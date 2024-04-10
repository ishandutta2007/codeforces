#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;
int n;

#define merge merge228

const int INF = 1e9 + 228;
const int MAXN = 1e5 + 228;

struct mdata {
    int arr[12];
};

bool hasa(int x) {
    return x == 0 || x == 3 || x == 4 || x == 5 || x >= 8;
}

bool hasab(int x) {
    return x == 4 || x >= 10;
}

bool hasc(int x) {
    return x == 2 || x >= 5;
}

bool hasbc(int x) {
    return x == 7 || x == 9 || x == 11;
}

bool hasb(int x) {
    return x == 1 || x == 3 || x == 4 || x >= 6;
}

int can[12][12];

const vector<int> ARR[12] = {
    {1, 0, 0, 0, 0}, 
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 0, 0, 0},
    {1, 1, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 1, 1, 0, 1},
    {1, 1, 1, 0, 0},
    {1, 1, 1, 0, 1},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1}
};

void build_merge() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            can[i][j] = -1;
            if ((hasa(i) && hasbc(j)) || (hasab(i) && hasc(j))) {
                continue;
            }
            vector<int> arr(5);
            if (hasa(i) || hasa(j))
                arr[0] = 1;
            if (hasb(i) || hasb(j))
                arr[1] = 1;
            if (hasc(i) || hasc(j))
                arr[2] = 1;
            if (hasab(i) || hasab(j) || (hasa(i) && hasb(j)))
                arr[3] = 1;
            if (hasbc(i) || hasbc(j) || (hasb(i) && hasc(j)))
                arr[4] = 1;
            int pos = 0;
            while (ARR[pos] != arr) {
                pos++;
            }
            can[i][j] = pos;
        }
    }
}

string s;

mdata merge(const mdata &a, const mdata &b) {
    vector<int> ia, ib;
    for (int i = 0; i < 12; i++) {
        if (a.arr[i] != INF)
            ia.push_back(i);
        if (b.arr[i] != INF)
            ib.push_back(i);
    }
    mdata ans;
    fill(ans.arr, ans.arr + 12, INF);
    for (int i : ia) {
        for (int j : ib) {
            if (can[i][j] != -1) {
                ans.arr[can[i][j]] = min(ans.arr[can[i][j]], a.arr[i] + b.arr[j]);
            }
        }
    }
    return ans;
}

mdata tree[4 * MAXN];

void build(int v, int l, int r) {
    if (l + 1 == r) {
        fill(tree[v].arr + 3, tree[v].arr + 12, INF);
        fill(tree[v].arr, tree[v].arr + 3, 1);
        tree[v].arr[s[l] - 'a'] = 0;
    } else {
        int m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

void update(int v, int l, int r, int i) {
    if (i < l || i >= r)
        return;
    if (l + 1 == r) {
        fill(tree[v].arr, tree[v].arr + 3, 1);
        tree[v].arr[s[l] - 'a'] = 0;
    } else {
        int m = (l + r) / 2;
        update(2 * v + 1, l, m, i);
        update(2 * v + 2, m, r, i);
        tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }
}


void solve() {
    build_merge();
    int q;
    cin >> n >> q;
    cin >> s;
    build(0, 0, n); 
    while (q--) {
        int i;
        cin >> i;
        char c;
        cin >> c;
        i--;
        s[i] = c;
        update(0, 0, n, i);
        cout << *min_element(tree[0].arr, tree[0].arr + 12) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}