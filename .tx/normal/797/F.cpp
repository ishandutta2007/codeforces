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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int x[5555];
pair<int, int> h[5555];

lint d[5555][5555];
//#ifdef TOXA31
//lint ds[5555][5555];
//#endif

const lint inf = 1e18;

lint stupid() {
#ifdef TOXA31
    ifstream in("input.txt");
    int n, m;
    in >> n >> m;
    for (int i = 0; i < n; i++) {
        in >> x[i];
    }
    sort(x, x + n);

    for (int i = 0; i < m; ++i) {
        in >> h[i].first;
        in >> h[i].second;
    }
    sort(h, h + m);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = inf;
        }
    }

    d[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            lint cur = 0;
            for (int t = 0; t <= min(j, h[i - 1].second); t++) {
                d[i][j] = min(d[i][j], d[i - 1][j - t] + cur);
                if (t != j) {
                    cur += abs(x[j - 1 - t] - h[i - 1].first);
                }
            }
        }
    }

    return (d[m][n] == inf ? -1 : d[m][n]);
#endif
}

void gen() {
    ofstream out("input.txt");

    int n = 500;
    int m = 100;
    int x = 1e9;

    out << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        out << rand() % x << " ";
    }

    out << "\n";

    for (int i = 0; i < m; i++) {
        out << rand() % x << " " << abs(rand()) % 10 + 1 << "\n";
    }
    out.close();
}

int main() {
#ifdef TOXA31
    srand(time(0));
for (int it = 0; it < 100; it++) {
    cout << it << endl;
    gen();
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        sci(x[i]);
    }
    sort(x, x + n);

    for (int i = 0; i < m; ++i) {
        sci(h[i].first, h[i].second);
    }
    sort(h, h + m);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = inf;
        }
    }

    d[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        lint cur = 0;
        int fst = -1;
        int cr = h[i - 1].second;
        d[i][0] = 0;
        for (int j = 1; j <= n; j++) {
            int cd = abs(h[i - 1].first - x[j - 1]);
            if (fst == -1) {
                if (cd + d[i - 1][j - 1] < d[i - 1][j]) {
                    d[i][j] = d[i - 1][j - 1] + cd;
                    fst = j - 1;
                    cr--;
                    cur += cd;
                } else {
                    d[i][j] = d[i - 1][j];
                }
            } else {
                if (cr > 0) {
                    cur += cd;
                    d[i][j] = min(inf, d[i - 1][fst] + cur);
                    cr--;
                } else {
                    cur += cd;
                    cur -= abs(h[i - 1].first - x[fst]);
                    fst++;
                    d[i][j] = min(inf, d[i - 1][fst] + cur);
                }
            }
        }
    }
#ifdef TOXA31
    lint ans = (d[m][n] == inf ? -1 : d[m][n]);
    lint st_ans = stupid();
    if (ans != st_ans) {
        cout << st_ans << "\n" << ans << endl;
        break;
    }
    cerr << st_ans << endl;
}
#else
    cout << (d[m][n] == inf ? -1 : d[m][n]);
#endif
    return 0;
}