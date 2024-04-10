#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 5001, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

long long modpow(int a, int b) {
	long long ans = 1;
	for (long long aa = a; b; b >>= 1, aa = aa * aa % mod) {
		if (b & 1) ans = ans * aa % mod;
	}
	return ans;
}

long long modinv (int b) {
	return modpow(b, mod - 2);
}

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  string s;
  int i, j = a + b - 1;
  if (a > b) {
    fop (i,0,a) s += '0';
    fop (i,0,b) s += '1';
    i = a - 1;
  } else {
    fop (i,0,b) s += '1';
    fop (i,0,a) s += '0';
    i = b - 1;
  }
  if (c & 1) {
    j--;
    c--;
    while (c) {
      c -= 2;
      swap(s[i], s[j]);
      i--; j -= 2;
    }
  } else {
    while (c) {
      c -= 2;
      swap(s[i], s[j]);
      i--;
      j -= 2;
    }
  }
  s += '\n';
  cout << s;
}