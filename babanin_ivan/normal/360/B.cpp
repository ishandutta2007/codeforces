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

int n, k;
vector <int> a;
int dp[2100][2100];

bool check(int r) {
    memset(dp, 0, sizeof(dp));

    dp[1][0] = 2;
    dp[1][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int tmp = dp[i][j];
            if (tmp == 0) 
                continue;
            //--tmp;
            if (tmp <= k) {
                if (dp[i + 1][j] == 0 || dp[i + 1][j] > tmp + 1) {
                    dp[i + 1][j] = tmp + 1;
                }
            }

            if (j == 0) {
                dp[i + 1][i + 1] = i + 1;
            }
            else {
                bool f = false;
                int x = a[i + 1 - 1];
                int y = a[j - 1];
                int d = i + 1 - j - 1;
                if (x > y)
                    swap(x, y);
                if (y - x <= r)
                    f = true;
                else {
                    int diff = y - x;
                    if (d * r >= diff - r)
                        f = true;
                }

                if (f) {
                    if (dp[i + 1][i + 1] == 0 || dp[i + 1][i + 1] > dp[i][j]) {
                        dp[i + 1][i + 1] = dp[i][j];
                    }
                }
            }
        }
    }
    for (int i = 0; i <= n; ++i)
        if (dp[n][i])
            return true;
    return false;
}

void solve() {
    cin >> n >> k;
    if (n == 1) {
        cout << 0 << endl;
        return ;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i)
        r = max(r, abs(a[i] - a[i - 1]));
    if (k == 0) {
        cout << r << endl;
        return ;
    }
    while (r - l > 2) {
        int m = int((int64(l) + int64(r)) / 2LL);
        bool f = check(m);
        if (f)
            r = m;
        else l = m + 1;
    }
    for (int i = l; i <= r; ++i)
        if (check(i)) {
            cout << i << endl;
            return ;
        }
}