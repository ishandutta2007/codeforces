#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef vector <pii> vii;
const ld pi = acos(-1);
const int arr = 4*1e5+100;
const ll md = 1e9+7;
const ll base=31;
const int AaA = 'a'-'A';
ld eps=1e-7;

#define int ll

int ans[arr];
vector<int> vec[arr];

void solve(int u, int type, int pred)
{
    ans[u]=type;
    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i]!=pred)
    {
        solve(vec[u][i],!type,u);
    }
}

signed main()
{
    int n;
    cin>>n;
    int cnt0=0,cnt1=0;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
        vec[v].pb(u);
    }

    solve(1,0,0);

    for (int i=1;i<=n;i++)
        if (ans[i]==0) cnt0++; else cnt1++;
    cout<<cnt0*cnt1-n+1;

}