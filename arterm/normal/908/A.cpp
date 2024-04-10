#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

string s;

void read() {
  cin >> s;
}

void kill() {
  int ans = 0;
  for (char c : s)
    for (char x : {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'})
      if (c == x)
        ++ans;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("a.in", "r", stdin);
#endif

  read();
  kill();
    
  return 0;
}