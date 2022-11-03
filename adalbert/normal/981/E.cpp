#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5;

int dp[arr],ans[arr];

int n,k;

void add(int u)
{
    for (int i=n;i>=u;i--)
    {
        dp[i]+=dp[i-u];
        dp[i]%=md;
    }
}

void dell(int u)
{
    for (int i=u;i<=n;i++)
    {
        dp[i]-=dp[i-u];
        dp[i]+=md;
        dp[i]%=md;
    }
}

vector<pair<int,int> > vec[arr];

signed main()
{
    dp[0]=1;
    cin>>n>>k;

    while (k--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        vec[l].pb({1,x});
        vec[r+1].pb({-1,x});
    }

    for (int i=1;i<=n;i++)
    {
        for (auto j:vec[i])
            if (j.fir==1)
            add(j.sec); else
            dell(j.sec);
        for (int i=1;i<=n;i++)
            if (dp[i])
            ans[i]=1;
    }

    vector<int> res;

    for (int i=1;i<=n;i++)
        if (ans[i])
        res.pb(i);

    cout<<res.size()<<'\n';
    for (auto i:res)
        cout<<i<<' ';
}