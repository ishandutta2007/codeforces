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
const int treesz = 131072;

int64 rsq[7][2 * treesz + 100];

vector <int> a;
pair <int, int> b[treesz];
int n;

int find(int x) {
    return int(lower_bound(a.begin(), a.end(), x) - a.begin());
}

void modif(int i, int d) {
    int j = i + treesz - 1;
    if (d == 0) {
        for (int t = 0; t < 6; ++t)
            rsq[t][j] = 0;
    }
    if (d == 1) {
        rsq[0][j] = a[i - 1];
        rsq[5][j] = 1;
    }
    while (j > 1) {
        j /= 2;
        for (int t = 0; t < 5; ++t)
            rsq[t][j] = rsq[t][2 * j];
        int szl = rsq[5][2 * j];
        for (int t = 0; t < 5; ++t)
            rsq[(szl + t) % 5][j] += rsq[t][2 * j + 1];
        rsq[5][j] = rsq[5][2 * j] + rsq[5][2 * j + 1];
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char c, c1, c2;
        scanf(" %c %c %c ", &c, &c1, &c2);
        if (c == 'a')
            b[i].first = 0;
        if (c == 'd')
            b[i].first = 1;
        if (c == 's')
            b[i].first = 2;
        else {
            int x;
            scanf("%d", &x);
            a.pb(x);
            b[i].second = x;
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        if (b[i].first == 0) {
            modif(find(b[i].second) + 1, 1);
        }
        if (b[i].first == 1) {
            modif(find(b[i].second) + 1, 0);
        }
        if (b[i].first == 2) {
            printf("%I64d\n", rsq[2][1]);
        }
    }
    return 0;
}