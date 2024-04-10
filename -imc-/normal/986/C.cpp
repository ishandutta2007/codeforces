#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read);

int main() {
    auto t0 = clock();
#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout.precision(20);
    cout << fixed;

    solve(true);
#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif
}

//#define int li

struct fenwick {
    int n;
    vector<int> a;

    fenwick(int n): n(n), a(n) {}

    void add(int i, int x) {
        for (; i < n; i = (i | (i + 1)))
            a[i] += x;
    }

    int get(int i) {
        int ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            ans += a[i];
        return ans;
    }
};

li countInversions(vector<int> p) {
    int n = p.size();
    fenwick f(n);
    li answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += i - f.get(p[i]);
        f.add(p[i], 1);
    }
    return answer;
}

vector<int> gen(int n, int ns) {
    vector<int> p(n);
    iota(all(p), 0);
    for (int t = 0; t < ns; ++t) {
        int i = rand() % n;
        int j = rand() % n;

        swap(p[i], p[j]);
    }
    return p;
}

const int N = 22;
const int whole = (1 << N) - 1;

bool have[1 << N];

template<class T>
inline void iterateEdges(int v, T callback) {
    if (v < (1 << N)) {
        callback((whole ^ v) + (1 << N));
    }
    else {
        int value = v - (1 << N);
        if (have[value])
            callback(value);
        for (int t = 0; t < N; ++t)
            if (value & (1 << t))
                callback((value & ~(1 << t)) | (1 << N));
    }
}

template<class T>
inline void iterateRevEdges(int v, T callback) {
    if (v < (1 << N)) {
        callback(v + (1 << N));
    }
    else {
        int value = v - (1 << N);
        if (have[whole ^ value])
            callback(whole ^ value);
        for (int t = 0; t < N; ++t)
            if (!(value & (1 << t)))
                callback((value | (1 << t)) | (1 << N));
    }
}

bool used[1 << (N + 1)];
vector<int> order;

void dfs(int v) {
    used[v] = true;

    iterateEdges(v, [](int u) {
        if (!used[u]) {
            dfs(u);
        }
    });

    order.push_back(v);
}

int qptr[1 << (N + 1)];

int getEdge(int v) {
    ++qptr[v];

    if (v < (1 << N)) {
        if (qptr[v] == 1)
            return (whole ^ v) + (1 << N);
        else
            return -1;
    }
    else {
        int value = v - (1 << N);
        if (qptr[v] == 1) {
            if (have[value])
                return value;
            else
                ++qptr[v];
        }

        int nSkip = qptr[v] - 2;

        for (int t = 0; t < N; ++t)
            if (value & (1 << t)) {
                if (nSkip != 0) {
                    --nSkip;
                    continue;
                }

                int to = (value & ~(1 << t)) | (1 << N);
                return to;
            }

        assert(nSkip == 0);
        return -1;
    }
}

void nonrecDfs(int start) {
    vector<int> q;
    used[start] = true;
    q.push_back(start);

    while (!q.empty()) {
        int v = q.back();

        int u = getEdge(v);
        if (u == -1) {
            q.pop_back();
            order.push_back(v);
            continue;
        }

        if (!used[u]) {
            used[u] = true;
            q.push_back(u);
        }
    }
}

vector<int> comp;

void rdfs(int v) {
    used[v] = true;
    comp.push_back(v);

    iterateRevEdges(v, [](int u) {
        if (!used[u]) {
            rdfs(u);
        }
    });
}

vector<int> q;

void bfs(int v) {
    used[v] = true;
    int qptr = 0;
    q.clear();
    q.push_back(v);

    while (qptr < q.size()) {
        v = q[qptr];
        ++qptr;
        comp.push_back(v);

        iterateRevEdges(v, [](int u) {
            if (!used[u]) {
                used[u] = true;
                q.push_back(u);
            }
        });
    }
}

void solve(bool __attribute__((unused)) read) {
    int lol, n;

    read = true;

    if (read)
        cin >> lol >> n;
    else
        lol = 22, n = 1 << 22;

    for (int i = 0; i < n; ++i) {
        int x;
        if (read)
            cin >> x;
        else
            x = i;
        have[x] = true;
    }

    order.reserve(1 << (N + 1));
    comp.reserve(1 << (N + 1));

    for (int i = 0; i < (1 << N); ++i) {
        if (have[i] && !used[i]) {
            nonrecDfs(i);
        }
            //dfs(i);
    }

    int answer = 0;

    q.reserve(1 << (N + 1));

    memset(used, 0, sizeof(used));
    reverse(all(order));
    for (int v: order) {
        if (!used[v]) {
            comp.clear();
            bfs(v);

            bool nonempty = false;
            for (int x: comp)
                if (x < (1 << N)) {
                    //cout << x << " ";
                    assert(have[x]);
                    nonempty = true;
                }
            if (nonempty) {
                //cout << endl;
                ++answer;
            }
        }
    }

    cout << answer << endl;
}