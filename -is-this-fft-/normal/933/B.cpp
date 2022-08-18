#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);

  ll p;
  int k;
  cin >> p >> k;

  vector<int> ans;
  while (p != 0) {
    int c = p % k;
    if (c < 0) c += k;
    ans.push_back(c);
    p = c - p;
    p /= k;
  }

  while (ans.back() == 0) ans.pop_back();

  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
  }
  cout << '\n';
}