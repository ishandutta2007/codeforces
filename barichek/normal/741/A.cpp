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
int cnt[arr];
bool use[arr];

int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}

int dfs(int now)
{
    int res=1;
    use[now]=true;
    for (auto i:reb[now])
        if (!use[i])
            res+=dfs(i);
    return res;
}

main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int u;
        cin>>u;
        cnt[u]++;
        reb[i].pb(u);
    }
    for (int i=1;i<=n;i++)
        if (cnt[i]!=1)
            return cout<<-1, 0;
    int ans=1;
    for (int i=1;i<=n;i++)
        if (!use[i])
        {
            int cur=dfs(i);
            if (cur%2==0)
                ans=lcm(ans,cur/2);
            else
                ans=lcm(ans,cur);
        }
    cout<<ans;
}