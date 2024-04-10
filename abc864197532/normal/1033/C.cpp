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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n + 1];
    fop (i,0,n) {
        cin >> a[i];
        b[a[i]]= i;
    }
    char dp[n];
    fop (i,0,n) dp[i] = 'A';
    FOP (i,n+1,1) {
        bool is = true;
        for (int j = b[i] % i; j < n; j += i) {
            if (dp[j] ==  'B') is = false;
        }
        if (is) dp[b[i]] = 'B';
    }
    fop (i,0,n) cout << dp[i];
}