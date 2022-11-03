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
#define get rgjeoig
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int cnt[1000100];

signed main()
{
    int n,k;
    cin>>n>>k;
    if (k>1e6)
    {
        cout<<"No";
    } else
    {
        for (int i=1;i<=k;i++)
        {
            if (cnt[n%i])
            {
                cout<<"No";
                return(0);
            }
            cnt[n%i]++;
        }

        cout<<"Yes";
    }
}
/*
*/