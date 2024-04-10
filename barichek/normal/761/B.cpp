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

bool ok(vi a,vi b)
{
    if (a==b) return true;
    for (int i=0;i<1000;i++)
    {
        int cur=a.back();
        a.pop_back();
        a.insert(a.begin(),cur);
        if (a==b) return true;
    }
    return false;
}

main()
{
    int n,l;
    cin>>n>>l;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    vi b;
    b.clear();
    b.resize(n);
    for (auto &i:b)
        cin>>i;
    vi dop;
    dop=a;
    a.clear();
    for (int i=1;i<dop.size();i++)
        a.pb(dop[i]-dop[i-1]);
    a.pb(dop[0]-dop[n-1]+l);
    dop=b;
    b.clear();
    for (int i=1;i<dop.size();i++)
        b.pb(dop[i]-dop[i-1]);
    b.pb(dop[0]-dop[n-1]+l);
    cout<<(ok(a,b)?"YES":"NO");
}