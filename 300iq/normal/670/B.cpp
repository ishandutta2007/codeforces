#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define int ll
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(x) (x > 0 ? x : -x)
  
using namespace std;
  
main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> id(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> id[i];
    }
    int say = 0;
    int cur = 1;
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        say += cur;
        if (say >= k) {
            for (int i = prev; i <= say; i++) {
                if (i == k) {
                    cout << id[i - prev] << endl;
                    return 0;
                }
            }
        }
        cur++;
        prev = say;
    }
}