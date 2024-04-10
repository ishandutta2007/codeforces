#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (111)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,a[N],a_x,m,b[N],b_x,l,r;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>a_x;
	for(int i=0;i<n;i++)cin>>a[i];
	for(ll i=n-1,p=1;i>=0;i--,p*=a_x)
		l+=p*a[i];
	cin>>m>>b_x;
	for(int i=0;i<m;i++)cin>>b[i];
	for(ll i=m-1,p=1;i>=0;i--,p*=b_x)
		r+=p*b[i];	
	//cout<<l<<" "<<r;	
	if(l==r)
		cout<<"=";
	else if(l<r)
		cout<<"<";
	else
		cout<<">";		
    return 0;
}