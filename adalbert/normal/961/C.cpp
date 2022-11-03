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

int cnt[10];

signed main()
{
    int n;

    cin>>n;

    for (int i=1;i<=4;i++)
    {
        for (int j=1;j<=n;j++)
        {
            string st;
            cin>>st;
            for (int l=1;l<=n;l++)
            {
                int a;
                a=st[l-1]-'0';
                cnt[i]+=(j%2)^(l%2)^a;
            }
        }

    }


    sort(cnt+1,cnt+5);

    int ans=1e9;
    do
    {
        ans=min(ans,cnt[1]+cnt[2]+n*n-cnt[3]+n*n-cnt[4]);
    } while (next_permutation(cnt+1,cnt+5));

    cout<<ans;
}
/*1
2 0
*/