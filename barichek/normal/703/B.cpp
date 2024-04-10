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

ll a[arr];
bool ok[arr];

int main()
{
    int n,k;
    cin>>n>>k;
    ll suma=0;
    for (int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        suma=suma+a[i];
    }
    ll ans=0;
    for (int i=0;i<n;i++)
        if (i<n-1) ans=ans+1ll*a[i]*a[i+1];
        else ans=ans+1ll*a[i]*a[0];
    //cout<<ans<<" !!!\n";
    vi id;
    ll sumid=0;
    for (int i=0;i<k;i++)
    {
        int zn;
        cin>>zn;
        zn--;
        id.pb(zn);
        sumid=sumid+a[zn];
        ok[zn]=true;
        ans=ans+(suma-(zn>0?a[zn-1]:a[n-1])-(zn<n-1?a[zn+1]:a[0])-a[zn])*a[zn];
        //cout<<"debug== "<<(suma-(zn>0?a[zn-1]:a[n-1])-(zn<n-1?a[zn+1]:a[0])-a[zn])*a[zn]<<"\n";
        //cout<<ans<<" !!\n";
    }
    //cout<<ans<<"!\n";
    for (auto i:id)
    {
        ans=ans-(sumid-a[i]-(ok[(i>0?i-1:n-1)]*a[(i>0?i-1:n-1)])-(ok[(i<n-1?i+1:0)]*a[(i<n-1?i+1:0)]))*a[i];
        sumid=sumid-a[i];
    }
    //cout<<ans<<"!\n";
    ll ansmin=0;
    for (auto i:id)
    {
        if (ok[(i>0?i-1:n-1)]) ansmin=ansmin+a[i]*a[(i>0?i-1:n-1)];
        if (ok[(i<n-1?i+1:0)]) ansmin=ansmin+a[i]*a[(i<n-1?i+1:0)];
    }
    //cout<<ansmin<<" !\n";
    cout<<ans-ansmin/2;
}