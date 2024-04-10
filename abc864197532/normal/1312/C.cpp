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
#define endl '\n'

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        lli tmp;
        int a[65];
        fop (i,0,65) a[i] = 0;
        fop (i,0,n) {
            cin >> tmp;
            int count = 0;
            while (tmp > 0) {
                a[count] += tmp % k;
                tmp /= k;
                count++;
            }
        }
        bool is = true;
        fop (i,0,65) {
            if (a[i] > 1) {
                is = false;
            }
        }
        if (is) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}