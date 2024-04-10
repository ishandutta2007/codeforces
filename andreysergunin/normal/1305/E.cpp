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
    int n, m;
    cin >> n >> m;  

    int cnt = 0;
    vector<int> arr;

    for (int i = 1; i <= n; ++i) {
        if (cnt + (i - 1) / 2 <= m) {
            arr.push_back(i);
            cnt += (i - 1) / 2;
        } else {
            int k = m - cnt;
            if (k == 0) {
                break;
            }
            int val = i;
            while (true) {
                if (k == i - 1 - val / 2) {
                    arr.push_back(val);
                    cnt = m;
                    break;
                }
                ++val;
            }
            break;
        }
    }

    if (cnt != m) {
        cout << - 1 << endl;
        return;
    }


    int cur = 1e9;
    while (sz(arr) < n) {
        arr.push_back(cur);
        cur -= 2e4;
    }
    sort(all(arr));

    for (int el : arr) {
        cout << el << " ";
    }
    cout << endl;
}