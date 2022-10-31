#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

long long get(int x) {
    return 1LL * x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    long long x;
    cin >> n >> x;
    vector <int> a(n);
    cin >> a;
    forn (i, 0, n)
        a.pb(a[i]);
    /*long long s = 0;
    int j;
    for (int i = n - 1; i >= 0; --i) {
        if (s + a[i] <= x)
            s += a[i];
        else {
            j = i;
            break;
        }
    }*/
    long long s = 0, hugs = 0;
    forn (i, 0, n) {
        s += a[i];
        hugs += get(a[i]);
    }
    int j = 0;
    long long ans = 0;
    forn (i, n, 2 * n) {
        s += a[i];
        hugs += get(a[i]);
        while (s >= x) {
            s -= a[j];
            hugs -= get(a[j]);
            ++j;
        }
        long long rest = x - s;
        //cout << j << " " << s << " " << hugs << " " << rest <<"\n";
        chkmax(ans, hugs + get(a[j - 1]) - get(a[j - 1] - rest));
    }
    cout << ans;
    return 0;
}