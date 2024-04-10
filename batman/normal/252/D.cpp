#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,k,a[N],b[2][N],s[N],maxi=1;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)b[0][i]=i;
	for(int i=1;i<=n;i++)
	{
		ll num=1,x=a[i];
		while(x!=i)
			num++,x=a[x];
		maxi=maxi*num/__gcd(maxi,num);
	}
	bool mark=1;
	for(int j=1;j<=n;j++)
		if(b[0][j]!=s[j])
			mark=0;
	if(mark)
		return cout<<((k)?"NO":"YES"),0;	
	for(int i=0;i<min(maxi,k+1);i++)
	{
		mark=1;
		for(int j=1;j<=n;j++)
			if(b[(i&1)][j]!=s[j])
				mark=0;
		if(mark)
		{
			if((maxi>2 && ((k>=i && k%2==i%2) || (k>=maxi-i && k%2==(maxi-i)%2))) || (maxi<=2 && k==1))return cout<<"YES",0;
			return cout<<"NO",0;
		}
		for(int j=1;j<=n;j++)b[!(i&1)][a[j]]=b[(i&1)][j];
		//for(int j=1;j<=n;j++)cout<<b[!(i&1)][j]<<" ";
		//cout<<"\n";
	}
	for(int i=1;i<=n;i++)b[0][i]=i;
	for(int i=0;i<min(maxi,k+1);i++)
	{
		mark=1;
		for(int j=1;j<=n;j++)
			if(b[(i&1)][j]!=s[j])
				mark=0;
		if(mark)
		{
			if((maxi>2 && ((k>=i && k%2==i%2) || (k>=maxi-i && k%2==(maxi-i)%2))) || (maxi<=2 && k==1))return cout<<"YES",0;
			return cout<<"NO",0;
		}
		for(int j=1;j<=n;j++)b[!(i&1)][j]=b[(i&1)][a[j]];
		//for(int j=1;j<=n;j++)cout<<b[!(i&1)][j]<<" ";
		//cout<<"\n";
	}
	cout<<"NO";
    return 0;
}