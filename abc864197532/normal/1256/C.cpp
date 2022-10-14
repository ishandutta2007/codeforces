#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
 
int main () {
    int n, m, d;
    cin >> n >> m >> d;
    int a[m], now = n;
    fop (i,0,m) {
        cin >> a[i];
        now -= a[i];
    }
    if (now > (d - 1) * (m + 1)) {
        cout << "NO" << endl;
    } else {
        int k = 0, b = 0;
        cout << "YES" << endl;
        while (b < n) {
            fop (i,0,d-1) {
                if (!now) break;
                now--;
                b++;
                cout << 0 << ' ';
            }
            if (k == m) break;
            fop (i,0,a[k]) {
                cout << k + 1 << ' ';
                b++;
            }
            k++;
        }
        cout << endl;
    }
}