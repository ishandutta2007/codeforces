#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

const int maxn = 2e5 + 42;


int to_add[4 * maxn], to_mul[4 * maxn];
int sum[4 * maxn];

void pushdown(int v, int u) {
    to_add[u] *= to_mul[v];
    to_mul[u] *= to_mul[v];
    to_add[u] += to_add[v];
    to_add[u] %= mod;
    to_mul[u] %= mod;
}

void push(int v, int l, int r) {
    if(to_add[v] == 0 && to_mul[v] == 1) {
        return;
    }
    sum[v] = (sum[v] * to_mul[v] + to_add[v] * (r - l)) % mod;
    if(r - l > 1) {
        pushdown(v, 2 * v);
        pushdown(v, 2 * v + 1);
    }
    to_mul[v] = 1;
    to_add[v] = 0;
}

void upd(int a, int b, int ad, int ml, int v = 1, int l = 0, int r = maxn) {
    push(v, l, r);
    if(a <= l && r <= b) {
        to_add[v] = ad;
        to_mul[v] = ml;
        push(v, l, r);
    } else if(r <= a || b <= l) {
        return;
    } else {
        int m = (l + r) / 2;
        upd(a, b, ad, ml, 2 * v, l, m);
        upd(a, b, ad, ml, 2 * v + 1, m, r);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        if(sum[v] >= mod) {
            sum[v] -= mod;
        }
    }
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    push(v, l, r);
    if(a <= l && r <= b) {
        return sum[v];
    } else if(r <= a || b <= l) {
        return 0;
    } else {
        int m = (l + r) / 2;
        int sm = get(a, b, 2 * v, l, m) + get(a, b, 2 * v + 1, m, r);
        if(sm >= mod) {
            sm -= mod;
        }
        return sm;
    }
}

set<pair<int, int>> que[maxn];

vector<tuple<int, int, int>> process(int x, int l, int r) {
    vector<tuple<int, int, int>> ans;
    auto it = prev(que[x].lower_bound({l + 1, 0}));
    if(it->second > l) {
        ans.push_back({1, l, min(it->second, r)});
        l = it->second;
    }
    it = que[x].lower_bound({l, 0});
    int last = l;
    while(it->first < r) {
        if(it->second <= r) {
            ans.push_back({1, it->first, it->second});
            ans.push_back({0, last, it->first});
            last = it->second;
            it = que[x].erase(it);
        } else {
            ans.push_back({1, it->first, r});
            ans.push_back({0, last, it->first});
            last = r;
            int L = r, R = it->second;
            r = it->first;
            //que[x].erase(it);
            //it = que[x].insert({L, R}).first;
        }
    }
    //cout << "!! " << l << ' ' << r << endl;
    if(last < r) {
        ans.push_back({0, last, r});
    }
    if(l < r) {
        que[x].insert({l, r});
    }
    /*cout << x << ":\n";
    for(auto it: que[x]) {
        cout << it.first << ' ' << it.second << endl;
    }*/
    return ans;
}

vector<tuple<int, int, int>> upd(int l, int r, int x) {
    auto nw = process(x, l, r);
    for(auto it: nw) {
        if(get<1>(it) == get<2>(it)) {
            continue;
        }
        if(get<0>(it)) { // multiply!
            //cout << get<1>(it) << ' ' << get<2>(it) << " += " << 0 << ", *= " << 2 << endl;
            upd(get<1>(it), get<2>(it), 0, 2);
        } else { // add!
            //cout << get<1>(it) << ' ' << get<2>(it) << " += " << 1 << ", *= " << 1 << endl;
            upd(get<1>(it), get<2>(it), 1, 1);
        }
    }
    //cout << endl;
    return nw;
}

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

void try1() {
    fill(to_mul, to_mul + 4 * maxn, 1);
    fill(to_add, to_add + 4 * maxn, 0);
    fill(sum, sum + 4 * maxn, 0);
    
    que[0].insert({-maxn, 0});
    que[0].insert({maxn, 2 * maxn});
    const int maxk = 5;
    int cnt[maxk];
    int func[maxk];
    memset(func, 0, sizeof(func));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < maxk / 2; i++) {
        int l = rand() % maxk;
        int r = l + rand() % (maxk - l) + 1;
        cout << l << ' ' << r << endl;
        //cout << l << ' ' << r << endl;
        auto lol = upd(l, r, 0);
        for(auto it = begin(que[0]); next(it) != end(que[0]); it++) {
            assert(it->second <= next(it)->first);
        }
        sort(begin(lol), end(lol), [&](tuple<int, int, int> A, tuple<int, int, int> B) {
            return pair<int, int>(get<1>(A), get<2>(A)) < pair<int, int>(get<1>(B), get<2>(B));
            });
        for(int j = l; j < r; j++) {
            cnt[j]++;
        }
        int used[maxk];
        fill(used, used + maxk, 0);
        for(int i = 0; i < lol.size(); i++) {
            if(i + 1 < lol.size()) {
                //cout << get<0>(lol[i]) << ' ' << get<1>(lol[i]) << ' ' << get<2>(lol[i]) << endl;
                //cout << get<0>(lol[i + 1]) << ' ' << get<1>(lol[i + 1]) << ' ' << get<2>(lol[i + 1]) << endl;
                assert(get<2>(lol[i]) <= get<1>(lol[i + 1]));
            }
            assert(get<1>(lol[i]) <= get<2>(lol[i]));
            for(int j = get<1>(lol[i]); j < get<2>(lol[i]); j++) {
                //cout << get<1>(lol[i]) << ' ' << get<2>(lol[i]) << ' ' << j << ' ' << cnt[j] << ' ' << get<0>(lol[i]) << endl;
                used[j] = true;
                if(cnt[j] == 1) {
                    func[j] = (func[j] + 1) % mod;
                    assert(get<0>(lol[i]) == 0);
                } else {
                    func[j] = (func[j] + func[j]) % mod;
                    assert(get<0>(lol[i]) == 1);
                }
            }
        }
        for(int i = 0; i < maxk; i++) {
            assert(used[i] == (l <= i && i < r));
            assert(func[i] == get(i, i + 1));
        }
        int control = 0;
        for(int i = l; i < r; i++) {
            control += func[i];
            control %= mod;
        }
        cout << l << ' ' << r << ' ' << control << ' ' << get(l, r) << endl;
        assert(control == get(l, r));
    }
    
    cout << "Ok!" << endl;
    que[0].clear();
}

void try_hack() {
    while(true) {
        try1();
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(to_mul, to_mul + 4 * maxn, 1);
    
    for(int i = 0; i < maxn; i++) {
        que[i].insert({-maxn, 0});
        que[i].insert({maxn, 2 * maxn});
    }
    //try_hack();
    
    int n, q;
    cin >> n >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--, x--;
            upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << get(l, r) << "\n";
        }
    }
    return 0;
}