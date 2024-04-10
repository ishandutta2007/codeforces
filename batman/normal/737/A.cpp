#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,k,s,t,c[N],v[N],g[N],ex[N],prt[N];
ll mini=INF,maxi=0,ans=INF;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>s>>t;
    for(int i=0;i<n;i++)
    	cin>>c[i]>>v[i];
    for(int i=1;i<=k;i++)cin>>g[i];
    sort(g+1,g+k+1);
	for(int i=1;i<=k;i++)
	{
		ll dis=g[i]-g[i-1];
		mini=min(dis,mini);
		maxi=max(dis,maxi);
		ex[i-1]=dis;
	}
	ll dis=s-g[k];
    mini=min(dis,mini);
	maxi=max(dis,maxi);
	ex[k]=dis;
	sort(ex,ex+k+1);
	for(int i=0;i<=k;i++)prt[i]=((i)?prt[i-1]:0)+ex[i];
    for(int i=0;i<n;i++)
    {
    	if(v[i]<maxi)continue;
    	ll id=(upper_bound(ex,ex+k+1,v[i]/2)-ex)-1;
    	ll res=prt[id]+(3*(s-prt[id])-(k-id)*v[i]);
    	if(id==-1)res=3*s-(k+1)*v[i];
    	if(res<=t)ans=min(ans,c[i]);
	}
    if(ans==INF)cout<<-1;
    else cout<<ans;
	return 0;
}