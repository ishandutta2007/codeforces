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
    int n, m, d;
    cin >> n >> m >> d;
    int input[n * m];
    fop (i,0,n*m) cin >> input[i];
    sort(input, input + (n * m));
    fop (i,0,n*m-1) {
        if ((input[i + 1] - input[i]) % d) {
            cout << "-1\n";
            return 0;
        }
    }
    int mid = n * m / 2;
    lli ans = 0;
    fop (i,0,n*m) {
        ans += abs(input[mid] - input[i]);
    }
    cout << ans / d << '\n';
}