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

void print(const vector<vector<int>>& ans) {
    int mx = 0;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            if (ans[i][j]) {
                mx = max(mx, i);
                mx = max(mx, j);
            }
        }
    }
    cout << mx + 1 << "\n";
    for (int k = mx; k >= 0; --k) {
        for (int l = 0; l <= mx; ++l) {
            cout << (ans[k][l] ? 'o' : '.');
        }
        cout << "\n";   
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    if (n == 2) {
        cout << "-1\n";
        return 0;
    }
    vector<vector<int>> ans(101, vector<int> (101));
    forn (iter, 0, 101) {
        if (n == iter * iter - 2) {
            forn (k, 0, iter - 2) {
                forn (l, 0, iter - 2) {
                    ans[k][l] = 1;
                }
            }
            int i = 0;
            int j = iter - 2;
            int filled = (iter - 2) * (iter - 2);
            while (filled < n) {
                ans[i][j] = ans[j][i] = 1;
                filled += 2;
                ++i;
                if (i == iter - 2) {
                    i = 0;
                    ++j;
                }
            }
            print(ans);
            return 0;
        }
    }
    int i = 0;
    int j = 0;
    int filled = 0;
    bool just_finished = false;
    while (filled < n) {
        cerr << i << " " << j << " " << filled << " " << "\n";
        just_finished = false;
        if (i == j) {
            ++filled;
            ans[i][j] = 1;
            ++j;
            i = 0;
            just_finished = true;
        } else {
            filled += 2;
            ans[i][j] = ans[j][i] = 1;
            ++i;
        }
    }
    if (filled != n) {
        ans[j - 1][j - 1] = 0;
        // ans[0][j + 1] = ans[j + 1][0] = 1;
    }
    if (just_finished) {
        --j;
    }
    print(ans);
    return 0;
}