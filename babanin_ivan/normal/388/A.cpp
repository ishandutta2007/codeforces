#include <iostream> 
#include <cstdio> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
//#include <unordered_set> 
using namespace std;
typedef long long int64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back 
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    while (t--)
        solve();

#ifdef YA 
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

int a[200];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];            
    }
    sort(a, a + n);
    reverse(a, a + n);

    int ans = 0;
    for (ans = 1; ans <= n; ++ans) {
        vector <int> res;
        res.resize(ans);
        int pos = 0;
        
        int cursum = 0;

        for (int i = 0; i < ans; ++i) {
            res[i] = a[i];
            cursum += a[i];
        }
        
        int rest = n - ans;

        bool f = true;

        if (cursum < rest)
            continue;

        pos = ans;
        
        for (int i = ans; i < n; ++i) {
            sort(res.begin(), res.end());
            reverse(res.begin(), res.end());

            int best = 1000000;
            int pos = 0;
            for (int j = 0; j < res.size(); ++j) {
                if (res[j]) {
                    best = min(best, res[j] - min(res[j] - 1, a[i]));
                    if (best < res[j] - min(res[j] - 1, a[i])) {
                        pos = j;
                    }
                }
            }
            cursum -= best;
            --rest;
            if (cursum < rest) {
                f = false;
                break;
            }
            res[pos] = min(res[pos] - 1, a[i]);
        }
        if (f)
            break;
    }
    cout << ans << endl;
}