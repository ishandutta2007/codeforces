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

array <int, 3> n;
vector <vector <int>> a;
vector <vector <vector <int>>> dp;

int solve(array <int, 3> cur) {
    cerr << cur[0] << " " << cur[1] << " " << cur[2] << "\n";
    if (dp[cur[0]][cur[1]][cur[2]] != -1)
        return dp[cur[0]][cur[1]][cur[2]];
    dp[cur[0]][cur[1]][cur[2]] = 0;
    forn (i, 0, 3) {
        array <int, 3> nxt;
        forn (j, 0, 3)
            nxt[j] = cur[j] + 1;
        nxt[i]--;
        bool ok = true;
        forn (j, 0, 3)
            if (i != j && nxt[j] > n[j])
                ok = false;
        int profit = 1;
        forn (j, 0, 3)
            if (i != j)
                profit *= a[j][cur[j]];
        if (ok)
            chkmax(dp[cur[0]][cur[1]][cur[2]],
                   solve(nxt) + profit);
    }
    return dp[cur[0]][cur[1]][cur[2]];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    forn (i, 0, 3)
        cin >> n[i];
    a.resize(3);
    forn (i, 0, 3) {
        a[i].resize(n[i]);
        cin >> a[i];
        sort(rall(a[i]));
    }
    dp = vector <vector <vector <int>>> (n[0] + 1, vector <vector <int>> (n[1] + 1, vector <int> (n[2] + 1, -1)));
    cout << solve({0, 0, 0});
    return 0;
}