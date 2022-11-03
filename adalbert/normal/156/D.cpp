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

const int arr=3e5+100;
const int base=31;

vector<int> vec[arr];
int cnt,use[arr];

void dfs(int u)
{
    use[u]=1;
    cnt++;
    for (auto j:vec[u])
        if (!use[j])
        dfs(j);
}

signed main()
{
    int n,m,k;
    cin>>n>>m>>k;

    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    int ans=1;
    int comp=0;
    for (int i=1;i<=n;i++)
    if (!use[i])
    {
        comp++;
        cnt=0;
        dfs(i);
        ans*=cnt;
        ans%=k;
    }
    int need=comp-1;
    for (int i=1;i<=need-1;i++)
    {
        ans*=n;
        ans%=k;
    }

    if (need==0)
        cout<<1%k; else

    cout<<ans;
}