//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.8 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define N (201*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define PI ((ld)3.1415926535897932384626433832795028841971)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
#define HASH ((ll)1e16+7)
const ld sqr5=sqrt(5),p=(1+sqr5)/2;
ld tavan(ld a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ld fib(ll x){return (tavan(p,x)-tavan(1-p,x))/sqr5;}
ll gcd(ll a, ll b){ll tmp;while(b){tmp=b,b=a%b,a=tmp;}return b;}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll s(ll x){ll ans=0;while(x){ans+=x%10;x/=10;}return ans;}
ll a,b,c;
vector <ll> ans;
int Sa1378
{ 
    IB
    cin>>a>>b>>c;
    for(int i=1;i<=9*9;i++)
    {
    	ll ex=b*tavan(i,a)+c;
    	if(s(ex)==i && ex<1e9)
    		ans.PB(ex);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}