#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200100],t[200100],lim;
void add(int x,int y){while(x<=lim)t[x]=max(t[x],y),x+=x&-x;}
int ask(int x){int ret=0;while(x)ret=max(ret,t[x]),x-=x&-x;return ret;}
pair<ll,ll>p[200100];
vector<ll>v;
bool che(int ip){
	v.clear(),memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++)p[i]=make_pair(1ll*ip*i-a[i],1ll*ip*i+a[i]),v.push_back(p[i].second);
	sort(v.begin(),v.end()),v.resize(lim=unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)p[i].second=lower_bound(v.begin(),v.end(),p[i].second)-v.begin()+1;
	sort(p+1,p+n+1);
	int mx=0;
	for(int i=1,tmp;i<=n;i++)tmp=ask(p[i].second)+1,mx=max(mx,tmp),add(p[i].second,tmp);
	return mx+m>=n;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0,r=2e9;
	while(l<r){
		int mid=(0ll+l+r)>>1;
		if(che(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}