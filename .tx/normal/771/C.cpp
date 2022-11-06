#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int n, k;
vector<int> g[222222];
bool centr[222222];
int sz[222222];

void calc_sz(int v, int p) {
    sz[v] = 1;
    for (int i : g[v]) {
        if (i == p || centr[i]) {
            continue;
        }
        calc_sz(i, v);
        sz[v] += sz[i];
    }
}

int find_center(int v, int p, int n) {
    sz[v] = 1;
    int mx = 0;
    int res = -1;
    for (int i : g[v]) {
        if (i == p || centr[i]) {
            continue;
        }
        int t = find_center(i, v, n);
        sz[v] += sz[i];
        if (sz[i] > mx) {
            mx = sz[i];
            res = t;
        }
    }
    if (mx * 2 > n) {
        return res;
    }
    return v;
}

lint ans = 0;
lint cnt[5];
lint hs[5];

void calc_ans(int v, int p, int d) {
    int x = d / k;
    int y = d % k;
    for (int i = 0; i < k; i++) {
        ans += cnt[i] * x + hs[i] + (y + i + k - 1) / k * cnt[i];
    }

    for (int i : g[v]) {
        if (i == p || centr[i]) {
            continue;
        }
        calc_ans(i, v, d + 1);
    }
}

void calc_cnt(int v, int p, int d) {
    int x = d / k;
    int y = d % k;
    cnt[y]++;
    hs[y] += x;

    for (int i : g[v]) {
        if (i == p || centr[i]) {
            continue;
        }
        calc_cnt(i, v, d + 1);
    }
}

int mxdep = 0;

void go(int v, int n) {
    int c = find_center(v, -1, n);
//    cerr << v << ": " << c << endl;
    centr[c] = true;

    memset(cnt, 0, sizeof(cnt));
    memset(hs, 0, sizeof(hs));

    cnt[0] = 1;

    for (int i : g[c]) {
        if (centr[i]) {
            continue;
        }
        calc_ans(i, c, 1);
        calc_cnt(i, c, 1);
    }

    for (int i : g[c]) {
        if (centr[i]) {
            continue;
        }
        go(i, n >> 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sci(n, k);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

//    cout << find_centr(0, -1);

    go(0, n);

    cout << ans;


    return 0;
}