#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

#define int li

void solve(bool);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

    //while (true) solve(false);

    return 0;
}

vector<vector<int>> ed;
vector<vector<int>> e;
vector<int> depth;
vector<int> parent;

void dfs(int v, int p = -1) {
    for (int u : ed[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        parent[u] = v;
        e[v].push_back(u);
        dfs(u, v);
    }
}

const int MOD = 1e9 + 7;

void add(int& to, int x) {
    to += x;
    if (to >= MOD) {
        to -= MOD;
    }
}

struct maxcalc {
    vector<pair<int, int>> pushTo, popFrom;

    int mx(vector<pair<int, int>>& vec) {
        return vec.empty() ? 0 : vec.back().second;
    }

    void push(vector<pair<int, int>>& to, int x) {
        int y = max(x, mx(to));
        to.emplace_back(x, y);
    }

    void push(int x) {
        push(pushTo, x);
    }

    void pop() {
        if (popFrom.empty()) {
            while (!pushTo.empty()) {
                int x = pushTo.back().first;
                pushTo.pop_back();
                push(popFrom, x);
            }
        }
        assert(!popFrom.empty());
        popFrom.pop_back();
    }

    int get() {
        return max(mx(pushTo), mx(popFrom));
    }
};

struct sufmax {
    vector<pair<int, int>> nums;
    int value = 0;

    void doAdd(int x, int cnt) {
        while (!nums.empty() && nums.back().first < x) {
            cnt += nums.back().second;
            add(value, MOD - (nums.back().second * nums.back().first) % MOD);
            nums.pop_back();
        }
        nums.emplace_back(x, cnt);
        add(value, x * cnt % MOD);
    }
};

int z(vector<int> a, int k) {
    int n = a.size();
    if (n < k) {
        return 0;
    }

    int ans = 0;

    vector<int> b;
    for (int i = 0; i + k - 1 < n; ++i) {
        int mx = 0;
        for (int j = i; j < i + k; ++j) {
            mx = max(mx, a[j]);
        }
        ans += mx;
        b.push_back(mx);
    }

    return ans + z(b, k);
}

void solve(bool __attribute__((unused)) read) {
    int n, k;
    if (read) {
        cin >> n >> k;
    } else {
        n = rand() % 10 + 2;
        k = min<li>(n, rand() % 10 + 2);
    }
    --k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (read) {

            cin >> a[i];
        } else {
            a[i] = rand() % 10 + 1;
        }
    }

    vector<maxcalc> maxcalcs(n / k + 1);
    for (int i = 0; i < n; ++i) {
        maxcalcs[i / k].push(a[i]);
    }

    int answer = 0;

    for (int start = 0; start < k; ++start) {
        //cout << "start = " << start << endl;

        sufmax s;
        int last = start;
        for (int i = start; i < n; i += k) {
            last = max(last, i);
        }

        for (int i = last; i >= start; i -= k) {
            if (i + k - 1 >= n) {
                continue;
            }

            s.doAdd(maxcalcs[i / k].get(), 1);
            if (i > 0) {
                s.doAdd(a[i - 1], 0);
                //cout << "from " << i << " " << s.value << endl;
                add(answer, s.value);
            }
        }

        for (int t = start; t < n; t += k) {
            maxcalcs[t / k].pop();
            if (t + k < n) {
                maxcalcs[t / k].push(a[t + k]);
            }
        }
    }

    cout << answer << endl;
#if 0
    int expected = z(a, k + 1);
    cout << "expected: " << expected << endl;
    assert(answer == expected);
#endif
}