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
#pragma GCC optimize ("O2")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b)
        a%=b; else
        b%=a;
    return(a+b);
}

int get(int a, int b)
{
    return((a&(1<<b))!=0);
}

int get(int u)
{
    int res=0;
    while (u!=0)
    {
        res+=u%2;
        u/=2;
    }
    return(res);
}

int solve(vector<int> vec)
{
    if (vec.size()==1)
        return(vec[0]);
    vector<int> vv;
    for (int i=0;i+1<vec.size();i++)
        vv.pb(vec[i]^vec[i+1]);
    return(solve(vv));
}

vector<int> parse(vector<int> vec)
{
    vector<int> res;
    res.pb(vec[0]);
    for (int i=0;i+1<vec.size();i++)
        res.pb((vec[i]+vec[i+1])%2);
    res.pb(vec.back());
    return(res);
}

vector<int> good(vector<int> vec)
{
    vector<int> res;
    for (int i=0;i<vec.size();i++)
        if (vec[i])
        res.pb(i);
    return(res);
}

int a[5100];
int sum[5100][5100];

signed main()
{
    fast;
    int n;
    cin>>n;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    vector<int> vec;
    vec.pb(1);

    for (int i=1;i<=n;i++)
    {
        vector<int> go=good(vec);
        for (int j=1;j+i-1<=n;j++)
        {
            int res=0;
            for (auto l:go)
                sum[j][j+i-1]^=a[j+l];
        }
        vec=parse(vec);
    }

    for (int len=2;len<=n;len++)
        for (int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            sum[i][j]=max(sum[i][j],sum[i][j-1]);
            sum[i][j]=max(sum[i][j],sum[i+1][j]);
        }

    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sum[l][r]<<'\n';
    }
}