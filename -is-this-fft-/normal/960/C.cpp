#include <iostream>
#include <vector>

using namespace std;

const int MAX_LG = 30;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);

  ll X, d;
  cin >> X >> d;

  ll cur = 1;
  vector<ll> ans;
  for (int i = 0; i < MAX_LG; i++) {
    if (X & 1 << i) {
      for (int j = 0; j < i; j++) {
        ans.push_back(cur);
      }
      cur += d;
      ans.push_back(cur);
      cur += d;
    }
  }

  cout << (int) ans.size() << '\n';
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
}