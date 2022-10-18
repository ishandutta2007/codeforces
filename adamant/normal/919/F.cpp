#include <bits/stdc++.h>

using namespace std;

const int maxn = 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 + 42;
const int half_mx = 9 * 9 * 9 * 9;

int ans[245025 + 1];
int pw[10];

int get(int mask, int i) {
    if(i == -1) {
        return 0;
    }
    return (mask / pw[i]) % 9;
}
#define set aambal
int set(int mask, int i, int x) {
    if(x == -1) {
        return mask;
    }
    mask -= get(mask, i) * pw[i];
    mask += x * pw[i];
    return mask;
}

map<int, int> hasher;
map<int, int> dehsh;
int get_hash(int mask) {
    if(!hasher[mask]) {
        hasher[mask] = hasher.size();
        dehsh[hasher[mask]] = mask;
    }
    return hasher[mask];
}

int dehash(int hsh) {
    return dehsh[hsh];
}

void print(int x) {
    cout << x % 9 << ' ' << (x / 9) % 9 << ' ' << (x / 9 / 9) % 9 << ' ' << (x / 9 / 9 / 9) % 9 << endl;
}
int print_mask(int mask) {
    int mask1 = mask / pw[4];
    int mask2 = mask % pw[4];
    print(mask1);
    print(mask2);
}


vector<int> g[245025 + 1];
int deg[245025 + 1];

int combine(int mask1, int mask2) {
    return mask1 * pw[4] + mask2;
}

vector<int> que;

int counter1 = 0, counter2 = 0;
int presolve(int mask1, int mask2) {
    counter1++;
    int mask = combine(mask1, mask2);
    if(mask1 == 0 && mask2 == 0) {
        return 0;
    } else if(mask1 == 0) {
        que.push_back(get_hash(mask));
        return ans[get_hash(mask)] = 2;
    } else if(mask2 == 0) {
        que.push_back(get_hash(mask));
        return ans[get_hash(mask)] = 1;
    }
    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j <= 4; j++) {
            int A = get(mask1, i - 1);
            int B = get(mask2, j - 1);
            int C = get(mask1, (i + j) % 5 - 1);
            if(A && B) {
                int tm1 = set(set(mask1, i - 1, A - 1), (i + j) % 5 - 1, C + 1);
                counter2++;
                g[get_hash(combine(mask2, tm1))].push_back(get_hash(mask));
                deg[get_hash(mask)]++;
            }
        }
    }
}

int get_mask(int *x) {
    return x[0] + x[1] * 9 + x[2] * 9 * 9 + x[3] * 9 * 9 * 9;
}

int solve(int mask1, int mask2) {
    return ans[get_hash(combine(mask1, mask2))];
}

void solve() {
    int f;
    cin >> f;
    int cnt[2][4];
    memset(cnt, 0, 8 * sizeof(int));
    for(int z = 0; z <= 1; z++) {
        for(int i = 0; i < 8; i++) {
            int t;
            cin >> t;
            if(t == 0) {
                continue;
            }
            cnt[z][t - 1]++;
        }
    }
    if(f) {
        swap(cnt[0], cnt[1]);
    }
    int t = solve(get_mask(cnt[0]), get_mask(cnt[1]));
    cout << (t == 0 ? "Deal" : (t == 2) ^ (f) ? "Alice" : "Bob") << endl;
}

bool ok(int mask) {
    return get(mask, 0) + get(mask, 1) + get(mask, 2) + get(mask, 3) <= 8;
}

int used[245025 + 1];
void dfs(int v) {
    used[v] = true;
    for(auto u: g[v]) {
        if(!used[u]) {
            if(ans[v] == 1) {
                ans[u] = 2;
            } else if(--deg[u] == 0) {
                ans[u] = 1;
            } else {
                continue;
            }
            dfs(u);
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1;
    for(int i = 1; i < 10; i++) {
        pw[i] = pw[i - 1] * 9;
    }
    for(int i = 0; i < half_mx; i++) {
        for(int j = 0; j < half_mx; j++) {
            if(ok(i) && ok(j)) {
                presolve(i, j);
            }
        }
    }
    int cnt1[4] = {0, 0, 1, 0};
    int cnt2[4] = {0, 0, 0, 0};
    //dfs(get_hash(combine(get_mask(cnt1), get_mask(cnt2))));
    for(auto it: que) {
        dfs(it);
    }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}