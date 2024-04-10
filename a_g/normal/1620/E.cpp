#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5+5;
int endpts[maxn];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(endpts, endpts + maxn, 0);
  int q;
  cin >> q;
  vector<tuple<int, int, int>> replacements;
  int sz = 0;
  vector<int> ans;

  while (q--) {
    int k;
    cin >> k;
    if (k == 1) {
      int x;
      cin >> x;
      ans.push_back(x);
      sz++;
    }
    else {
      int x, y;
      cin >> x >> y;
      replacements.push_back({sz, x, y});
    }
  }
  
  int index = replacements.size()-1;
  for (int i = sz-1; i >= 0; i--) {
    while (index >= 0 && get<0>(replacements[index]) > i) {
      endpts[get<1>(replacements[index])] = endpts[get<2>(replacements[index])];
      index--;
    }
    ans[i] = endpts[ans[i]];
  }
  for (int val: ans) cout << val << ' ';
  cout << '\n';
}