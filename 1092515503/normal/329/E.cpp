#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
pair<int,int>p[100100],q[100100];
ll solve(){
	sort(p+1,p+n+1);
	ll res=0;
	for(int i=1;i<=(n>>1);i++)q[i]=make_pair(p[i].second,1),res-=p[i].first<<1;
	for(int i=(n>>1)+1;i<=n;i++)q[i]=make_pair(p[i].second,-1),res+=p[i].first<<1;
	if(n&1)q[m]=make_pair(p[m].second,0),res-=p[m].first<<1;
	sort(q+1,q+n+1);
	if(n&1){
		bool ok=false;
		if(q[m].second)ok=true;
		else{
			ok=true;
			for(int i=2;i<m;i++)if(q[i].second!=q[1].second)ok=false;
		}
		for(int i=1;i<m;i++)res-=q[i].first<<1;
		for(int i=n;i>m;i--)res+=q[i].first<<1;
		if(!ok)res-=min(q[m+1].first-q[m].first,q[m].first-q[m-1].first)<<1;
		return res;
	}
	bool ok=false;
	for(int i=2;i<=(n>>1);i++)if(q[i].second!=q[1].second)ok=true;
	for(int i=1;i<=(n>>1)-ok;i++)res-=q[i].first<<1;
	for(int i=(n>>1)+1+ok;i<=n;i++)res+=q[i].first<<1;
	return res;
}
ll res;
int main(){
	scanf("%d",&n);
	if(n&1)m=(n+1)>>1;
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second);
	res=solve();
	for(int i=1;i<=n;i++)swap(p[i].first,p[i].second);
	res=max(res,solve());
	printf("%lld\n",res);
	return 0;
}