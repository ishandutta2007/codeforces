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
    map<ll,ll> cnt;
    vector<ll> step2;
    for (int i=0;i<35;i++)
        step2.pb(i?*step2.rbegin()*2:1);
    int n;
    cin>>n;
    ll ans=0;
    for (int i=0;i<n;i++)
    {
        ll now;
        scanf("%I64d",&now);
        for (auto j:step2)
            ans+=cnt[j-now];
        cnt[now]++;
    }
    cout<<ans;
}