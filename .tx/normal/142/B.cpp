#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct item {
    int x, y, w;

    bool operator<(const item& r) const {
        if (w != r.w) {
            return w < r.w;
        }
        if (x != r.x) {
            return x < r.x;
        }
        return y < r.y;
    }
};

vector<int> a[1111][1111];
item objects[1111 * 1111];
bool forbid[1111][1111];

int hx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int hy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

int n, m;

bool taken_id[1111 * 1111];

vector<int> pam[9];

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int id_min() {
    for (int i = 0; i <= 8; i++) {
        if (!pam[i].empty()) {
            int res = pam[i].back();
            pam[i].pop_back();
            return res;
        }
    }
    return -1;
}

int main() {
    scii(n, m);
    if (min(n, m) >= 10) {
        cout << n * m - (n * m) / 2;
        return 0;
    }
    set<item> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int id = i * m + j;
            int w = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + hx[k];
                int y = j + hy[k];
                if (check(x, y)) {
                    a[x][y].push_back(id);
                    w++;
                }
            }
            objects[id] = item{i, j, w};
//            st.insert(objects[id]);
            pam[w].push_back(id);
        }
    }

    int ans = 0;

    while (true) {//
        int cid = id_min();
        if (cid == -1) {
            break;
        }
        item& it = objects[cid];
        if (forbid[it.x][it.y] || taken_id[cid]) {
            continue;
        }
        taken_id[cid] = true;
        ans++;
        for (int i = 0; i < 8; i++) {
            int x = it.x + hx[i];
            int y = it.y + hy[i];
            if (check(x, y) && !forbid[x][y]) {
                forbid[x][y] = true;
                for (int id : a[x][y]) {
//                    if (taken_id[id]) {
//                        continue;
//                    }
//                    st.erase(objects[id]);
                    objects[id].w--;

//                    st.insert(objects[id]);
                    pam[objects[id].w].push_back(id);
                }
            }
        }
    }

    cout << ans;

    return 0;
}