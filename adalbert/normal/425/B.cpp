#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int a[200][200];
int dp[200][20][2];
int n,m,k;


int get(int u, int st)
{
    return((u&(1<<st))!=0);
}

void stupid()
{
    int ans=1e9;
    for (int mask=0;mask<(1<<m);mask++)
    {
        int now=0;
        for (int j=1;j<=m;j++)
            if (get(mask,j-1))
                a[1][j]^=1,now++;

        for (int i=1;i<=n;i++)
        {
            int pl=0;
            for (int j=1;j<=m;j++)
            if (a[i][j]!=a[1][j])
                pl++;
            now+=min(pl,m-pl);
        }


        for (int j=1;j<=m;j++)
            if (get(mask,j-1))
                a[1][j]^=1;
        ans=min(ans,now);
    }

    if (ans>k)
        cout<<-1; else
        cout<<ans;
    exit(0);
}


signed main()
{
    cin>>n>>m>>k;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>a[i][j];

    if (m<=2*k)
        stupid();

    set<int> setik;
    for (int i=1;i<=n;i++)
    {
        int now=0;
        for (int j=1;j<=m;j++)
            if (a[i][j]!=a[1][j])
            now++;
        if (now>k)
        {
            for (int j=1;j<=m;j++)
                a[i][j]^=1;
        }

        for (int j=1;j<=m;j++)
            if (a[i][j]!=a[1][j])
                setik.insert(j);
    }

    vector<int> vec;
    for (auto i:setik)
        vec.pb(i);
    if (vec.size()>k)
    {
        cout<<-1;
        return(0);
    }

    int ans=1e9;
    for (int mask=0;mask<(1<<vec.size());mask++)
    {
        int now=0;
        for (int j=0;j<vec.size();j++)
            if (get(mask,j))
                a[1][vec[j]]^=1,now++;

        for (int i=1;i<=n;i++)
        {
            int pl=0;
            for (int j=1;j<=m;j++)
            if (a[i][j]!=a[1][j])
                pl++;
            now+=min(pl,m-pl);
        }

        for (int j=0;j<vec.size();j++)
            if (get(mask,j))
                a[1][vec[j]]^=1;
        ans=min(ans,now);
    }

    if (ans>k)
        cout<<-1; else
        cout<<ans;
}
/*

*/