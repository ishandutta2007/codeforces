#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define abs(x) (x > 0 ? x : -x)
  
using namespace std;
  
int main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int mn = 0, mx = 0;
    for (int i = 5; i <= n; i += 5) {
        if (i + 2 <= n) {
            i += 2;
            mn += 2;
        } else {
            if (i + 1 <= n) {
                i += 1;
                mn += 1;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i <= n; i += 5) {
        if (i + 2 <= n) {
            i += 2;
            mx += 2;
        } else {
            if (i + 1 <= n) {
                i += 1;
                mx += 1;
            } else {
                break;
            }
        }
    }
    cout << mn << " " << mx << endl;
}