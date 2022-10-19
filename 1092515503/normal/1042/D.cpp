#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum[200100],res,lim;
vector<int>v;
int t[400100];
void ADD(int x){x=lim-x+1;while(x<=lim)t[x]++,x+=x&-x;}
int SUM(int x){x=lim-x+1;int ans=0;while(x)ans+=t[x],x-=x&-x;return ans;}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&sum[i]),sum[i]+=sum[i-1];
	for(int i=0;i<=n;i++)v.push_back(sum[i]);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin()),lim=v.size();
	for(int i=0;i<=n;i++){
		res+=SUM(upper_bound(v.begin(),v.end(),sum[i]-m)-v.begin()+1);
		ADD(lower_bound(v.begin(),v.end(),sum[i])-v.begin()+1);
	}
	printf("%lld\n",res);
	return 0;
}