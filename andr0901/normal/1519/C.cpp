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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> skills(n);
    vector<int> unis(n);
    cin >> unis;
    forn (i, 0, n) {
        int skill;
        cin >> skill;
        skills[unis[i] - 1].push_back(skill);
    }
    vector<int> sizes_used;
    vector<vector<long long>> sum_by_size(n + 1);
    forn (i, 0, n) {
        sort(rall(skills[i]));
        int sz = skills[i].size();
        if (sz == 0) {
            continue;
        }
        sizes_used.push_back(sz);
        if (sum_by_size[sz].empty()) {
            sum_by_size[sz].resize(sz);
        }
        forn (j, 0, sz) {
            sum_by_size[sz][j] += skills[i][j];
        }
    }
    sort(all(sizes_used));
    sizes_used.erase(unique(all(sizes_used)), sizes_used.end());
    vector<vector<long long>> pref_sums(n + 1);
    forn (i, 1, n + 1) {
        if (!sum_by_size[i].empty()) {
            pref_sums[i].resize(i + 1);
            forn (j, 0, i) {
                pref_sums[i][j + 1] = pref_sums[i][j] + sum_by_size[i][j];
            }
        }
    }
    forn (i, 1, n + 1) {
        long long ans = 0;
        for (int k : sizes_used) {
            int sz = k / i * i;
            cerr << i << " " << k << " " << sz << " " << pref_sums[k][sz] << "\n";
            ans += pref_sums[k][sz];
        }
        cerr << "\n";
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}