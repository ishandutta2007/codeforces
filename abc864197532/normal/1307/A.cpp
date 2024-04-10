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
#define pli pair<lli,int> 
#define X first
#define Y second

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n];
    fop (i,0,n) cin >> a[i];
    if (n == 1) {
      cout << a[0] << endl;
      continue;
    }
    int k = 100;
    while (k--) {
      fop (i,1,n) {
        if (!a[i]) continue;
        if (m >= i) {
          a[i]--;
          a[0]++;
          m -= i;
          break;
        } else m = 0;
      }
    }
    cout << a[0] << endl;
  }
}