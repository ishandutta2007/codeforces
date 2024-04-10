#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

#define int li

vector<vector<int>> e;
vector<int> value;

// oddity of num vertices in path, count of such pathes
vector<array<int, 2>> sum, cnt;

int answer;

const int MOD = 1e9 + 7;

void add(int& to, int x) {
    assert(x >= 0 && x < MOD);
    assert(to >= 0 && to < MOD);
    to += x;
    if (to >= MOD)
        to -= MOD;
}

void dfs(int v, int p) {
    add(sum[v][1], value[v]);
    add(cnt[v][1], 1);

    for (int u: e[v]) {
        if (u == p) continue;

        dfs(u, v);

        for (int t = 0; t < 2; ++t) {
            // v -> u path
            int s = (t == 0 ? 1 : MOD - 1);
            s = 1;

            // u part must be negated if our part is odd (t = 1)
            // it also always must be negated because it goes other direction

            add(answer, (sum[v][t] * cnt[u][1 - t] + s * ((sum[u][1 - t] * cnt[v][t]) % MOD)) % MOD);
        }

        for (int t = 0; t < 2; ++t) {
            // t == 1: take value as negative now
            add(sum[v][t], (sum[u][1 - t] + cnt[u][1 - t] * (t == 0 ? MOD - value[v] : value[v])) % MOD);
            add(cnt[v][t], cnt[u][1 - t]);
        }
    }

    //add(answer, sum[v][1]);
}

int stress = 0;

int sdfs(int v, int p, int cur_s, int cur_sign) {
    cur_s += value[v] * cur_sign;
    cur_sign *= -1;
    int add = cur_s;

    //cout << "sum " << cur_s << " " << value[v] * cur_sign << endl;

    for (int u: e[v]) {
        if (u == p) continue;

        add += sdfs(u, v, cur_s, cur_sign);
    }
    return add;
}

void solve(bool __attribute__((unused)) read) {
    int n;
    if (read) {
        cin >> n;
    }
    else {
        n = rand() % 10 + 1;
        cout << "TEST:\n";
        cout << n << endl;
    }

    value.assign(n, 0);

    li sum_vals = 0;
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> value[i];
        }
        else {
            value[i] = rand() % 5 + 1;
            cout << value[i] << " ";
        }
        value[i] %= MOD;
        if (value[i] < 0)
            value[i] += MOD;

        add(sum_vals, value[i]);
    }

    if (!read) {
        cout << endl;
    }

    e.clear();
    e.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        if (read)
            cin >> u >> v;
        else {
            u = rand() % (i + 1);
            v = i + 1;
            ++u; ++v;
            cout << u << " " << v << endl;
        }
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    array<int, 2> zero;
    zero.fill(0);
    sum.assign(n, zero);
    cnt.assign(n, zero);

    answer = 0;
    dfs(0, -1);
    //cout << "base answer " << answer << endl;
    add(answer, answer);
    //add(answer, (MOD - sum_vals) % MOD);
    add(answer, sum_vals % MOD);
    cout << answer << endl;

#if 0
    stress = 0;
    for (int i = 0; i < n; ++i) {
        int add = sdfs(i, -1, 0, 1);
        stress += add;
        cout << "with " << i + 1 << " got " << add << endl;
    }

    stress %= MOD;
    if (stress < 0) stress += MOD;
    cout << "answer: " << answer << " expected: " << stress << endl;
    assert(answer == stress);
#endif
}