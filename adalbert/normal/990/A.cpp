#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1039;


signed main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int n1=n/m*m;
    int n2=n1+m;

    cout<<min(abs(n-n1)*b,abs(n-n2)*a);
}
/*
*/