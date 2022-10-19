#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;

int n, k, a, b;
string s;
vector<int> lens, ls;

void read() {
  cin >> n >> a >> b >> k;
  cin >> s;
}


void kill() {
  for (int l = 0; l < n;) {
    if (s[l] == '1') {
      ++l;
      continue;
    }
    int r = l;
    while (r < n && s[r] == '0')
      ++r;
    int len = (r - l);
    lens.push_back(len);
    ls.push_back(l);
    l = r;
  }

  int sum = 0;
  for (int len : lens)
    sum += len / b;

  assert(sum >= a);

  vector<int> ans;

  for (int i = 0; i < (int) lens.size(); ++i) {
    while (sum >= a && lens[i] >= b) {
      ans.push_back(ls[i] + b - 1);
      ls[i] += b;
      lens[i] -= b;
      --sum;
    }
  }

  assert(sum < a);

  cout << ans.size() << endl;
  for (int x : ans)
    cout << x + 1 << " ";
  cout << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}