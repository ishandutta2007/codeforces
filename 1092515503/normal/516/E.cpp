#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,n_m,m_n,d,b,g;
ll res;
vector<int>B[200100],G[200100];
map<int,int>mp;
void exgcd(int a,int b,int&x,int&y){if(!b)x=1,y=0;else exgcd(b,a%b,y,x),y-=a/b*x;}
int inv(int a,int mod){int x,y;exgcd(a,mod,x,y);return ((x%mod)+mod)%mod;}
vector<pair<int,int> >v;
ll func(int id){
ll ret=-1;
for(auto x:G[id]){
	if(mp.find(x)==mp.end())mp[x]=0x3f3f3f3f;
	mp[x]=min(mp[x],x);
}
for(auto x:B[id]){
	if(mp.find(x%m)==mp.end())mp[x%m]=0x3f3f3f3f;
	mp[x%m]=min(mp[x%m],x);
}
for(auto x:mp)v.emplace_back(1ll*x.first*n_m%m,x.second);
sort(v.begin(),v.end());
int sz=v.size();
for(int i=0;i<(sz<<1);i++)
	v[(i+1)%sz].second=min(1ll*v[(i+1)%sz].second,1ll*(v[(i+1)%sz].first-v[i%sz].first+m)%m*n+v[i%sz].second);
for(int i=0;i<sz;i++){
	if(binary_search(G[id].begin(),G[id].end(),1ll*v[i].first*n%m)&&(v[i].first+1)%m==v[(i+1)%sz].first)continue;
	ret=max(ret,1ll*(v[(i+1)%sz].first-v[i].first-1+m)%m*n+v[i].second);
}
v.clear(),mp.clear();
return ret;
}
ll calc(int id){
	if(B[id].empty()&&G[id].empty()){puts("-1");exit(0);}
	if(B[id].size()==n&&G[id].size()==m)return -1;
	ll ret=-1;
	sort(B[id].begin(),B[id].end());
	sort(G[id].begin(),G[id].end());
	ret=max(ret,func(id));
	swap(B[id],G[id]),swap(n,m),swap(n_m,m_n);
	ret=max(ret,func(id));
	swap(n,m),swap(n_m,m_n);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m),d=__gcd(n,m);
	if(d>200000){puts("-1");return 0;}
	n_m=inv(n,m),m_n=inv(m,n);
	n/=d,m/=d;
	scanf("%d",&b);for(int i=0,x;i<b;i++)scanf("%d",&x),B[x%d].push_back(x/d);
	scanf("%d",&g);for(int i=0,x;i<g;i++)scanf("%d",&x),G[x%d].push_back(x/d);
	for(int i=0;i<d;i++)res=max(res,calc(i)*d+i);
	printf("%lld\n",res);
	return 0;
}