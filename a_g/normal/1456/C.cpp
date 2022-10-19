#include <bits/stdc++.h>
using namespace std;

const int N  = 5e5+5;
int k;
pair<long long, int> tree[2*N];
long long s[N];

void upd(int i) {
  tree[i+k] = make_pair(s[i], i);
  i += k;
  for (i >>= 1; i; i >>= 1) {
    tree[i] = max(tree[2*i], tree[2*i+1]);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> k;
  k++;
  for (int i = 0; i < k; i++) {
    tree[i+k] = make_pair(0, i);
  }
  for (int i = k-1; i >= 1; i--) {
    tree[i] = min(tree[2*i], tree[2*i+1]);
  }

  vector<int> a(n);
  for (int& x: a) cin >> x;
  sort(a.begin(), a.end(), greater<int>());

  long long ans = 0;
  for (int x: a) {
    int i = tree[1].second;
    ans += s[i];
    s[i] += x;
    upd(i);
  }
  cout << ans << '\n';
}