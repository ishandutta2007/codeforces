#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 3000005, logN = 20, K = 333;

vector <int> f[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i < N; ++i) if (f[i].empty()) {
        for (int j = i; j < N; j += i) f[j].pb(i);
    }
    int n, i, x;
    cin >> n;
    bool larger = false;
    vector <int> is(N, false);
    for (i = 0; i < n; ++i) {
        cin >> x;
        for (int j : f[x]) {
            if (is[j]) larger = true;
        }
        if (larger) {
            for (int j = x; ; ++j) {
                bool ok = false;
                for (int k : f[j]) ok |= is[k];
                if (!ok) {
                    cout << j << ' ';
                    for (int k : f[j]) is[k] = true;
                    break;
                }
            }
            break;
        }
        cout << x << ' ';
        for (int j : f[x]) is[j] = true;
    }
    for (int j = 2; i < n - 1; ++i, ++j) {
        while (true) {
            bool ok = false;
            for (int k : f[j]) ok |= is[k];
            if (!ok) break;
            j++;
        }
        cout << j << ' ';
        for (int k : f[j]) is[k] = true;
    }
}