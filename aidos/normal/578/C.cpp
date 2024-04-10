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
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;



int n;
int a[200200];
double b[200200];
double g(double x){
    for(int i = 0; i < n; i++)
        b[i] = a[i] - x;
    double sum = 0;
    double cur = -1e12;
    for(int i = 0; i < n; i++){
        sum += b[i];
        cur = max(cur, sum);
        if( sum < 0 ) sum = 0;
    }
    for(int i = 0; i < n; i++)
        b[i] = -a[i] + x;
    sum = 0;
    for(int i = 0; i < n; i++){
        sum += b[i];
        cur = max(cur, sum);
        if( sum < 0 ) sum = 0;
    }
    return cur;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    double l = -20000, r = 20000;
    
    for(int i = 0; i < 300; i++){
        double dif = (r - l)/3.0;
        double f1 = l + dif;
        double f2 = l + 2.0 * dif;
        if( g(f1) < g(f2)){
            r = f2;
        }
        else l = f1;
    }
    printf("%.12lf\n", g(r));
//  printf("%.12lf\n", g(2));
    






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}