#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxn 100005

using namespace std;
typedef long long ll;

int n, p, xmin, a[maxn];
set<int> legal; // legal remainders.
vector<int> ans;
void work(int l, int r) { // [l, r)
  if (legal.empty()) return;
  int i = *legal.lower_bound(l % p) - l % p + l;
  while (i < r) {
    ans.push_back(i);
    i = *legal.lower_bound(i % p + 1) - i % p + i;
  }
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) xmin = max(xmin, a[i] - i + 1);
  for (int i = 0; i < p + p; i++) legal.insert(i);
  for (int i = n; i >= 2; i--) {
    int newBan = ((a[i] - i) % p + p) % p;
    legal.erase(newBan);
    legal.erase(newBan + p);
    work(max(xmin, a[i - 1]), min(a[i], a[p]));
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", int(ans.size()));
  for (auto i : ans) printf("%d ", i);
  return 0;
}