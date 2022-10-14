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
    int a, b;
    cin >> a >> b;
    int m = a - b >> 1;
    fop (i,0,a) {
        if (i % (m + 1) < m) cout << 0;
        else cout << 1;
    }
    cout << endl;
}