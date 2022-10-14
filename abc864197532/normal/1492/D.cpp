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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    if (a == 0) {
        if (k == 0) {
            cout << "Yes\n" << string(b, '1') << endl << string(b, '1') << endl;
        } else {
            cout << "No\n";
        }
    } else if (b == 1) {
        if (k == 0) {
            cout << "Yes\n" << 1 << string(a, '0') << endl << 1 << string(a, '0') << endl;
        } else {
            cout << "No\n";
        }
    } else {
        if (k <= a + b - 2) {
            string ansa(a + b, '0'), ansb(a + b, '0');
            ansa[0] = ansb[0] = '1';
            ansa[1] = '1';
            ansb[1 + k] = '1';
            for (int i = 2; i < ansa.size() && b > 2; i++) {
                if (ansa[i] == '0' && ansb[i] == '0') {
                    b--;
                    ansa[i] = ansb[i] = '1';
                }
            }
            cout << "Yes\n" << ansa << endl << ansb << endl;
        } else {
            cout << "No\n";
        }
    }
}