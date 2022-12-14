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
ll l,r ,x ,i,j;
int main()
{
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);

    fast_io;
    srand(time(0));
    cin >> l >> r;
    x = r;
    while(l < x){
        bool fl =0;
        for(j = 2; j * j <= x && j <= l; j++)if(x % j == 0){
            fl = 1;
            break;
        }
        if(!fl){
            cout << x << endl;
            exit(0);
        }
        x--;
    }
    cout << -1 << endl;
    return 0;
}