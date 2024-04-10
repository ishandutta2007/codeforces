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
const int mod = 1e9 + 7, abc = 864197532, N = 100001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int sum, n;
    cin >> sum >> n;
    if (sum < 1ll * n * (n + 1) / 2) {
        cout << "NO\n";
        return 0;
    }
    sum -= n * (n + 1) / 2;
    vector <int> ans(n);
    iota(all(ans), 1);
    if (sum != n - 1) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            ans[i] += sum / n + (n - i - 1 < sum % n);
        }
        printv(ans);
    } else {
        if (n == 1) {
            cout << "YES\n1\n";
        } else if (n == 2 || n == 3) {
            cout << "NO\n";
        } else {
            for (int i = 2; i < n; ++i) {
                ans[i]++;
            }
            ans[n - 1]++;
            cout << "YES\n";
            printv(ans);
        }
    }
}