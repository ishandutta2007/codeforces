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

//#define int li

#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

struct line {
    // ax + b
    li a, b;

    li eval(li x) const { return a * x + b; }

    bool operator<(const line& l) const {
        return make_pair(a, b) < make_pair(l.a, l.b);
    }
};

vector<int> a, b;
vector<vector<int>> e;

/*class hull_optimizer {
    struct line {
        long long m, b, value;
        double xlo;
        bool is_query, query_max;

        line(long long m, long long b, long long v, bool is_query, bool query_max)
            : m(m), b(b), value(v), xlo(-std::numeric_limits<double>::max()),
              is_query(is_query), query_max(query_max) {}

        double intersect(const line &l) const {
            if (m == l.m) {
                return std::numeric_limits<double>::max();
            }
            return (double)(l.b - b)/(m - l.m);
        }

        bool operator<(const line &l) const {
            if (l.is_query) {
                return query_max ? (xlo < l.value) : (l.value < xlo);
            }
            return m < l.m;
        }
    };
public :

    std::set<line> hull;
    bool query_max;

    typedef std::set<line>::iterator hulliter;

    bool has_prev(hulliter it) const {
        return it != hull.begin();
    }

    bool has_next(hulliter it) const {
        return (it != hull.end()) && (++it != hull.end());
    }

    bool irrelevant(hulliter it) const {
        if (!has_prev(it) || !has_next(it)) {
            return false;
        }
        hulliter prev = it, next = it;
        --prev;
        ++next;
        return query_max ? (prev->intersect(*next) <= prev->intersect(*it))
                         : (next->intersect(*prev) <= next->intersect(*it));
    }

    hulliter update_left_border(hulliter it) {
        if ((query_max && !has_prev(it)) || (!query_max && !has_next(it))) {
            return it;
        }
        hulliter it2 = it;
        double value = it->intersect(query_max ? *--it2 : *++it2);
        line l(*it);
        l.xlo = value;
        hull.erase(it++);
        return hull.insert(it, l);
    }

public:
    hull_optimizer(bool query_max = false) : query_max(query_max) {}

    void add_line(long long m, long long b) {
        line l(m, b, 0, false, query_max);
        hulliter it = hull.lower_bound(l);
        if (it != hull.end() && it->m == l.m) {
            if ((query_max && it->b < b) || (!query_max && b < it->b)) {
                hull.erase(it++);
            } else {
                return;
            }
        }
        it = hull.insert(it, l);
        if (irrelevant(it)) {
            hull.erase(it);
            return;
        }
        while (has_prev(it) && irrelevant(--it)) {
            hull.erase(it++);
        }
        while (has_next(it) && irrelevant(++it)) {
            hull.erase(it--);
        }
        it = update_left_border(it);
        if (has_prev(it)) {
            update_left_border(--it);
        }
        if (it != hull.end() && has_next(++it)) {
            update_left_border(++it);
        }
    }

    long long query(long long x) const {
        line q(0, 0, x, true, query_max);
        hulliter it = hull.lower_bound(q);
        if (query_max) {
            --it;
        }
        if (it == hull.end()) return 1e18;
        return it->m*x + it->b;
    }
};*/

const li is_query = -(1LL << 62);

struct Line {
    li m, b;
    mutable function<const Line *()> succ;

    bool operator<(const Line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        li x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

//using LI = int128_t;

struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (long double)(z->m - y->m) >= (y->b - z->b) * (long double)(y->m - x->m);
    }

    void insert_line(li m, li b) {
        m *= -1, b *= -1;
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }

    li eval(li x) {
        auto l = *lower_bound((Line) {x, is_query});
        return -(l.m * x + l.b);
    }
};

struct cht {
    set<line> lines, dumb;
    //hull_optimizer opt;
    //HullDynamic* opt = nullptr;
    shared_ptr<HullDynamic> opt;

    cht(): opt(new HullDynamic) {
    }

    void addLine(line l) {
        dumb.insert(l);
        lines.insert(l);

        opt->insert_line(l.a, l.b);

        /*
        auto it = lines.insert(l);

        while (true) {
            while (it != lines.end() && next(it)->a == it->a) {
                lines.erase(next(it));
            }

            if (it != lines.begin() && prev(it)->a == it->a) {
                lines.erase(it);
                return;
            }

            // ok (no)

            while (it != lines.begin() && prev(it) != lines.begin()
        }*/
    }

    int size() const { return lines.size(); }

    li minQuery(int x) {
#if 0
        li mx = 1e18;
        assert(!lines.empty());
        for (const line& l: dumb) {
            //cout << "line " << l.a << " " << l.b << "\n";
            mx = min(mx, l.eval(x));
        }

#endif
        assert(!lines.empty());

        li exp = opt->eval(x);
        //cout << mx << " " << exp << endl;
        //assert(mx == exp);

        return exp;
    }
};

vector<li> dp;

cht dfs(int v, int p = -1) {
    cht cur;

    for (int u: e[v]) {
        if (u == p) continue;

        cht x = dfs(u, v);

#if 1
        if (x.size() > cur.size()) {
            swap(x, cur);
            //x.dumb.swap(cur.dumb);
            //x.lines.swap(cur.lines);
            //x.opt.hull.swap(cur.opt.hull);
            //x.opt.swap(cur.opt);
            //swap(x.opt, cur.opt);
        }
#endif

        for (const line& l: x.lines)
            cur.addLine(l);
    }

    dp[v] = cur.lines.empty() ? 0 : cur.minQuery(a[v]);
    cur.addLine(line { b[v], dp[v] });

    return cur;
}

void solve(bool __attribute__((unused)) read) {
    int n;
    if (read)
        cin >> n;
    else
        n = rand() % 10000 + 1;

    a.resize(n);
    b.resize(n);

    const int MC = 20;
    for (int i = 0; i < n; ++i) if (read) cin >> a[i]; else a[i] = rand() % (int)(MC * 2) - MC;
    for (int i = 0; i < n; ++i) if (read) cin >> b[i]; else b[i] = rand() % (int)(MC * 2) - MC;

    e.clear();
    e.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        if (read) {
            cin >> u >> v;
            --u;
            --v;
        }
        else {
            u = rand() % (i + 1);
            v = i + 1;
        }

        e[u].push_back(v);
        e[v].push_back(u);
    }

    dp.assign(n, 0);
    cht res = dfs(0);

    for (int i = 0; i < n; ++i)
        cout << dp[i] << " ";
    cout << "\n";
}