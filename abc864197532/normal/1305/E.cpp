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
  int n, m, all = 0;
  cin >> n >> m;
  vector <int> ans(n);
  fop (i,0,n) {
    ans[i] = i + 1;
    all += i / 2;
  }
  if (all < m) cout << -1 << endl;
  else {
    int now = n - 1, able = now / 2;
    while (all > m) {
      ans[now] += 2;
      all--;
      able--;
      if (able == 0) {
        ans[now] = 1e9 - (n - now) * 10000;
        now--;
        able = now / 2;
      }
    }
    fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
  }
}