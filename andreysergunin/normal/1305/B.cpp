// #pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    while (tests--) {
       solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> res[2];
    vector<int> pos[2];
    for (int i = 0; i < n; ++i) {
        pos[s[i] == ')'].push_back(i);
    }   

    for (int i = 0, j = sz(pos[1]) - 1; i < sz(pos[0]) && j >= 0; ++i, --j) {
        if (pos[0][i] < pos[1][j]) {
            res[0].push_back(pos[0][i]);
            res[1].push_back(pos[1][j]);
        }
    }
    if (sz(res[0]) == 0) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << sz(res[0]) * 2 << endl;;
    reverse(all(res[1]));
    for (int x = 0; x < 2; ++x) {
        for (int el : res[x]) {
            cout << el + 1 << " ";
        }
    }
    cout << endl;


}