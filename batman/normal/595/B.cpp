#include <bits/stdc++.h>
using namespace std;
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define N (101*1000)
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
#define MOD ((ll)1e9+7)

ll n,k,ans=1,a[N],b;

int main()
{
	IB
	cin>>n>>k;
	ll xx=tavan((ll)10,k);
	for(int i=0;i<n/k;i++)
		cin>>a[i];
	for(int i=0;i<n/k;i++)
	{
		cin>>b;
		ll ex=((xx-1)/a[i])+1,ex2;
		if(b)
			ex2=((b+1)*xx/10-1)/a[i]-(b*xx/10-1)/a[i];
		else	
			ex2=((b+1)*xx/10-1)/a[i]+1;
		//cout<<ex2<<endl;
		//cout<<ex<<endl;
		ans*=(ex-ex2);
		ans%=MOD;	
	}	
	cout<<ans;
    return 0;
}