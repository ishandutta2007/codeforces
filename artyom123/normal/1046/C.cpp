#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define INF 1000000
#define EPS 1e-4
#define MAXN int(1e6)
#define int ll

//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

inline void Routine(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

template<class T, class U>
istream &operator >> (istream &in, pair<T, U> &p) {
    in >> p.fi >> p.se;
    return in;
}

template<class T, class U>
ostream &operator << (ostream &out, const pair<T, U> &p) {
    out << p.fi << ' ' << p.se;
    return out;
}

template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}

signed main() {
    Routine();
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    cin >> a;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.emplace(-x);
    }
    int temp = a[d - 1] - *s.begin();
    s.erase(s.begin());
    int ans = d;
    for (int i = d - 2; i >= 0; i--) {
        auto it = s.lower_bound(a[i] - temp);
        if (it != s.end()) {
            s.erase(it);
            ans--;
        }
    }
    cout << ans;
    return 0;
}