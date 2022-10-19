#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 300005;

bool isPrime[N+1];

void sieve(int N) {
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &e : a) {
        cin >> e;
    }
    vector<vector<long long>> vals(n + 1);
    vector<int> ps;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && n % i == 0) {
            ps.push_back(i);
            vals[i].resize(n / i, 0);
            long long foo = n / i;
            for (int j = 0; j < n; j++) {
                vals[i][j % foo] += foo * a[j];
            }
        }
    }
    set<tuple<long long, int, int>> s;
    for (int e : ps) {
        int foo = n / e;
        for (int j = 0; j < foo; j++) {
            s.insert(make_tuple(vals[e][j], e, j));
        }
    }
    cout << get<0>(*s.rbegin()) << endl;
    for (int rep = 0; rep < q; rep++) {
        int p, x;
        cin >> p >> x;
        p--;
        long long delta = x - a[p];
        a[p] = x;
        for (int e : ps) {
            int foo = n / e;
            int pos = p % foo;
            s.erase(make_tuple(vals[e][pos], e, pos));
            vals[e][pos] += delta * foo;
            s.insert(make_tuple(vals[e][pos], e, pos));
            // debug(e, pos, vals[e][pos]);
        }
        cout << get<0>(*s.rbegin()) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(N);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}