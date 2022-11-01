#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (301*1000)
#define INF ((ll)1e9)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll a,b,c,d,e,f,g,h,i,j,ans,h1,h2;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	cin>>h1>>h2;
	ans=h1*100-h2*50;
	ans+=max((ll)150,500-2*a-50*f);
	ans+=max((ll)300,1000-4*b-50*g);
	ans+=max((ll)450,1500-6*c-50*h);
	ans+=max((ll)600,2000-8*d-50*i);
	ans+=max((ll)750,2500-10*e-50*j);
	cout<<ans;
    return 0;
}