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

const int md=1e9+9;
const int arr=3e5+100;

int bpow(int a, int b)
{
    if (b==0)
        return(1);
    if (b%2)
        return(bpow(a,b-1)*a%md); else
        return(bpow(a*a%md,b/2));
}

signed main()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    n++;

    int s=0;
    string st;
    cin>>st;
    for (int i=0;i<k;i++)
    {
        int now=bpow(a,(n-1)-i)*bpow(b,i)%md;
        if (st[i]=='-')
        {
            now=((md-now)%md+md)%md;
        }

        s+=now;
        s%=md;
    }


    int d=bpow(b,k)*bpow(bpow(a,k),md-2)%md;

    if (d==1)
        cout<<s*(n/k)%md; else

    cout<<s*((bpow(d,n/k)-1+md)%md)%md*bpow((d-1+md)%md,md-2)%md;
}