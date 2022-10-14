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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  int a[n], b[m];
  fop (i,0,n) cin >> a[i];
  fop (i,0,m) cin >> b[i];
  int l = 0, r = 0;
  while (a[l] % p == 0) l++;
  while (b[r] % p == 0) r++;
  cout << l + r << '\n';
}