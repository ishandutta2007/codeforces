#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define y eth
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int md=1e9+7;
const int base=3;
int n,k;

bool check(int u)
{
    if (u<=0 || u>n)
        return(0);
    int uu=k-u;

    if (uu<=u || uu>n)
        return(0);
    return(1);
}

signed main()
{
    cin>>n>>k;


    int mncost=k/2;
    if (k%2==0)
        mncost--;

    if (!check(mncost))
    {
        cout<<0;
        return(0);
    }

    int last=mncost;

    while (check(last-1e7))
        last-=1e7;

    while (check(last-1))
        last--;

    cout<<mncost-last+1;
}