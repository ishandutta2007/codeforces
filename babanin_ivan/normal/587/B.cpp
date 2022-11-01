#pragma comment (linker, "/STACK:128000000")
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

#define int li

const int mod = 1000000007;

li n, l, k;

void solve() {
    cin >> n >> l >> k;
    /*if ((l + n - 1) / n < k) {
        cout << 0 << endl;
        return;
    }*/
    /*
    if (l <= n) {
        cout << l << endl;
        return;
    }*/

    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector <int> b = a;

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    vector <int> cou(b.size());
    for (int i = 0; i < n; ++i) {
        ++cou[a[i]];
    }


    vector <vector <int>> dp(b.size(), vector <int>(k));
    for (int i = 0; i < b.size(); ++i) {
        dp[i][0] = cou[i];
    }

    

    for (int i = 0; i < k - 1; ++i) {
        vector <int> sums(b.size() + 1);
        sums[0] = 0;
        for (int j = 0; j < b.size(); ++j) {
            sums[j + 1] = (sums[j] + dp[j][i]) % mod;
            dp[j][i + 1] = (li(sums[j + 1]) * li(cou[j])) % mod;
        }
    }

    li ans = 0;


    for (int len = 1; len <= k; ++len) {
        if ((l + n - 1) / n < len) {
            continue;
        }

        li sumdp = 0;
        for (int i = 0; i < b.size(); ++i) {
            sumdp = (sumdp + dp[i][len - 1]) % mod;
        }

        if (l / n >= len) {
            ans = (ans + sumdp * ((l / n - len + 1) % mod)) % mod;
        }
        
        if (len == 1) {
            ans += (l % n);
            ans %= mod;
        }
        else {
            vector <int> sums(b.size() + 1);
            sums[0] = 0;
            for (int j = 0; j < b.size(); ++j) {
                sums[j + 1] = (sums[j] + dp[j][len - 2]) % mod;
            }

            for (int i = 0; i < (l % n); ++i) {
                ans += sums[a[i] + 1];
                ans %= mod;
            }
        }
    }

    cout << ans << endl;
}