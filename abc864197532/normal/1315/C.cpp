#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, tmp;
        cin >> n;
        int a[2*n];
        bool ss[2*n+1];
        fop (i,0,2*n) a[i] = -1;
        fop (i,0,2*n+1) ss[i] = false;
        fop (i,0,n) {
            cin >> a[i*2];
            ss[a[i*2]] = true;
        }
        bool is = false;
        for (int i = 0; i < 2 * n; i += 2) {
            bool is1 = true;
            fop (j,a[i]+1,2 * n + 1) {
                if (!ss[j]) {
                    a[i+1] = j;
                    ss[j] = true;
                    is1 = false;
                    break;
                }
            }
            if (is1) {
                is = true;
                break;
            }
        }
        if (!is) {
            for (int i : a) cout << i << ' ';
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}