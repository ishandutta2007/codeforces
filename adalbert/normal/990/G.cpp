#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=1e6+100;
const int md=1e9+7;
const int base=1039;

int mx=2e5;
ll cnt=0;
vector<int> vec[300000];
vector<int> todo[300000];
bool ok[300000],use[300000];

void dfs(int &u)
{
    cnt++;
    use[u]=1;

    for (auto &i:vec[u])
        if (ok[i] && !use[i])
        dfs(i);
}

ll a[300000],ans[300000];

signed main()
{
    fast;
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        for (int j=1;j*j<=a[i];j++)
            if (a[i]%j==0)
        {
            todo[j].pb(i);
            if (a[i]/j!=j)
                todo[a[i]/j].pb(i);
        }
    }


    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].pb(y);
        vec[y].pb(x);
    }

    for (int i=1;i<=mx;i++)
    {
        for (auto j:todo[i])
            ok[j]=1;

        for (auto j:todo[i])
            if (!use[j])
            {
                cnt=0;
                dfs(j);
                ans[i]+=cnt*(cnt+1)/2;
            }

        for (auto j:todo[i])
        {
            ok[j]=0;
            use[j]=0;
        }
    }

    vector<pair<int,int> > dell;

    for (int i=1;i<=mx;i++)
    {
        int now=i;
        int cnt=0;
        bool ch=1;

        for (int j=2;j*j<=now;j++)
        {
            if (now%j==0)
            {
                cnt++;
                if (now%(j*j)==0)
                    ch=0;
                now/=j;
            }
        }

        if (now!=1)
            cnt++;

        if (ch)
        {
            if (cnt%2==0)
            dell.pb({1,i}); else
            dell.pb({-1,i});
        }
    }


    for (int i=1;i<=mx;i++)
    {
        ll now=0;
        for (auto j:dell)
        {
            if (i*j.sec>mx)
                break;
            now+=j.fir*ans[j.sec*i];
        }

        if (now!=0)
            cout<<i<<' '<<now<<'\n';
    }
}
/*
*/