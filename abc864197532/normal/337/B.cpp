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

void check(int a, int b, int c, int d, int is) {
    if (is) {
        int kk = a;
        a *= c, b *= c, c *= kk, d *= kk;
        if (b > d) {
            int k = __gcd(b - d, b);
            cout << (b - d) / k << '/' << b / k << '\n';
            exit(0);
        }
    } else {
        int kk = b;
        a *= d, b *= d, c *= kk, d *= kk;
        if (a > c) {
            int k = __gcd(a - c, a);
            cout << (a - c) / k << '/' << a / k << '\n';
            exit(0);
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) swap(a, c), swap(b, d);
    check(a, b, c, d, 1);
    if (b > d) swap(a, c), swap(b, d);
    check(a, b, c, d, 0);
    cout << "0/1\n";
}