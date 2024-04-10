#include <bits/stdc++.h>
#define bc __builtin_popcount
using namespace std;

const int MAXN = 24;
const int MAXB = 1e6;

int N;
vector <int> b;
int mask[MAXN * MAXB + 5];
int sum[1 << MAXN];

void load() {
  scanf("%d", &N);
  b.resize(N);
  for (auto &it : b)
    scanf("%d", &it);
}

void construct(vector <int> cycle, vector <int> tail) {
  puts("YES");
  for (auto it : cycle)
    printf("%d ", it);
  for (auto it : tail) {
    int curr = it - cycle.back();
    printf("%d ", curr);
    cycle.push_back(curr);
  }
  puts("");
  exit(0);
}

void bye() {
  puts("NO");
  exit(0);
}

vector <int> get_three(vector <int> v) {
  int sum = accumulate(v.begin(), v.end(), 0);
  if (sum % 2)
    return {};
  sum /= 2;
  vector <int> res;
  for (auto it : v)
    res.push_back(sum - it);
  return res;
}

vector <int> get_rest(vector <int> v) {
  vector <int> res;
  for (auto it : b)
    if (!count(v.begin(), v.end(), it))
      res.push_back(it);
  return res;
}

void solve() {
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  if (b.size() < N) {
    b.resize(N - 1);
    construct({0}, b);
  }
  if (N == 2)
    bye();
  if (N == 3) {
    vector <int> sol = get_three(b);
    if (sol.empty())
      bye();
    construct(sol, {});
  }
  vector <int> even, odd;
  for (auto it : b)
    if (it % 2)
      odd.push_back(it);
    else
      even.push_back(it);
  if (!even.empty()) {
    vector <int> three = {even.back()};
    even.pop_back();
    for (int i = 0; i < 2; i++)
      three.push_back(even.size() >= 2 ? even[i] : odd[i]);
    construct(get_three(three), get_rest(three));
  }
  int n = min(N, 24);
  for (int i = 0; i < n; i++)
    sum[1 << i] = b[i];
  for (int i = 1; i < 1 << n; i++) {
    int lobit = i & -i, sz = bc(i);
    sum[i] = sum[i ^ lobit] + sum[lobit];
    if (mask[sum[i]] >> sz & 1) 
      for (int j = 1; j < i; j++)
        if (sum[j] == sum[i] && bc(j) == sz) {
          auto extract = [&](int subset) {
            vector <int> res;
            for (int k = 0; k < n; k++)
              if (subset >> k & 1)
                res.push_back(b[k]);
            return res;
          };
          vector <int> c;
          vector <int> x = extract(i);
          vector <int> y = extract(j);  
          for (int k = 0; k < sz; k++) {
            c.push_back(x[k]);
            c.push_back(y[k]);
          }
          vector <int> rest = get_rest(c);
          c.insert(c.end(), rest.begin(), rest.end());
          c.erase(c.begin());
          construct({0}, c);
        }
    mask[sum[i]] |= 1 << sz;
  }
  bye();
}

int main() {
  load();
  solve();
  return 0;
}