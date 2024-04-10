#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200001, logN = 17;

struct seg {
    int x, y, id;
    bool operator < (const seg& o) {
        if (y == o.y) return x > o.x;
        return y < o.y;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <seg> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].x >> v[i].y, v[i].id = i + 1;
    sort(all(v));
    set <pii> s;
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound({v[i].x, -1});
        if (it != s.end()) {
            cout << it->Y << ' ' << v[i].id << endl;
            return 0;
        }
        s.insert({v[i].x, v[i].id});
    }
    cout << "-1 -1\n";
}