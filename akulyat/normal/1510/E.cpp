#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>
#include <functional>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
    template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
    string pdbg(const string &s) { return "\"" + s + "\""; }
    template<class It> string pdbg(It begin, It end, string d);
    template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
    template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
    template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
    template<class It> string pdbg(It begin, It end, string d) {
        string ans;
        ans += "{";
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end)
            ans += "," + d + pdbg(*begin++);
        ans += "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

struct pt {
    ld x, y, w;
    pt() {}
    pt(ld _x, ld _y, ld _w) : x(_x), y(_y), w(_w) {}
    friend pt merge(const pt &a, const pt &b) {
        pt ans;
        ans.w = a.w + b.w;
        ans.x = (a.x * a.w + b.x * b.w) / ans.w;
        ans.y = (a.y * a.w + b.y * b.w) / ans.w;
        return ans;
    }
};

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    a.f -= b.f;
    a.s -= b.s;
    return sqrt(a.f * a.f + a.s * a.s);
}

void answer(string a, string b) {
    reverse(b);
    for (auto &i : b) {
        if (i == '(') i = ')';
        else i = '(';
    }
    println(a + b);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    exit(0);
}

const ld third = 1.0 / 3;
const ld twothird = 2.0 / 3;

pair<pii, pt> getcenter(string s) {
    int curr = 0;
    vector<int> h = {curr};
    for (auto i : s) {
        if (i == '(') ++curr;
        else --curr;
        if (curr < 0) return {{-1, -1}, {0, 0, 0}};
        h.pb(curr);
    }
    pt center = {0, 0, 0};
    int sq = 0;
    for (int i = 0; i + 1 < sz(h); ++i) {
        sq += h[i] + h[i + 1];
        int mn = min(h[i], h[i + 1]);
        pt low = {i + 0.5, mn * 0.5, (ld)mn};
        pt high;
        if (h[i] > h[i + 1]) {
            high = {i + third, mn + third, 0.5};
        } else {
            high = {i + twothird, mn + third, 0.5};
        }
        center = merge(center, merge(low, high));
    }
    return {{sq, curr}, center};
}

struct myset {
    map<pll, string> st;
    void add(ld X, ld Y, string s) {
        ll x = round(X * 1e7);
        ll y = round(Y * 1e7);
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy)
                st[{x + dx, y + dy}] = s;
    }
    string get(ld X, ld Y) {
        ll x = round(X * 1e7);
        ll y = round(Y * 1e7);
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy) {
                auto it = st.find({x + dx, y + dy});
                if (it != st.end()) return it->s;
            }
        return "";
    }
};

signed main() {
    FAST; FIXED;
    int n;
    ld X, Y;
    read(n, X, Y);
    const int MAXS = 18 * 18 + 1;
    const int MAXBAL = 18 + 1;
    vector<vector<myset>> st(MAXS, vector<myset>(MAXBAL));
    vector<vector<vector<pair<pt, string>>>> have(MAXS, vector<vector<pair<pt, string>>>(MAXBAL));
    for (int mask = 0; mask < (1 << (n / 2)); ++mask) {
        string s;
        for (int i = 0; i < (n / 2); ++i) {
            if (mask >> i & 1) s += '(';
            else s += ')';
        }
        auto res = getcenter(s);
        if (res.f.f < 0) continue;
        st[res.f.f][res.f.s].add(res.s.x, res.s.y, s);
        have[res.f.f][res.f.s].pb({res.s, s});
    }
    for (int sq = 0; sq < MAXS; ++sq)
        for (int bal = 0; bal < MAXBAL; ++bal) {
            for (auto i : have[sq][bal]) {
                pt left = i.f;
                for (int sqr = 0; sqr < MAXS; ++sqr)
                    if (sz(st[sqr][bal].st)) {
                        int sum = sq + sqr;
                        if (sum % 2 == 0) {
                            pt right = merge(pt(X, Y, sum / 2), pt(left.x, left.y, -left.w));
                            // dbg(left.x, left.y, left.w);
                            // dbg(right.x, right.y, right.w);
                            right.x = n - right.x;
                            auto res = st[sqr][bal].get(right.x, right.y);
                            if (sz(res) > 0) {
                                answer(i.s, res);
                            }
                        }
                    }
            }
        }
    assert(false);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}