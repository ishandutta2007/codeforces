#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int n;
    cin >> n;
    int a[n], l[n], r[n];
    fop (i,0,n) cin >> a[i];
    fop (i,0,n) {
        l[i] = 1;
        r[i] = 1;
    }
    fop (i,n-1,0) {
        if (a[i] < a[i+1]) l[i] = l[i+1] + 1;
    }
    fop (i,1,n) {
        if (a[i-1] < a[i]) r[i] = r[i-1] + 1;
    }
    int ans = *max_element(l,l+n);
    fop (i,1,n-1) {
        if (a[i-1] < a[i+1]) ans = max(ans, r[i-1] + l[i+1]);
    }
    cout << ans << endl;
}