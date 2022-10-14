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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 250001, logN = 18;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return a[i] < a[j];
    });
    set <vector <int>> ans;
    vector <pii> range;
    int cnt = 1;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && a[p[i]] == a[p[j]]) j++;
        if (j - i > 1) range.eb(i, j);
        cnt = cnt * (j - i);
        if (cnt >= 3) cnt = 3;
    }
    if (cnt < 3) cout << "NO\n";
    else {
        while (ans.size() < 3) {
            for (pii A : range) {
                random_shuffle(p.begin() + A.X, p.begin() + A.Y);
            }
            ans.insert(p);
        }
        cout << "YES\n";
        for (auto i : ans) {
            for (int j : i) cout << j + 1 << ' ';
            cout << endl;
        }
    }
}