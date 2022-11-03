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

vector<int> vec[arr];
int cnt[arr];

void solve(int u, int len)
{
    cnt[len]++;
    for (auto i:vec[u])
        solve(i,len+1);
}

signed main()
{
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        vec[p].pb(i);
    }

    solve(1,0);
    int ans=0;

    for (int i =0;i<=n;i++)
        ans+=cnt[i]%2;

    cout<<ans;
}