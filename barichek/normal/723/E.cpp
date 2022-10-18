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
const ld eps=1e-10;

///---program start---///

int n,m;
int step[ar];
bool use[ar];
int reb[ar][ar];
bool is_fake[ar][ar];
vi bad;
vector<pii> ans;

void dfs(int now,int& res)
{
    if (step[now]&1)
        bad.pb(now);
    else
        res++;
    use[now]=true;
    for (int i=1;i<=n;i++)
        if (!use[i]&&reb[now][i]>0)
            dfs(i,res);
}

void dfs_euler(int now)
{
    for (int i=1;i<=n;i++)
        if (reb[now][i]>0)
        {
            ans.pb(mp(now,i));
            reb[now][i]--;
            reb[i][now]--;
            dfs_euler(i);
        }
}

main()
{
    int test;
    cin>>test;
    while (test--)
    {
        /// memset
        for (int i=0;i<ar;i++)
            for (int j=0;j<ar;j++)
                reb[i][j]=0;
        for (int i=0;i<ar;i++)
            step[i]=0,
            use[i]=false;
        for (int i=0;i<ar;i++)
            for (int j=0;j<ar;j++)
                is_fake[i][j]=false;

        cin>>n>>m;
        while (m--)
        {
            int u,v;
            cin>>u>>v;
            reb[u][v]++;
            reb[v][u]++;
            step[u]++;
            step[v]++;
        }
        int res=0;
        ans.clear();
        for (int i=1;i<=n;i++)
            if (step[i]!=0&&!use[i])
            {
                bad.clear();
                dfs(i,res);
                for (int j=0;j<bad.size();j+=2)
                {
                    int u=bad[j];
                    int v=bad[j+1];
                    reb[u][v]++;
                    reb[v][u]++;
                    is_fake[u][v]=true;
                    is_fake[v][u]=true;
                }
                dfs_euler(i);
            }
        vector<pii> dop=ans;
        ans.clear();
        for (auto i:dop)
        {
            if (is_fake[i.fir][i.sec])
                is_fake[i.fir][i.sec]=false,
                is_fake[i.sec][i.fir]=false;
            else
                ans.pb(i);
        }
        for (int i=1;i<=n;i++)
            res+=(step[i]==0);
        cout<<res<<"\n";
        for (auto i:ans)
            cout<<i.fir<<" "<<i.sec<<"\n";
    }
}