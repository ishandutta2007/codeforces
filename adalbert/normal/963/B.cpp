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
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int md=1e9+9;
const int arr=3e5+100;

bool dp[arr][2];
vector<int> vec[arr];

void solve(int u)
{
    for (auto i:vec[u])
        solve(i);

    int cnt0=0,cnt1=0,cnt2=0;

    for (auto i:vec[u])
        if (dp[i][0] && dp[i][1])
            cnt2++; else
        if (dp[i][0])
            cnt0++; else
            cnt1++;

    if (cnt2!=0)
    {
        dp[u][1]=1;
        dp[u][0]=1;
    } else
    {
        if (cnt0%2)
        {
            dp[u][1]=1;
            dp[u][0]=0;
        } else
        {
            dp[u][1]=0;
            dp[u][0]=1;
        }
    }
}

void vuvod(int u, int type)
{

    vector<int> vec0,vec1,vec2;
    for (auto i:vec[u])
        if (dp[i][0] && dp[i][1])
            vec2.pb(i); else
            if (dp[i][0])
            vec0.pb(i); else
            vec1.pb(i);
    for (auto i:vec1)
        vuvod(i,1);

    if ((type+vec0.size())%2)
    {

        for (int i=1;i<vec2.size();i++)
            vuvod(vec2[i],1);
        cout<<u<<'\n';
        vuvod(vec2[0],0);
        for (auto i:vec0)
            vuvod(i,0);
    } else
    {

        for (int i=0;i<vec2.size();i++)
            vuvod(vec2[i],1);
        cout<<u<<'\n';
        for (auto i:vec0)
            vuvod(i,0);
    }


}

signed main()
{
    int n;
    cin>>n;

    int root=1;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if (a==0)
            root=i; else
        vec[a].pb(i);
    }

    solve(root);

    if (dp[root][0])
    {
        cout<<"YES\n";
        vuvod(root,0);
    } else
    cout<<"NO";
}