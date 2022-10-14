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
const int mod = 1e9 + 7, abc = 864197532, N = 51, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    deque <int> mn, mx;
    auto del = [&](int i) {
        if (mn.front() < i) mn.pop_front();
        if (mx.front() < i) mx.pop_front();
    };
    auto add = [&](int i) {
        while (!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
        while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
        mn.push_back(i);
        mx.push_back(i);
    };
    int len = 1;
    vector <int> pos;
    for (int i = 0, j = 0; i <= n; ++i) {
        while (!mn.empty() && !mx.empty() && a[mx.front()] - a[mn.front()] > k) {
            del(++j);
        }
        if (len < i - j) pos.assign(1, j), len = i - j;
        else if (len == i - j) pos.pb(j);
        if (i == n) break;
        add(i);
    }
    cout << len << ' ' << pos.size() << endl;
    for (int i : pos) cout << i + 1 << ' ' << i + len << endl;
}