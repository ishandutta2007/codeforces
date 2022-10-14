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
        int n,a,sum=0;
        cin >> n;
        fop (i,0,n) {
            cin >> a;
            if (a<=2048) sum+=a;
        }
        if (sum>=2048) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}