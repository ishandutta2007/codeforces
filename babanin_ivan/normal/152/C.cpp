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

const int64 inf = 1000000007;
const ld eps = 1e-07;

int n, m;
vector <int> a[300];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c ", &c);
            a[j].pb(c);
        }
    }
    int64 ans = 1;
    for (int i = 0; i < m; ++i) {
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
        ans = (ans * int64(a[i].size())) % inf;
    }
    cout << ans << endl;
    return 0;
}