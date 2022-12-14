#include <bits/stdc++.h>

#define sqr(a) (a)*(a)
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))

typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=1000000;

using namespace std;
ll a[MAXN],n,k,i,ans;
ll binpow (ll a, ll n)
{
    ll res=1;
    n=n;
    while (n)
    {
        if (n&1) res*=a;
        a*=a;
        n >>= 1;
    }
    return res;
}

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    fast_io;
    srand(time(0));
    ll sum,b,d,s,mx,alt=0;
    // b - zavtrak
    // d - obed
    // s - ugin
    cin >> b >> d >> s;
    mx=max(b,max(d,s));
    if (b==d && s==d && s==b)
    {
        cout << 0;
        return 0;
    }
    mx--;
    if (b-mx < 0) alt+=-(b-mx);
    if (d-mx < 0) alt+=-(d-mx);
    if (s-mx < 0) alt+=-(s-mx);
    cout<< alt << endl;



}