#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n];
        fop (i,0,n) cin >> x[i];
        sort (x,x+n);
        bool is=true;
        fop (i,0,n-1) {
            if (x[i]-x[i+1]==-1) {
                 cout << 2 << endl;
                 is=false;
                 break;
            }
        }
        if (is) cout << 1 << endl;
    }
}