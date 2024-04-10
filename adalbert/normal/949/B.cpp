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
int n;

int gt(int u)
{
    //cout<<u<<'\n';
    if (u%2)
        return(u/2+1); else
        return (gt(u+(2*n-u)/2));
}

signed main()
{
    int q;
    cin>>n>>q;
    while (q--)
    {
        int a;
        cin>>a;
        cout<<gt(a)<<'\n';
    }
}