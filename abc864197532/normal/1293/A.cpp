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
    int t;
    cin >> t;
    while (t--) {
        int n,x,k,tmp;
        set <int> ss;
        cin >> n >> x >> k;
        fop (i,0,k) {
            cin >> tmp;
            ss.insert(tmp);
        }
        int now = 0, now2 = 0;
        while (ss.count(x + now)) now++;
        while (ss.count(x - now2)) now2++;
        if (x + now > n) now = 10000;
        if (x - now2 < 1) now2 = 10000;
        cout << min(now, now2) << endl;
    }
}