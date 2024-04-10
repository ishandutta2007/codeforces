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
vector <int> g[501000];
int p[501000];
int sz[501000];
set <int> vv;

int getanc(int v) {
    if (v == p[v])
        return v;
    return p[v] = getanc(p[v]);
}

void merge(int a, int b) {
    int x = getanc(a);
    int y = getanc(b);
    if (x == y)
        return;
    if (rand() & 1) {
        p[x] = y;
        sz[y] += sz[x];
    }
    else {
        p[y] = x;
        sz[x] += sz[y];
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sz[i] = 1;
        vv.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        vector <int> tmp, tmp2;
        tmp.resize(g[i].size());
        for (int j = 0; j < g[i].size(); ++j) {
            tmp[j] = getanc(g[i][j]);   
        }
        sort(tmp.begin(), tmp.end());
        int x = 0;
        int y;
        while (x < tmp.size()) {
            int sum = 0;
            y = x;
            while (y < tmp.size() && tmp[y] == tmp[x]) {
                ++y;
                ++sum;
            }
            if (sz[tmp[x]] == sum) {
                vv.erase(tmp[x]);
                tmp2.pb(tmp[x]);
            }
            x = y;
        }
        set <int> ::iterator it = vv.begin();
        while (it != vv.end()) {
            merge(i, *it);
            ++it;
        }
        vv.clear();
        vv.insert(getanc(i));
        for (int j = 0; j < tmp2.size(); ++j) {
            vv.insert(tmp2[j]);
        }
    }
    cout << vv.size();
    vector <pair <int, int>> tmp;
    for (int i = 0; i < n; ++i) {
        tmp.pb(mp(getanc(i), i));
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); ++i) {
        if ((i == 0) || (tmp[i].first != tmp[i - 1].first)) {
            printf("\n%d ", sz[tmp[i].first]);
        }
        printf("%d ", tmp[i].second + 1);
    }
    return 0;
}