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
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b, tmp, s = 0;
    cin >> n >> m >> a >> b;
    n -= m;
    bool is = true;
    fop (i,0,m) {
        cin >> tmp;
        if (tmp == a) s |= 2;
        if (tmp == b) s |= 1;
        if (tmp < a or tmp > b) is = false;
    }
    if (is and n >= 2 - __builtin_popcount(s)) cout << "Correct\n";
    else cout << "Incorrect\n";
}