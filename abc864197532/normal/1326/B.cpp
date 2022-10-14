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
    int n;
    cin >> n;
    int input[n];
    fop (i,0,n) cin >> input[i];
    lli ans[n];
    ans[0] = input[0];
    lli maxx = ans[0];
    fop (i,1,n) {
        ans[i] = maxx + input[i];
        maxx = max(maxx, ans[i]);
    }
    fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}