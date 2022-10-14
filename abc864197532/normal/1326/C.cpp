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
const int mod = 998244353;

int main () {
    int n, k;
    cin >> n >> k;
    int input[n];
    vector <int> v;
    lli ans1 = 0;
    fop (i,0,n) {
        cin >> input[i];
        if (input[i] >= n - k + 1) v.pb(i), ans1 += input[i];
    }
    sort(v.begin(), v.end());
    lli ans2 = 1;
    fop (i,1,k) {
        ans2 = ans2 * (v[i] - v[i - 1]) % mod;
    }
    cout << ans1 << ' ' << ans2 << endl;
}