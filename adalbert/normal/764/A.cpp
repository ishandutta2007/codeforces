#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define int ll
#define y1 humiuyn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int nsd(int a, int b)
{
    while (a!=0 && b!=0)
        if (a>b) a%=b; else b%=a;
    return(a+b);
}
int nsk(int a, int b)
{
    return(a*b/nsd(a,b));
}
signed main()
{
    int n,m,z;
    cin>>n>>m>>z;
    cout<<z/nsk(n,m);
}