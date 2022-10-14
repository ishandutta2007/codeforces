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
const int mod = 1e9 + 7, abc = 864197532, N = 10100101, logN = 17, K = 333, INF = 5e8;

int ask(int l, int r) {
    assert(r - l > 1);
    cout << "? " << l + 1 << ' ' << r << endl;
    cin >> l;
    return --l;
}

bool ask2(int l, int r, int p, int n) {
    int mid = l + r >> 1;
    if (p < mid) {
        int now = ask((l <= p ? l : 0), mid);
        return now != p;
    } else {
        int now = ask(mid, (p < r ? r : n));
        return now == p;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p = ask(0, n);
    int l = 0, r = n;
    while (r - l > 3) {
        int mid = l + r >> 1;
        if (ask2(l, r, p, n)) l = mid;
        else r = mid;
    }
    if (r - l == 2) {
        int now = ask(l, r);
        if (now == l) cout << "! " << r << endl;
        else cout << "! " << l + 1 << endl;
    } else {
        int now = ask(l, r), now2 = ask(l + 1, r), ans;
        if (now == l) {
            ans = (now2 == l + 1 ? l + 2 : l + 1);
        } else if (now == l + 1) {
            ans = (now2 == l + 1 ? l + 2 : l);
        } else if (now == l + 2) {
            ans = (now2 == l + 1 ? l : l + 1);
        }
        cout << "! " << ans + 1 << endl;
    }
}