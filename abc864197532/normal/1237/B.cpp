#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 



int main () {
    int n, tmp;
    cin >> n;
    vector <int> a(n), b(n);
    fop (i,0,n) cin >> a[i];
    fop (i,0,n) cin >> b[i];
    int ans=0;
    set <int> nums;
    int now=n-1;
    fop (i,n,0) {
        if (a[i] == b[now]) {
            now--;
        } else {
            nums.insert(a[i]);
            ans++;
        }
        while (nums.count(b[now])) now--;
    }
    cout << ans << endl;
}