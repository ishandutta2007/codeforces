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

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 2, 201);
    forn (i, 1, n + 1) {
        cin >> a[i];
        a[i] -= 1;
    }
    int k = 201;
    int ans = 0;
    forn (i, 0, k) {
        int p = 0, s = n + 1;
        vector <int> cnt(k);
        forn (j, 1, n + 1)
            cnt[a[j]]++;
        int cnt_p = 0, cnt_s = 0;
        forn (j, 0, n + 1) {
            while (p < n + 1 && cnt_p < j) {
                ++p;
                cnt[a[p]]--;
                cnt_p += (a[p] == i);
            }
            while (s > 0 && cnt_s < j) {
                --s;
                cnt[a[s]]--;
                cnt_s += (a[s] == i);
            }
            if (p >= s || p == n + 1 || s == 0)
                break;
            else {
                /*cout << i << " " << j << " " << p << " " << s << " " << *max_element(all(cnt)) << "\n";
                forn (t, 0, 3)
                    cout << cnt[t] << " ";
                cout << "\n";*/
                int mx = 0;
                forn (l, 0, 200)
                    chkmax(mx, cnt[l]);
                chkmax(ans, 2 * j + mx);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}