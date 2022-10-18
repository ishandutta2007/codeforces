#include <bits/stdc++.h>

using namespace std;

#define int int64_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 30;
map<int, vector<int>> hashes;

vector<int> hashify(int x) {
    if(hashes.count(x)) {
        return hashes[x];
    } else {
        vector<int> hs(K);
        for(int i = 0; i < K; i++) {
            hs[i] = rng();
        }
        return hashes[x] = hs;
    }
}

const int maxn = 3e5 + 42;

int cur[maxn];

int A[K][maxn];

void add(int i, auto hs, int c) {
    for(int z = 0; z < K; z++) {
        for(int j = i; j < maxn; j += j & -j) {
            A[z][j] += hs[z] * c;
        }
    }
}

vector<int> get(int i) {
    vector<int> res(K);
    for(int z = 0; z < K; z++) {
        for(int j = i; j > 0; j -= j & -j) {
            res[z] += A[z][j];
        }
    }
    return res;
}

void upd(int i, int x) {
    add(i, hashify(cur[i]), -1);
    cur[i] = x;
    add(i, hashify(cur[i]), +1);
}

bool check(int l, int r, int k) {
    auto A = get(l - 1);
    auto B = get(r);
    for(int z = 0; z < K; z++) {
        if((B[z] - A[z]) % k != 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        upd(i + 1, a[i]);
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i, x;
            cin >> i >> x;
            upd(i, x);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << (check(l, r, k) ? "yes" : "no") << "\n";
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    cerr << clock() / double(CLOCKS_PER_SEC) << endl;
    //return 0;
}