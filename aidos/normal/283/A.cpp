#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (2e5 + 10)
using namespace std;
int n;
int a[MAXN], t;
ll d[MAXN], x, l;
ll sum = 0;
int sz = 1;
int main () {
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        if( t == 1){
            cin >> x >> l;
            d[x-1] += l;
            sum += x * l;
        }
        else if( t == 2){
            cin >> x;
            a[sz] = x;
            
            sz++;
            sum+=x;
        }
        else {
            if(sz > 1){
                sz--;
                d[sz-1] += d[sz];
                sum -= d[sz] + a[sz];
                d[sz] = 0;
            }
        }
        printf("%.12lf\n", sum * 1.0/sz);
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}