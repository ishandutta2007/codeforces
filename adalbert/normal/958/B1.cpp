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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef long double ld;

int cnt[20000];

signed main()
{
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }

    int ans=0;
    for (int i=1;i<=n;i++)
        if (cnt[i]==1)
        ans++;

    cout<<ans;
}
/*
*/