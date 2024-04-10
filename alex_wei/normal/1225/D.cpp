#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[100005],cnt[100005],ans,pd[100005];
vector <ll> g;
void zero()
{
	for(int i=0;i<g.size();i++)
		pd[g[i]]=0;
	while(g.size())g.pop_back();
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=n;i++){
		ll nd=1,tp=a[i];
		for(int j=2;j<=sqrt(tp);j++)
			if(tp%j==0){
				g.push_back(j);
				while(tp%j==0)pd[j]++,tp/=j;
			}
		if(tp>1)pd[tp]++,g.push_back(tp);
		ll nw=1;
		for(int j=0;j<g.size();j++){
			while(pd[g[j]]%k!=0){
				nw*=g[j],pd[g[j]]++;
				if(nw>1e5)break;
			}
		}
		if(nw>1e5){zero();continue;}
		for(ll j=1;;j++){
			ll ned=nw;
			for(int l=1;l<=k;l++){ned*=j;if(ned>1e5)break;}
			if(ned>1e5)break;
//			if(cnt[ned])cout<<ned<<" "<<a[i]<<endl;
			if(ned!=a[i])ans+=cnt[ned];
			else ans+=max(0ll,cnt[ned]-1);
		}
		zero();
	}
	cout<<ans/2<<endl;
    return 0;
}