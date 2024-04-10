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
        int a,b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        int n = sqrt(b-a);
        while (n * (n + 1) / 2 < b - a) n++;
        while ((1ll * n * (n + 1) / 2) % 2 != (b - a) % 2) {
            n++;
        }
        cout << n << endl;
    }
}