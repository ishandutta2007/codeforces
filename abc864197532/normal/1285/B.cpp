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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        lli now = 0;
        cin >> n;
        int a[n];
        bool is = true;
        fop (i,0,n) cin >> a[i];
        fop (i,0,n) {
            now += a[i];
            if (now <= 0) is = false;
        }
        now = 0;
        FOP (i,n,0) {
            now += a[i];
            if (now <= 0) is = false;
        }
        if (is) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}