#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (2020)
#define K (11050)

ll n,a[N],dif[K],r_dif[K],ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			dif[abs(a[i]-a[j])]++;
	for(int i=K-1;i>=0;i--)
		r_dif[i]=r_dif[i+1]+dif[i];
	for(int i=0;i<K;i++)
		for(int j=0;j<K;j++)
		{
			ll p=dif[i]*dif[j];
			ans+=p*r_dif[i+j+1];
		}
	ld res=(ld)ans/(ld)(n*(n-1)/2);
	res/=(ld)(n*(n-1)/2);
	res/=(ld)(n*(n-1)/2);
	cout<<fixed<<setprecision(12)<<res;
	return 0;
}