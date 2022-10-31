//#pragma GCC optimize("Ofast")
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

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

int N = 29;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    int lst = 0, i = 2, p = 1;
    vector<tuple<int, int, int>> ans = {{1, N, 1}};
    while ((lst + 1) * 2 <= n) {
        for (int j = 1; j < i; ++j) {
            ans.eb(j, i, p);
        }
        ans.eb(i, N, 1);

        ++i;
        lst += p;
        p *= 2;
    }
    if (n & (n - 1)) {
        ans.eb(1, i, p);
        cerr << i << " " << p << " " << lst << "\n";
        int last = p + 2;
        int bit = 0;
        for (int j = 2; j < i; ++j) {
            int pow = (1 << j - 2) + 1;
            if (((n - 1) >> bit) & 1) {
                ans.eb(j, i, last - pow);
                last += pow - 1;
            }
            ++bit;
        }
        ans.eb(i, N, 1);
    }
    if (l > 1) {
        ++N;
        ans.eb(N - 1, N, l - 1);
    }

    cout << "YES\n" << N << " " << ans.size() << "\n";
    for (auto [v, u, w] : ans)
        cout << v << " " << u << " " << w << "\n";
    return 0;
}