#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

int n, k;
vector<string> names;

void gen() {
  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j) {
      string cur = "Aa";
      cur[0] += i;
      cur[1] += j;
      names.push_back(cur);
    }
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  gen();

  int n, k;
  cin >> n >> k;
  int t = 0;
  vector<string> ans(n);
  for (int i = 0; i < k - 1; ++i)
    ans[i] = names[t++];


  for (int i = k - 1; i < n; ++i) {
    string cur;
    cin >> cur;
    if (cur == "YES")
      ans[i] = names[t++];
    else
      ans[i] = ans[i - (k - 1)];
  }

  for (string s : ans)
    cout << s << " ";
  cout << endl;
}