#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

set <pair <int, int>> st;
vector <pair <int, int>> here[N];
int n, l[N], r[N], id[N], one[N], two[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", l + i, r + i);
    here[l[i]].emplace_back(r[i], i);
  }
  for (int i = 1; i <= n; ++i) {
    for (auto it : here[i]) st.emplace(it);
    one[st.begin() -> second] = i, st.erase(st.begin());
  }
  for (int i = 1; i <= n; ++i) two[i] = one[i];
  bool bad = 0;
  for (int i = 1; i <= n; ++i) {
    for (auto it : here[i]) st.emplace(it);
    if (st.size() > 1 and one[next(st.begin()) -> second] <= st.begin() -> first) {
      swap(two[st.begin() -> second], two[next(st.begin()) -> second]);
      bad = 1; break;
    } else st.erase(st.begin());
  }
  puts(bad ? "NO" : "YES");
  for (int i = 1; i <= n; ++i) printf("%d ", one[i]); puts("");
  if (bad) {
    for (int i = 1; i <= n; ++i) printf("%d ", two[i]); puts("");
  }
  return 0;
}