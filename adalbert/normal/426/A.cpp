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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;

int a[10000];

signed main()
{
    int n,s;
    cin>>n>>s;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int sum=0;
    int mx=0;
    for (int i=1;i<=n;i++)
    {
        mx=max(mx,a[i]);
        sum+=a[i];
    }

    if (s>=sum-mx)
        cout<<"YES"; else
        cout<<"NO";
}