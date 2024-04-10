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

int n, k;
vector <pair <int, int> > a;
vector <pair <int, int> > b;
vector <int> res[2000];
ld sum = 0;
int st[2000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int c, t;
        scanf("%d %d", &c, &t);
        sum += ld(c);
        if (t == 1)
            a.pb(mp(c, i));
        else b.pb(mp(c, i));
        st[i] = c;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a.size() >= k) {
        int j = a.size() - 1;
        for (int i = 0; i < k; ++i) {
            res[i].pb(a[j].second);
            --j;
        }
        while (j >= 0) {
            res[k - 1].pb(a[j].second);
            --j;
        }
        for (int i = 0; i < b.size(); ++i)
            res[k - 1].pb(b[i].second);
        for (int i = 0; i < k; ++i) {
            int minx = inf;
            for (int j = 0; j < res[i].size(); ++j)
                minx = min(minx, st[res[i][j]]);
            sum -= ld(minx) / 2.0;
        }
        cout.precision(1);
        cout << fixed << sum << endl;
        for (int i = 0; i < k; ++i) {
            printf("%d ", res[i].size());
            for (int j = 0; j < res[i].size(); ++j)
                printf("%d ", res[i][j] + 1);
            printf("\n");
        }
        return 0;
    }
    for (int i = 0; i < a.size(); ++i) {
        sum -= ld(a[i].first) / 2.0;
        res[i].pb(a[i].second);
    }
    int j = a.size();
    for (int i = 0; i < b.size(); ++i) {
        res[j].pb(b[i].second);
        ++j;
        if (j == k)
            j = a.size();
    }
    cout.precision(1);
    cout << fixed << sum << endl;
    for (int i = 0; i < k; ++i) {
        printf("%d ", res[i].size());
        for (int j = 0; j < res[i].size(); ++j)
            printf("%d ", res[i][j] + 1);
        printf("\n");
    }
    return 0;
}