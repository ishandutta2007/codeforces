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

int d[arr];

int find_(int u)
{
    return d[u]==u?u:d[u]=find_(d[u]);
}

void union_(int u,int v)
{
    u=find_(u);
    v=find_(v);
    if (u==v) return;
    if (rand()&1)
        swap(u,v);
    d[u]=v;
}

main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        d[i]=i;
    for (int i=1;i<=n;i++)
    {
        int u;
        cin>>u;
        union_(i,u);
    }
    for (int i=1;i<=n;i++)
        find_(i);
    set<int> ans;
    ans.clear();
    for (int i=1;i<=n;i++)
        ans.insert(d[i]);
    cout<<ans.size();
}