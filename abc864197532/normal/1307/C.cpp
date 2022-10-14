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
  string s;
  cin >> s;
  int n = s.length();
  lli ans = 0;
  fop (c1,0,26) {
    lli aa = 0;
    fop (i,0,n) if (c1 == s[i] - 'a') aa++;
    ans = max(ans, aa);
    fop (c2,0,26) {
      int now = 0;
      lli tmp = 0;
      fop (i,0,n) {
        if (c2 == s[i] - 'a') tmp += now;
        if (c1 == s[i] - 'a') now++;
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}