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
const int mod = 1e9 + 7, abc = 864197532, N = 200005, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> cnt(N, 0);
    for (int i = 0, x; i < n; ++i) cin >> x, cnt[x]++;
    int curans = -1, l = -1, r = -1;
    for (int i = 1, j = 1; i + 1 < N; i = ++j) {
        while (cnt[j] >= 2) j++;
        int al = 0;
        for (int k = i; k < j; ++k) {
            al += cnt[k];
        }
        int L = i, R = j;
        if (cnt[i - 1]) L--, al += cnt[i - 1];
        if (cnt[j]) R++, al += cnt[j];
        if (curans < al) {
            curans = al;
            l = L, r = R;
        }
    }
    cout << curans << endl;
    for (int i = l; i < r; ++i) {
        cout << i << ' ';
        cnt[i]--;
    }
    for (int i = r - 1; i >= l; --i) {
        while (cnt[i]--) cout << i << ' ';
    }
    cout << endl;
}