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

int main () {
    int n, tmp;
    cin >> n;
    int a[n];
    fop (i,0,n) {
        cin >> tmp;
        a[tmp-1] = i + 1;
    }
    int r = 0;
    int ans[n];
    fop (i,0,n) {
        cin >> tmp;
        ans[i] = max(a[tmp-1] - r, 0);
        r = max(r, a[tmp-1]);
    }
    fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}