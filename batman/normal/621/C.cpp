#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,p,l[N],r[N];
ld ans;


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>p;
	for(int i=0;i<n;i++)cin>>l[i]>>r[i];
	for(int i=0;i<n;i++)
	{
		ll ex1=r[i]/p;ex1-=(l[i]-1)/p;
		ll ex2=r[(i+1)%n]/p;ex2-=(l[(i+1)%n]-1)/p;
		ll ex3=ex1*(r[(i+1)%n]-l[(i+1)%n]+1)+ex2*(r[i]-l[i]+1)-ex1*ex2;
		ans+=(ld)ex3/((r[(i+1)%n]-l[(i+1)%n]+1)*(r[i]-l[i]+1));
	}
	cout<<fixed<<setprecision(12)<<ans*(ld)2000;
    return 0;
}