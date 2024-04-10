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
#define MAXN 300000

int main () {
  int n;
  cin >> n;
  int a[n], b[n];
  fop (i,0,n) cin >> a[i];
  fop (i,0,n) cin >> b[i];
  vector <int> nums;
  fop (i,0,n) nums.pb(b[i] - a[i]);
  sort(nums.begin(), nums.end());
  lli ans = 0;
  fop (i,0,n) ans += lower_bound(nums.begin(), nums.end(), a[i] - b[i]) - nums.begin();
  fop (i,0,n) if (a[i] - b[i] > b[i] - a[i]) ans--;
  cout << ans / 2 << endl;
}