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
const int mod = 1e9 + 7, abc = 864197532, N = 100005, logN = 20, K = 333;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (s[n - 2] == '0' && s[n - 1] == '0') {
        cout << 0 << endl;
        return 0;
    }
    auto chk = [&](string s) {
        return s[0] != '0';
    };
    auto chkk = [&](string s) {
        if (s[n - 2] == '0' && s[n - 1] == '0') return true;
        if (s[n - 2] == '2' && s[n - 1] == '5') return true;
        if (s[n - 2] == '5' && s[n - 1] == '0') return true;
        if (s[n - 2] == '7' && s[n - 1] == '5') return true;
        return false;
    };
    int ans = 1000;
    for (int i = 0; i < n; ++i) {
        string tmp = s;
        int cans = 0;
        if (!i) {
            for (int i = 1; i < n; ++i) {
                if (tmp[i] != '0') break;
                cans++;
            }
            for (int i = cans + 1; i > 1; --i) swap(tmp[i], tmp[i - 1]);
        }
        for (int k = i; k < n - 1; ++k) swap(tmp[k], tmp[k + 1]), cans++;
        for (int j = 0; j < n - 1; ++j) {
            string tmpp = tmp;
            int tans = 0;
            if (!j) {
                for (int i = 1; i < n - 1; ++i) {
                    if (tmpp[i] != '0') break;
                    tans++;
                }
                for (int i = tans + 1; i > 1; --i) swap(tmpp[i], tmpp[i - 1]);
            }
            for (int k = j; k < n - 2; ++k) swap(tmpp[k], tmpp[k + 1]), tans++;
            if (chkk(tmpp)) ans = min(ans, cans + tans);
        }
    }
    cout << (ans == 1000 ? -1 : ans) << endl;
}