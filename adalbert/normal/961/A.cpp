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
const int md=1e9+7;
const int arr=7e5;

int cnt[10000];

signed main()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    while (m--)
    {
        int a;
        cin>>a;
        cnt[a]++;

        bool ch=1;
        for (int i=1;i<=n;i++)
            if (cnt[i]==0)
            ch=0;
        if (ch)
        {
            ans++;
            for (int i=1;i<=n;i++)
            cnt[i]--;
        }
    }

    cout<<ans;
}
/*1
2 0
*/