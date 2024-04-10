#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
#define sz(v) ((int)(v).size())

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#ifdef LOCAL
#include "pretty_print.h"
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define nl "\n"

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

const int MAXN = 1e+6 + 42;
const int MAXM = 61;

int n;

ll a[MAXN];
int b[MAXN];


struct TInterval {
    int left, right, sum;
};
ostream& operator<<(ostream& out, const TInterval& i) {
    return out << "<" << i.left << "," << i.right << "," << i.sum << ">";
}

vector<TInterval> stmx[MAXM];
vector<TInterval> stmn[MAXM];

int get(vector<TInterval>& st, int left, int right) {
    // int ret = 0;
    // for (auto& i : st) {
    //     ret += max(min(right, i.right) - max(left, i.left) + 1, 0);
    // }

    // return ret;

    if (left) {
        return get(st, 0, right) - get(st, 0, left - 1);
    }

    int l = 0;
    int r = sz(st);
    while (l < r) {
        int m = (l + r) / 2;

        if (st[m].left <= right) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    int idx = l - 1;
    return st[idx].sum - max(st[idx].right - max(st[idx].left, right), 0);
};

int main(int /* argc */, const char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = __builtin_popcountll(a[i]);
        }

        ll answer = 0;

        for (int i = 0; i < MAXM; ++i) {
            stmx[i].clear();
            stmx[i].push_back({-1, -1, 0});
            stmn[i].clear();
            stmn[i].push_back({-1, -1, 0});
        }

        ll result = 0;
        stack<pair<ll, int>> mx;
        stack<pair<ll, int>> mn;

        const ll INF = 1e+18 + 42;
        mx.push({INF, -1});
        mn.push({-INF, -1});


        for (int i = 0; i < n; ++i) {

            while (mx.top().first < a[i]) {
                int val = b[mx.top().second];
                result -= get(stmn[val], stmx[val].back().left, stmx[val].back().right);
                stmx[val].pop_back();
                mx.pop();
            }
            {
                int val = b[i];
                auto& s = stmx[val];
                int st = mx.top().second + 1;
                int fn = i;
                s.push_back({st, fn, s.back().sum + fn - st + 1});
                result += get(stmn[val], st, fn);
                mx.push({a[i], i});
            }

            while (mn.top().first > a[i]) {
                int val = b[mn.top().second];
                result -= get(stmx[val], stmn[val].back().left, stmn[val].back().right);
                stmn[val].pop_back();
                mn.pop();
            }
            {
                int val = b[i];
                auto& s = stmn[val];
                int st = mn.top().second + 1;
                int fn = i;
                s.push_back({st, fn, s.back().sum + fn - st + 1});
                result += get(stmx[val], st, fn);
                mn.push({a[i], i});
            }
            answer += result;
        }

        cout << answer << nl;
    }


#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}