#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N;
int perm[MAXN];
bool bio[MAXN];
deque <pii> ans;

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int coin;
    scanf("%d", &coin);
    perm[coin] = i;
  }
}

void add_front(int x, int y) {
  ans.push_front({x, y});
}

void add_back(int x, int y) {
  ans.push_back({x, y});
}

void one_cycle(const vi &cyc) {
  int len = cyc.size();
  auto add_local = [&](int x, int y) {
    add_front(cyc[x % len], cyc[y % len]);
  };
  add_local(1, 2);
  add_local(1, 3);
  for (int i = 3; i < len; i++)
    add_local(i, i + 1);
  add_local(1, 2);
  add_local(0, 1);
}

void two_cycles(vi cyc1, vi cyc2) {
  cyc2.insert(cyc2.begin(), cyc1.back());
  cyc1.pop_back();
  cyc1.insert(cyc1.begin(), cyc2.back());
  cyc2.pop_back();
  int len1 = cyc1.size();
  for (int i = 0; i < len1 - 1; i++)
    add_front(cyc1[i], cyc1[i + 1]);
  int len2 = cyc2.size();
  for (int i = 0; i < len2 - 1; i++)
    add_front(cyc2[i], cyc2[i + 1]);
  add_front(cyc1[0], cyc2[0]);
  add_front(cyc1.back(), cyc2.back());
}

void fixed_and_transposition(int x, const vi &tau) {
  add_back(x, tau[0]);
  add_back(tau[0], tau[1]);
  add_back(x, tau[1]);
}

void solve() {
  int fixed = 0;
  vector <vi> other;
  for (int i = 1; i <= N; i++) 
    if (!bio[i]) {
      vi tmp;
      for (int x = i; !bio[x]; x = perm[x]) {
        tmp.push_back(x);
        bio[x] = true;
      }
      if (tmp.size() > 1)
        other.push_back(tmp);
      else
        fixed = tmp[0];
    }
  if (!other.empty()) {
    int largest = max_element(other.begin(), other.end(), [&](const vi &u, const vi &v) { return u.size() < v.size(); }) - other.begin();
    swap(other[0], other[largest]);
    int parity = other.size() % 2;
    for (int i = parity; i < other.size(); i += 2)
      two_cycles(other[i], other[i + 1]);
    if (parity) {
      if (other[0].size() >= 3) 
        one_cycle(other[0]);
      else 
        fixed_and_transposition(fixed ? fixed : other[1][0], other[0]);
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) {
    printf("%d %d\n", perm[it.first], perm[it.second]);
    swap(perm[it.first], perm[it.second]);
  }
}

int main() {
  load();
  solve();
  return 0;
}