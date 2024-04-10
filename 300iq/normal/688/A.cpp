#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = 107;
int cnt[MAXN];
 
int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, d;
    cin >> n >> d;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '0') {
                cnt[i]++;
            }
        }
        if (cnt[i] > 0) {
            cur++;
        } else {
            cur = 0;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}