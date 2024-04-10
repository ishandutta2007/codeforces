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
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

#define int ll

ll cur;
int n,reb[ar][ar];
bool use[arr];

void floyd(int x)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (reb[i][j]>reb[i][x]+reb[x][j])
                reb[i][j]=reb[i][x]+reb[x][j];
}

void add(int x)
{
    use[x]=true;
    floyd(x);
    floyd(x);
    cur=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (use[i]&&use[j])
                cur+=reb[i][j];
}

main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>reb[i][j];
    vector<ll> ans;
    vi zap;
    zap.resize(n);
    for (int i=0;i<n;i++)
        cin>>zap[i];
    reverse(all(zap));
    for (auto i:zap)
    {
        add(i);
        ans.pb(cur);
    }
    reverse(all(ans));
    for (auto i:ans)
        cout<<i<<" ";
}