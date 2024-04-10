#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100100],b[100100],lim,t[200100],res;
vector<int>u,v;
map<int,int>mp;
void ADD(int x){x=lim-x+1;while(x<=lim)t[x]++,x+=x&-x;}
int SUM(int x){x=lim-x+1;int ans=0;while(x>=1)ans+=t[x],x-=x&-x;return ans;}
int len(int l,int r){
	if(l>r)return 0;
	return upper_bound(u.begin(),u.end(),r)-lower_bound(u.begin(),u.end(),l);
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]),u.push_back(a[i]),u.push_back(b[i]);
	sort(u.begin(),u.end()),u.resize(unique(u.begin(),u.end())-u.begin()),lim=u.size();
	for(int i=0;i<lim;i++)v.push_back(i);
	for(int i=1;i<=n;i++)swap(v[lower_bound(u.begin(),u.end(),a[i])-u.begin()],v[lower_bound(u.begin(),u.end(),b[i])-u.begin()]);
	for(int i=0;i<lim;i++)mp[u[v[i]]]=i;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		if(u[it->second]<it->first)res+=it->first-u[it->second]-1-len(u[it->second]+1,it->first-1);
		if(u[it->second]>it->first)res+=u[it->second]-it->first-1-len(it->first+1,u[it->second]-1);
	}
	for(int i=0;i<lim;i++)res+=SUM(v[i]+1),ADD(v[i]+1);
	printf("%lld\n",res);
	return 0;
}