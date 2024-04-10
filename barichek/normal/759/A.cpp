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

vi reb[arr];
bool use[arr];

void dfs(int now)
{
    use[now]=true;
    for (auto wh:reb[now])
        if (!use[wh])
            dfs(wh);
}

main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int u;
        cin>>u;
        reb[i].pb(u);
        reb[u].pb(i);
    }
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        sum+=a;
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (!use[i])
            cnt++,
            dfs(i);
    if (cnt==1)
        cnt=0;
    if (n%2==0&&sum%2==0) cnt++;
    if (n%2==1&&sum%2==0) cnt++;
    cout<<cnt;
}