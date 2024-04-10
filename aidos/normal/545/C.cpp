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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

pii a[maxn];
int n;
bool was[maxn];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i].f, &a[i].s);
    }
    int ans = 0;
    was[0] = true;
    for(int i = 1; i < n ; i++){
        if(!was[i-1] && a[i-1].s + a[i-1].f < a[i].f){
            was[i-1] = true;
            a[i-1].f += a[i-1].s;
        }
        if(a[i].f - a[i-1].f > a[i].s) was[i] = true;
    }
    was[n-1]=true;
    for(int i = 0; i < n; i++)
        ans += was[i];
    cout << ans << endl;    
    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}