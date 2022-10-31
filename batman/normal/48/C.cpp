// Zzz
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)1100)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=(b%2)?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,sum,a[N];
ld l=10,r=INF;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]*=10;
		l=max(l,(ld)(a[i]-a[i-1]+sum)/i);
		//cout<<a[i]-a[i-1]+sum<<"\n";
		r=min(r,(ld)(a[i]-a[i-1]+10+sum)/i);
		sum=a[i];
	}
	
	l*=n+1;r*=n+1;
//	cout<<l<<" "<<r<<"\n";
	if(floor(r)==r && ((ll)r)%10==0)r--;
	ll l2=l,r2=r;
	//cout<<l2<<" "<<r2<<"\n";
	if(l2/10!=r2/10)return cout<<"not unique",0;
	l2/=10;
	cout<<"unique\n"<<l2<<"\n";
	return 0;
}