#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define rank das

const int M = 107;

const int mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int sub(int x, int y) {
  return add(x, mod - y);
}

int mul(ll x, ll y) {
  return x * y % mod;
}

int n, k;
string t;
map<char, int> p;
set<pair<int, char>> ord;
map<char, int> rank;
int ans = 1;
int sum = 0;
int cur = 0;

void read() {
  cin >> n >> k;
  cin >> t;
}

void add(char c) {
  ord.erase(make_pair(rank[c], c));
  ++cur;
  rank[c] = cur;
  ord.insert(make_pair(rank[c], c));

  int upd = sub(add(1, sum), p[c]);
  ans = add(ans, upd);
  p[c] = add(p[c], upd);
  sum = add(sum, upd);
}

void kill() {
  for (int i = 0; i < k; ++i) {
    char c = 'a' + i; 
    p[c] = 0;
    ord.insert(make_pair(cur, c));
    rank[c] = cur;
  }

  for (char c : t) {
    add(c);
    /*for (int i = 0; i < k; ++i) {
      char c = 'a' + i;
      cerr << "p " << c << " = " << p[c] << endl;
    }
    cerr << endl;
    */
  }

  //cerr << "ans = " << ans << endl;

  for (int i = 0; i < n; ++i) {
    char c = ord.begin()->second;
    add(c);
    //cerr << c << "!\n";
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
}