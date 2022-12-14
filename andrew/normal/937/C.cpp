#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <iomanip>
#include <set>
#include <sstream>
#include <ctime>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)


typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=1000000;
const double pi=3.1415926535897932384626433832795;
using namespace std;
ll d,k,t;
long double sc;
bool check(double ce){
    ll de = ce / d;
    //cout << de * sc << endl;
    long double pp = de * sc;
    ce -= de * d;
    //cout << k - ce << endl;
    if(ce - k <= 1e-9)pp += ce;else {
         pp += k;
         ce -= k;
         pp += ce / 2.0;
    }
    //cout <<  pp << endl;
    if(t - pp <= 1e-9)return 1;
    return 0;
}
int main()
{
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);

    fast_io;
    srand(time(0));

 cin >> k >> d >> t;
 if(d < k){
    ll de = k / d;
    if(de * d != k)de ++;
    d = de * d;
 }
 sc = k + (d - k) / 2.0;
 //cout << sc << endl;
 double l = 0,r = 2 * 1e18;
 for(ll j = 0; j < 100;j++){
    long double c = (l + r) / 2;
    if(check(c))r = c;else l = c;
 }
 //cout << check(6) << endl;
 cout << fixed << setprecision(9) << l << endl;
    return 0;
}