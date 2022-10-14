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
const int mod = 1e9 + 7, abc = 864197532, N = 200001, K = 111, logN = 18;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <lli> a(n);
    lli sum = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    if (sum % n != 0) {
        cout << 0 << endl;
        return 0;
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > sum / n) cnt0++;
        else if (a[i] < sum / n) cnt1++;
    }
    if (cnt0 <= 1 || cnt1 <= 1) {
        lli ans = 1;
        sort(all(a));
        for (int i = 1; i <= n; ++i) ans = ans * i % mod;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[j] == a[i]) j++;
            for (int k = 1; k <= j - i; ++k) ans = ans * modpow(k, mod - 2) % mod;
        }
        cout << ans << endl;
        return 0;
    }
    lli ans = 1;
    for (int i = 1; i <= n; ++i) ans = ans * i % mod;
    for (int i = 1; i <= cnt0 + cnt1; ++i) ans = ans * modpow(i, mod - 2) % mod;
    for (int i = 1; i <= n - cnt0 - cnt1; ++i) ans = ans * modpow(i, mod - 2) % mod;
    ans = ans * 2 % mod;
    {
        map <int, int> m1;
        int cnt = 1;
        for (int i = 0; i < n; ++i) if (a[i] < sum / n) {
                m1[a[i]]++;
                ans = ans * (cnt++) % mod;
            }
        for (pii A : m1) {
            for (int i = 1; i <= A.Y; ++i) ans = ans * modpow(i, mod - 2) % mod;
        }
    }
    {
        map <int, int> m1;
        int cnt = 1;
        for (int i = 0; i < n; ++i) if (a[i] > sum / n) {
            m1[a[i]]++;
            ans = ans * (cnt++) % mod;
        }
        for (pii A : m1) {
            for (int i = 1; i <= A.Y; ++i) ans = ans * modpow(i, mod - 2) % mod;
        }
    }
    cout << ans << endl;
    /*
     * 1 3 -2 -2
     * 1 2 -1 -2
     * 1 2 3 -3 -2 -1
     */
    /*
     * - - - - - - + + + + + + + +
     */
}

/*
 * |a_i - b_i| - |a_i - b_j| + |a_j - b_j| - |a_j - b_i|
 *
 */