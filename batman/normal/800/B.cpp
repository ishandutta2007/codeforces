#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=201*1000;

ll n,x[N],y[N];
ld ans=1e18;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	for(int i=0;i<n;i++)
	{
		ll j=(i+1)%n,k=(i+2)%n;
		if(x[i]==x[k])
		{
			ans=min(ans,abs(((ld)x[j]-x[k])/(ld)2));
			continue;
		}
		ld m=(ld)((ld)y[i]-y[k])/(x[i]-x[k]);
		ld a=m,b=-1,c=-m*x[i]+y[i];
		ld ex=abs(a*x[j]+b*y[j]+c);
		ex/=(ld)sqrt((ld)a*a+b*b);
		ans=min(ans,ex/(ld)2);	
	}
	cout<<fixed<<setprecision(14)<<ans<<"\n";
	return 0;
}