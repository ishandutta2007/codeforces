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
    int t;
    cin >> t;
    while (t--) {
        int n, tmp;
        cin >> n;
        int a[n];
        fop (i,0,n) cin >> a[i];
        fop (i,0,n) {
            cin >> tmp;
            a[i] = tmp - a[i];
        }
        bool is = true, ok = true;
        int k = 0;
        fop (i,0,n) {
            if (a[i] < 0) {
                cout << "NO" << endl;
                ok = false;
                break;
            } else if (is and a[i] > 0) {
                k = a[i];
                is = false;
            } else if (!is) {
                if (k != a[i] and a[i] != 0) {
                    cout << "NO" << endl;
                    ok = false;
                    break;
                }
                k = a[i];
            } 
        }
        if (ok) cout << "YES" << endl;
    }
}