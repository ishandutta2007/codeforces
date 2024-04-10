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
    long long sum = 0;
    int a[n];
    fop (i,0,n) {
        cin >> a[i];
        sum += 1ll * a[i];
    }
    sort(a,a+n);
    if (n < 3) {
        sum -= (1ll * n * (n - 1) / 2);
        if (sum & 1 and sum >= 0) cout << "sjfnb" << endl;
        else cout << "cslnb" << endl;
        return 0;
    }
    fop (i,1,n-1) {
        if (a[i] == 0) {
            cout << "cslnb" << endl;
            return 0;
        } if (a[i] == a[i+1] and a[i] - a[i-1] <= 1) {
            cout << "cslnb" << endl;
            return 0;
        }
    }
    int tmp = unique(a,a+n) - a;
    if (tmp <= n - 2) {
        cout << "cslnb" << endl;
        return 0;
    }
    sum -= (1ll * n * (n - 1) / 2);
    if (sum & 1) cout << "sjfnb" << endl;
    else cout << "cslnb" << endl;
    return 0;
}