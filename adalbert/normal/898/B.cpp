#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=500000;


signed main()
{
    int n,a,b;
    cin>>n>>a>>b;
    for (int i=0;i<=n/a;i++)
        if ((n-a*i)%b==0)
    {
        cout<<"YES"<<'\n';
        cout<<i<<' '<<(n-a*i)/b<<'\n';
        exit(0);
    }

    cout<<"NO";
}