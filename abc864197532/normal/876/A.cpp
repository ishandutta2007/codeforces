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
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    if (min({a,b,c}) == c) {
        if (n > 1) cout << min(a,b) + c * (n - 2) << endl;
        else cout << 0 << endl;
    } else {
        cout << min({a,b,c}) * (n - 1) << endl;
    }
}