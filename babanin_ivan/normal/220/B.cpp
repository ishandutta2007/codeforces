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

int n, m;
int a[200000];
vector <pair <int, int> > b;
vector <pair <pair <int, int>, int> > c;
int sum[200000];
int res[200000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > n)
            a[i] = 0;
    }
    int step = int(sqrt(ld(n)));

    for (int j = 0; j < m; ++j) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        b.pb(mp(x, y));
        c.pb(mp(mp(x / step, y), j)); 
    }
    sort(c.begin(), c.end());
    pair <int, int> last = mp(-1, -1);
    int lastres = 0;
    for (int z = 0; z < m; ++z) {
        if ((z != 0) && (c[z - 1].first.first != c[z].first.first)) {
            last = mp(-1, -1);
            lastres = 0;
            for (int i = 0; i <= n; ++i)
                sum[i] = 0;
        }
        int it = c[z].second;
        if (last == mp(-1, -1)) {
            for (int i = b[it].first; i <= b[it].second; ++i) {
                if (a[i] == 0)
                    continue;
                if (sum[a[i]] == a[i])
                    --res[it];
                ++sum[a[i]];
                if (sum[a[i]] == a[i])
                    ++res[it];
            }
            last = b[it];
            lastres = res[it];
        }
        else {
            res[it] = lastres;
            for (int i = last.second + 1; i <= b[it].second; ++i) {
                if (a[i] == 0)
                    continue;
                if (sum[a[i]] == a[i])
                    --res[it];
                ++sum[a[i]];
                if (sum[a[i]] == a[i])
                    ++res[it];
            }
            if (last.first > b[it].first) {
                for (int i = b[it].first; i < last.first; ++i) {
                    if (a[i] == 0)
                        continue;
                    if (sum[a[i]] == a[i])
                        --res[it];
                    ++sum[a[i]];
                    if (sum[a[i]] == a[i])
                        ++res[it];
                }
            }
            else {
                for (int i = last.first; i < b[it].first; ++i) {
                    if (a[i] == 0)
                        continue;
                    if (sum[a[i]] == a[i])
                        --res[it];
                    --sum[a[i]];
                    if (sum[a[i]] == a[i])
                        ++res[it];
                }
            }
            last = b[it];
            lastres = res[it];
        }
    }
    for (int i = 0; i < m; ++i)
        printf("%d\n", res[i]);
    return 0;
}