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

int n,h;

int getsum(int l, int r)
{
    return((r+l)*(r-l+1)/2);
}

int get(int u)
{
    if (u<=h)
    {
        return(getsum(1,u));
    } else
    {
        int cnt=h+u;
        int z=cnt/2;
        if (cnt%2==0)
        {
            return(getsum(1,z)+getsum(h,z)-z);
        } else
        {
            return(getsum(1,z)+getsum(h,z));
        }
    }
}

signed main()
{
    cin>>n>>h;

    int l=1;
    int r=2e9;

    while (r-l>1)
    {
        int d=(l+r)/2;

        if (get(d)>=n)
            r=d; else l=d;
    }

    if (get(l)>=n)
        cout<<l; else
        cout<<r;
}