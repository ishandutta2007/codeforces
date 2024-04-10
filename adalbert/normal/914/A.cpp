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
const int arr=1e6+100;
int md=998244353;

signed main()
{
    int n;
    cin>>n;
    int mx=-1e9;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        int c=sqrt(abs(a));
        if (c*c!=a && (c+1)*(c+1)!=a)
            mx=max(mx,a);
            
    }
    cout<<mx<<'\n';
}