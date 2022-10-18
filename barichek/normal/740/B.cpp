#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

main()
{
    int n,m;
    cin>>n>>m;
    vi a;
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    vi pref;
    pref.clear();
    for (auto i:a)
        pref.pb((pref.empty()?0:pref.back())+i);
    int ans=0;
    while (m--)
    {
        int l,r;
        cin>>l>>r;
        r--;
        l--;
        ans+=max(0ll,pref[r]-(l==0?0:pref[l-1]));
    }
    cout<<ans;
}