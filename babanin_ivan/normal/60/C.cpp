#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void error() {
    cout << "NO\n";
    exit(0);
}

vector <pair <int, pair <int64, int64> > > a[1000];
int n, m;
int64 ans[1000];
int64 preans[1000];
int64 finans[1000];
int used[1000];
int k = 1;
bool waserr = false;

void dfs(int v) {
    used[v] = k;
    
    if (waserr)
        return ;
    
    for (int i = 0; i < a[v].size(); ++i) { 
        if (preans[v] > a[v][i].second.second) {
            waserr = true;
            return;
        }
        if (used[a[v][i].first] == k) {
            if (gcd(preans[v], preans[a[v][i].first]) != a[v][i].second.first) {
                waserr = true;
                return ;
            }
            if (((preans[v] * preans[a[v][i].first]) / a[v][i].second.first) != a[v][i].second.second) {
                waserr = true;
                return ;
            }
        }
        else {
            preans[a[v][i].first] = (a[v][i].second.first * a[v][i].second.second) / preans[v];
            if (preans[a[v][i].first] == 0) {
                waserr = true; 
                return;
            }
            dfs(a[v][i].first);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        ans[i] = 1;

    for (int i = 0; i < m; ++i) {
        int x, y;
        int64 d, k;
        cin >> x >> y >> d >> k;
        --x;
        --y;
        if (k % d) {
            error();
        }
        a[x].pb(mp(y, mp(d, k)));
        a[y].pb(mp(x, mp(d, k)));
        ans[x] = (ans[x] * d) / gcd(ans[x], d);
        ans[y] = (ans[y] * d) / gcd(ans[y], d);
    }

    for (int i = 0; i < n; ++i) {
        if (finans[i])
            continue;
        for (int64 j = 1; j <= 1000000; ++j) {
            if ((j * ans[i]) > 1000000LL)
                error();
            preans[i] = j * ans[i];
            ++k;
            waserr = false;
            dfs(i);
            if (waserr == false) {
                for (int p = 0; p < n; ++p)
                    if (used[p] == k)
                        finans[p] = preans[p];
                break;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", finans[i]);
    return 0;
}