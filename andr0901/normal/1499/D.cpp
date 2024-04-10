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

vector<int> cnt;

constexpr int N = 2e7 + 5;

// from emaxx
int lp[N+1];
vector<int> pr;
 
void find_lp() {
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void solve() {
    int c, d, x;
    cin >> c >> d >> x;
    long long ans = 0;
    auto check = [&](int g) {
        int x = g + d;
        if (x % c)
            return;
        x /= c;
        ans += cnt[x];
    };
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            check(x / i);
            if (i != x / i)
                check(i);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    find_lp();
    cnt.resize(N);
    cnt[1] = 1;
    forn (i, 2, N) {
        if (i / lp[i] % lp[i] == 0) {
            cnt[i] = cnt[i / lp[i]];
        } else {
            cnt[i] = 2 * cnt[i / lp[i]];
        }
    }
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}