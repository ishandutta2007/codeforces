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
    int n;
    cin >> n;
    int a[n];
    fop (i,0,n) cin >> a[i];
    fop (i,0,n) {
        fop (j,0,n) {
            if (j & 1) {
                a[j]++;
                if (a[j] == n) a[j] = 0;
            } else {
                a[j]--;
                if (a[j] < 0) a[j] += n;
            }
        }
        bool is = true;
        fop (j,0,n) {
            if (a[j] != j) is = false;
        }
        if (is) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}