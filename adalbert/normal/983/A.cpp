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
#pragma GCC optimize ("O2")
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b)
        a%=b; else
        b%=a;
    return(a+b);
}

signed main()
{
    fast;
    int n;
    cin>>n;
    while (n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int k=nsd(a,b);
        b/=k;

        while (1)
        {
            int ns=__gcd(b,c);
            if (ns==1)
                break;
            while (b%ns==0)
                b/=ns;

        }
        if (b==1)
            cout<<"Finite\n"; else
            cout<<"Infinite\n";
    }
}