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
    lli n, k, tmp;
    cin >> n >> k;
    lli ans = 0;
    int id = 0;
    lli dd = -1;
    fop (i,0,k) {
        cin >> tmp;
        if (ans < (n / tmp) * tmp) {
            ans = (n / tmp) * tmp;
            id = i;
            dd = tmp;
        }
    }
    cout << id + 1 << ' ' << max(n / dd, 0ll) << endl;
}