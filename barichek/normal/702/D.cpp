#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

int main()
{
    ll d,k,a,b,t;
    cin>>d>>k>>a>>b>>t;
    ll how_much=d/k;
    ll ans=0;
    if (d<=k) return cout<<d*a<<"\n", 0;
    if (t+a*k<k*b)
        ans+=how_much*k*a+(how_much-1)*t;
    else
        ans+=a*k+(how_much-1)*k*b;
    if (t+a*(d%k)<(d%k)*b)
        ans+=t+(d%k)*a;
    else
        ans+=(d%k)*b;
    cout<<ans;
}