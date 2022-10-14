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
  vector <int> lf(n + 1, 1);
  fop (i,2,n+1) {
    for (int j = i + i; j <= n; j += i) lf[j] = i;
  }
  sort(lf.begin(), lf.end());
  fop (i,2,n+1) cout << lf[i] << ' ';
  cout << '\n';
}