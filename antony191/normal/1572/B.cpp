#include <bits/stdc++.h>
//#include <iostream>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

const char el = '\n';
const int inf = 1000'000'000, mod = 1000000007, mod2 = 998244353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
//#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
//#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
mt19937_64 rnd_64(time(nullptr));

vector<int> ans;
bool solve(int l, int r, vector<int> &a) {
    if (r - l < 5) {
        if (r - l == 1 || r - l == 0) {
            return true;
        }
        if (r - l == 2) {
            ans.push_back(l);
            return true;
        }
        if (r - l == 3) {
            ans.push_back(l + 1);
            return true;
        }
        if (r - l == 4) {
            int t = a[l] ^ a[l + 1] ^ a[l + 2];
            if (t == 0) {
                ans.push_back(l + 1);
                return true;
            }
            if (a[l] == 0) {
                ans.push_back(l + 2);
                return true;
            }
            if (a[l + 3] == 0) {
                ans.push_back(l + 1);
                return true;
            }
            if (l == 0) return false;
            ans.push_back(l + 1);
            ans.push_back(l);
            ans.push_back(l + 2);
            return true;
        }
    }
    if (a[l] == 0) {
        return solve(l + 1, r, a);
    }
    int t = a[l] ^ a[l + 1] ^ a[l + 2];
    if (t == 0) {
        ans.push_back(l + 1);
        return solve(l + 3, r, a);
    }
    if (a[l + 1]) {
        if (l > 0) {
            ans.push_back(l);
            return solve(l + 2, r, a);
        }
        int i = l;
        while(i < r && a[i]) i++;
        if (i == r) return false;
        if (!((i - l) & 1)) {
            for (int j = i - 2; j >= l; j -= 2) {
                ans.push_back(j + 1);
            }
            return solve(i + 1, r, a);
        }
        for (int j = i - 1; j + 3 <= r; j += 2) {
            t = a[j] ^ a[j + 1] ^ a[j + 2];
            ans.push_back(j + 1);
            if (t == 1) {
                a[j] = a[j + 1] = a[j + 2] = 1;
                continue;
            }
            a[j] = a[j + 1] = a[j + 2] = 0;
            int k = j - 2;
            while(k >= l) {
                ans.push_back(k + 1);
                k -= 2;
            }
            return solve(j + 3, r, a);
        }
        return false;
    }
    for (int j = l; j + 3 <= r; j += 2) {
        t = a[j] ^ a[j + 1] ^ a[j + 2];
        if (t) {
            ans.push_back(j + 1);
            a[j] = a[j + 1] = a[j + 2] = 1;
            continue;
        }
        ans.push_back(j + 1);
        a[j] = a[j + 1] = a[j + 2] = 0;
        int k = j - 2;
        while(k >= l) {
            ans.push_back(k + 1);
            k -= 2;
        }
        return solve(j + 3, r, a);
    }
    if (l == 0) return false;
    for (int j = l - 1; j + 3 <= r; j += 2) {
        ans.push_back(j + 1);
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        forn(i, n) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == n || (sum & 1)) {
            cout << "NO" << el;
            continue;
        }
        ans.clear();
        bool t = solve(0, n, a);
        if (t) {
            cout << "YES" << el;
            cout << (int)ans.size() << el;
            output(ans);
        } else {
            cout << "NO" << el;
        }
    }
    return 0;
}