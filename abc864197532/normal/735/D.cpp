#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
const int mod = 1e9 + 7, x = 864197532, N = 5087, logN = 13;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli n;
  cin >> n;
  if (n & 1) {
    bool is = true, is2 = true;
    for (lli i = 2; i * i <= n; ++i) {
      is &= n % i != 0;
      is2 &= (n - 2) % i != 0;
    }
    if (is) cout << 1 << endl;
    else if (is2) cout << 2 << endl;
    else cout << 3 << endl;
  } else {
    cout << (n != 2) + 1 << endl;
  }
}