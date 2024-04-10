#include <bits/stdc++.h>

using namespace std;

typedef pair <string, string> road;

const int N = 310;

string u[N], v[N];
int n, a, b, k, f;
map <road, int> cost;
vector <int> vec;

int main() {
  cin >> n >> a >> b >> k >> f;
  for (int i = 1; i <= n; ++i) {
    cin >> u[i] >> v[i];
    if (i > 1 and u[i] == v[i - 1]) {
      cost[{min(u[i], v[i]), max(u[i], v[i])}] += b;
    } else {
      cost[{min(u[i], v[i]), max(u[i], v[i])}] += a;
    }
  }
  int tot = 0;
  for (auto it : cost) {
    vec.push_back(it.second);
    tot += it.second;
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < min(k, (int) vec.size()); ++i) {
    tot -= max(0, vec[i] - f);
  }
  printf("%d\n", tot);
  return 0;
}