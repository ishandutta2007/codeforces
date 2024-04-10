#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)2e18)
#define K (14)

ll n,a[N],i;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=2)return cout<<0,0;
	while(a[i]==a[i+1] && i<n)i++;
	if(i>=n-1)return cout<<0,0;
	bool p=(a[i]<a[i+1]);
	for(int j=i+2;j<n;j++)
		if((!p && a[j-1]<a[j]) || (p && a[j-1]>a[j]))return cout<<"3\n"<<i+1<<" "<<j<<" "<<j+1,0;
	cout<<0;
    return 0;
}