#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
#define X first
#define Y second
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string ss;
        fop (i,0,b - 1) ss.pb('a' + i);
        fop (i,0,a - b + 1) ss.pb('a' + b - 1);
        int now = 0;
        fop (i,0,n) {
            cout << ss[now];
            now = (now + 1) % a;
        }
        cout << endl;
    }
}