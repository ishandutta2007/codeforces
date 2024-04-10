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
    int n, k;
    cin >> n >> k;
    lli a[n];
    lli summ = 0;
    fop (i,0,n) cin >> a[i];
    sort(a, a+n);
    fop (i,0,n) {
        if (i >= k) a[i] += a[i - k];
        summ += 1ll * a[i];
        cout << summ << " \n"[i == n - 1];
    }
}