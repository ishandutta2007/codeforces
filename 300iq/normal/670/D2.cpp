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

vector <int> a(100000), b(100000);
int n, k;

bool check(int x) {
    long double d = k;
    for (int i = 0; i < n; i++) {
        if (a[i] / b[i] < x) {
            long double need = x - a[i] / b[i];
            d -= b[i] - (a[i] % b[i]);
            need--;
            if (need > 0) {
                d -= need * b[i];
            }   
        }
    }
    return (d >= 0);
}
  
main() {
    ios_base::sync_with_stdio(0);
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int x, m;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0;
    int r = 2000000000 + 7;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
}