#include <bits/stdc++.h>

using namespace std;

// DEBUG BEGIN
#ifdef DEBUG
template <class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p) {
    return out << "{" << p.first << ", " << p.second << "}";
}
template <class Tuple, size_t N> struct TuplePrinter {
    static ostream &print(ostream &out, const Tuple &t) {
        return TuplePrinter<Tuple, N - 1>::print(out, t) << ", " << get<N - 1>(t);
    }
};
template <class Tuple> struct TuplePrinter<Tuple, 1> {
    static ostream &print(ostream &out, const Tuple &t) { return out << get<0>(t); }
};
template <class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t) {
    return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "{", t) << "}";
}
template <class... Args> ostream &operator<<(ostream &out, const tuple<Args...> &t) { return print_tuple(out, t); }
template <class T> ostream &operator<<(class enable_if<!is_same<T, string>::value, ostream>::type &out, const T &arr) {
    out << "{";
    for (auto x : arr)
        out << x << ", ";
    return out << (arr.empty() ? "" : "\b\b") << "}";
}
template <size_t S> ostream &operator<<(ostream &out, const bitset<S> &b) {
    for (auto i = 0; i < S; ++i)
        out << b[i];
    return out;
}
ostream &operator<<(ostream &out, const _Bit_reference &bit) { return out << bool(bit); }
template <class T, class A, class C> ostream &operator<<(ostream &out, priority_queue<T, A, C> pq) {
    vector<T> a;
    while (!pq.empty())
        a.push_back(pq.top()), pq.pop();
    return out << a;
}
void debug_out() { cerr << "\b\b " << endl; }
template <class Head, class... Tail> void debug_out(Head H, Tail... T) { cerr << H << ", ", debug_out(T...); }
void debug2_out() {}
template <class Head, class... Tail> void debug2_out(Head H, Tail... T) {
    cerr << "\n";
    for (auto x : H)
        cerr << x << "\n";
    debug2_out(T...);
}
void debug_frac_out() { cerr << "\b\b " << endl; }
template <class Head, class... Tail> void debug_frac_out(Head H, Tail... T) {
    for (auto d = 1;; ++d) {
        if ((H * d).value <= 1000000) {
            cerr << H * d << "/" << d << ", ";
            break;
        } else if ((-H * d).value <= 1000000) {
            cerr << "-" << -H * d << "/" << d << ", ";
            break;
        }
    }
    debug_frac_out(T...);
}
enum CODE { CCRED = 31, CCGREEN = 32, CCYELLOW = 33, CCBLUE = 34, CCDEFAULT = 39 };
#define debug_endl() cerr << endl;
#define debug(...)                                                                                                     \
    cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m",             \
        debug_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug2(...)                                                                                                    \
    cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "] \033[" << (int)CODE(CCBLUE) << "m",              \
        debug2_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#define debug_frac(...)                                                                                                \
    cerr << "\033[" << (int)CODE(CCRED) << "m[" << #__VA_ARGS__ << "]: \033[" << (int)CODE(CCBLUE) << "m",             \
        debug_frac_out(__VA_ARGS__), cerr << "\33[" << (int)CODE(CCDEFAULT) << "m";
#else
#define debug_endl() 42
#define debug(...) 42
#define debug2(...) 42
#define debug_frac(...) 42
#endif
// DEBUG END

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> syn;
    {
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            syn.insert({x, y});
        }
    }
    queue<pair<int, int>> q;
    map<pair<int, int>, int> dist;
    dist[{1, 1}] = 0;
    q.push({1, 1});
    while (!q.empty() && !dist.count({n, m})) {
        auto [x, y] = q.front();
        q.pop();
        int pw = x + y + syn.count({x, y});
        int ax = min(n, pw);
        int ay = y;    
        int bx = x;
        int by = min(m, pw);
        if ((ax + ay >= min({bx + by, n, m}) || ax == n) && !dist.count({ax, ay})) {
            dist[{ax, ay}] = dist[{x, y}] + 1;
            q.push({ax, ay});
        }
        if ((bx + by >= min({ax + ay, n, m}) || by == m) && !dist.count({bx, by})) {
            dist[{bx, by}] = dist[{x, y}] + 1;
            q.push({bx, by});
        }
    }
    cout << dist[{n, m}] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}