#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5;
const int MAXV = 1e6 + 5;

int N;
int a[MAXN];
int pos[MAXV];
vector <int> divisors[MAXV];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

vector <int> two_pointers(const vector <int> &u, vector <int> v, bool rev, const function <bool(int, int)> &cmp) {
  if (rev)
    reverse(v.begin(), v.end());
  int ptr = 0, sz = v.size();
  vector <int> res(sz);
  for (int i = 0; i < sz; i++) {
    while (ptr < u.size() && cmp(u[ptr], v[i]))
      ptr++;
    res[i] = ptr;
  }
  if (rev)
    reverse(res.begin(), res.end());
  return res;
}

ll solve(int lo, int hi) {
  if (hi - lo == 1)
    return 1;
  int mid = (lo + hi) / 2;
  ll res = solve(lo, mid) + solve(mid, hi);
  vector <int> v(a + lo, a + hi);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  int sz = v.size();
  for (int i = 0; i < sz; i++)
    pos[v[i]] = i;
  vector <int> lft(a + lo, a + mid);
  reverse(lft.begin(), lft.end());
  vector <int> rig(a + mid, a + hi);
  auto my_less = [](int x, int y) { return x < y; };
  auto my_leq = [](int x, int y) { return x <= y; };
  auto my_greater = [](int x, int y) { return x > y; };
  auto my_geq = [](int x, int y) { return x >= y; };
  vector <int> leq_left = two_pointers(lft, v, false, my_leq);
  vector <int> leq_right = two_pointers(rig, v, false, my_leq);
  vector <int> less_left = two_pointers(lft, v, false, my_less); 
  vector <int> less_right = two_pointers(rig, v, false, my_less);
  vector <int> geq_left = two_pointers(lft, v, true, my_geq); 
  vector <int> geq_right = two_pointers(rig, v, true, my_geq);
  vector <int> greater_left = two_pointers(lft, v, true, my_greater);
  vector <int> greater_right = two_pointers(rig, v, true, my_greater);
  for (int j = sz - 1; j >= 0; j--) {
    for (auto it : divisors[v[j]]) {
      int i = pos[it];
      if (i != -1)
        res += (ll)min(geq_left[i], leq_left[j]) * min(geq_right[i], leq_right[j]) + 
               (ll)min(greater_left[i], less_left[j]) * min(greater_right[i], less_right[j]) - 
               (ll)min(geq_left[i], less_left[j]) * min(geq_right[i], less_right[j]) - 
               (ll)min(greater_left[i], leq_left[j]) * min(greater_right[i], leq_right[j]);
    }
    pos[v[j]] = -1;
  }
  return res;
}

void init() {
  memset(pos, -1, sizeof pos);
  for (int i = 1; i < MAXV; i++)
    for (int j = i; j < MAXV; j += i)
      divisors[j].push_back(i);
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%lld\n", solve(0, N));
  }
  return 0;
}