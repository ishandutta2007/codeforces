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
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        fop (i,0,n) cin >> a[i] >> b[i];
        bool is = true;
        int pre1 = 0, pre2 = 0;
        fop (i,0,n) {
            if (pre1 > a[i] or pre2 > b[i]) is = false;
            if (a[i] - pre1 < b[i] - pre2) is = false;
            pre1 = a[i], pre2 = b[i];
        }
        cout << (is ? "Yes" : "No") << endl;
    }
}