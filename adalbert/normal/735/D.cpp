#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
bool prime(ll n)
{
    for (int i=2;i<=sqrt(n);i++)
        if (n%i==0) return(0);
    return(1);

}
///-----------------------------------------------------------------------///
int  main()
{
    ll n;
    cin>>n;
    if (prime(n)) cout<<1; else if (n%2==0 ) cout<<2; else
        if (prime(n-2) ) cout<<2; else cout<<3;
}