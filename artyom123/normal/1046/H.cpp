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
    int n;
    cin >> n;
    map<vector<bool>, int> m;
    vector<bool> temp(26);
    for (int i = 0; i < n; i++) {
        temp.assign(26, 0);
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            temp[s[j] - 'a'].flip();
        }
        m[temp]++;
    }
    int ans = 0;
    for (auto &c : m) {
        temp = c.fi;
        ans += (c.se) * (c.se - 1);
        for (int i = 0; i < 26; i++) {
            temp[i].flip();
            if (m.find(temp) != m.end()) {
                ans += m[temp] * c.se;
            }
            temp[i].flip();
        }
    }
    cout << ans / 2;
    return 0;
}