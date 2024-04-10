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
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    string ans = s;
    int k = 1;
    fop (i,1,n) {
      string t1 = s.substr(0, i), t2 = s.substr(i);
      if ((n + i) & 1) reverse(t1.begin(), t1.end());
      if (ans > t2 + t1) {
        ans = t2 + t1;
        k = i + 1;
      }
    }
    cout << ans << endl << k << endl;
  }
}