#include <bits/stdc++.h>
using namespace std;

vector<int> operator + (const vector<int>& a, const vector<int>& b) {
  int k = (int)a.size();
  assert(k == (int)b.size());
  vector<int> c(k);
  for (int i = 0; i < k; i++) {
    c[i] = a[i]+b[i];
    if (c[i] > 3) c[i] -= 3;
    if (c[i] != 0) c[i] = 3-c[i];
  }
  return c;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> cards(n, vector<int>(k));
  for (int i = 0; i < n; i++) {
    for (int& x: cards[i]) cin >> x;
  }
  sort(cards.begin(), cards.end());
  vector<int> freq(n);
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      vector<int> c = cards[i]+cards[j];
      auto it = lower_bound(cards.begin(), cards.end(), c);
      if (it != cards.end() && *it == c) {
        freq[it-cards.begin()]++;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += freq[i]*(freq[i]-1)/2;
  }
  cout << ans << '\n';
}