#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
const int mod = 1e9 + 7, abc = 864197532, N = 100008, logN = 17, K = 333;

int n;

int ask(int x) {
    if (x == -1 || x == n) return 1 << 30;
    cout << "? " << x + 1 << endl;
    cin >> x;
    return x;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = l + r >> 1;
        int a[3] = {ask(mid - 1), ask(mid), ask(mid + 1)};
        if (a[1] < min(a[0], a[2])) {
            cout << "! " << mid + 1 << endl;
            return 0;
        }
        if (a[0] < a[1] && a[1] < a[2]) r = mid;
        else l = mid;
    }
    cout << "! " << l + 1 << endl;
}