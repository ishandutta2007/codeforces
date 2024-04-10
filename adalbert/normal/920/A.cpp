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
const int arr=2e5+100;

int a[arr];

void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    for (int i=1;i<=k;i++)
        cin>>a[i];
    int ans=0;

    for (int j=1;j<=n;j++)
    {
        int now=1e9;
        for (int i=1;i<=k;i++)
        now=min(now,abs(a[i]-j));
        ans=max(ans,now);
    }

    cout<<ans+1<<'\n';
}

signed main()
{
    int t;
    cin>>t;
    while (t--)
        solve();
}
/*
2
set physicsexercise 2
query physicsexercise
*/