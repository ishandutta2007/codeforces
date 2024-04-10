#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cout << #x << " is " << x << endl;
#define ST(a,b) cout<<fixed<<setprecision((b))<<((ld)a)<<"\n";
#define sin(a) sin(a*PI/180)
#define tan(a) tan(a*PI/180)
#define cot(a) cot(a*PI/180)
#define cos(a) cos(a*PI/180)
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
const ld PI=((ld)2*asin(1));
const ll INF=((ll)1e14);
const ll MOD=((ll)1e9+7);
const ll BIG_HSH=((ll)9999999900000001);
const ll SML_HSH=((ll)100030001);
const ll N =301*1000;
inline ll tavan(ll a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline ld tavan(ld a,ll b){return (b)?(tavan((a)*(a),(b)>>1) * ((b) & 1?(a):1)):1;}
inline ll gcd(ll a,ll b){while(b ^= a ^= b ^= a = a % b);return a;}
template <class T>  inline void smx(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smn(T &x,T y){ x = min((x), (y));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,d,sum,ans;
pair <ll,ll> a[101*1000];
int Sa1378
{
    IB
    cin>>n>>d;
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    for(int i=0,j=0;i<n;i++)
    {
    	sum+=a[i].second;
    	while(a[i].first-d>=a[j].first)
    		sum-=a[j++].second;
    	ans=max(ans,sum);	
	}
	cout<<ans;
    return 0;
}