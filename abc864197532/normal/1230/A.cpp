#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
 
 
int main () {
    int a[4];
    fop (i,0,4) cin >> a[i];
    fop (i,0,16) {
        int sum=0;
        fop (j,0,4) {
            if (i&(1<<j)) sum+=a[j];
            else sum-=a[j];
        }
        if (sum==0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}