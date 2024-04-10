#include <bits/stdc++.h>
using namespace std;

typedef __int128 lll;

const int MAXN = 1e3 + 5;

class Tournament {
  lll num;
  int idx, offset;
  vector <lll> tour;
public:
  lll gcd(lll a, lll b) {
    return b ? gcd(b, a % b) : a;
  }
  void recalc(int x) {
    tour[x] = gcd(tour[2 * x], tour[2 * x + 1]);
  }
  Tournament(lll num, int idx, vector <lll> other) : num(num), idx(idx) {
    int n = other.size();
    for (offset = 1; offset < n; offset *= 2);
    tour.resize(2 * offset, num);
    for (int i = 0; i < n; i++)
      tour[i + offset] /= gcd(num, other[i]);
    for (int i = offset - 1; i; i--)
      recalc(i);
  }
  Tournament() {}
  void update(int x) {
    x += offset;
    tour[x] = num;
    for (x /= 2; x; x /= 2)
      recalc(x);
  }
  lll getNum() const {
    return num;
  }
  int getIdx() const {
    return idx;
  }
  bool bad() const {
    return tour[1] > 1;
  }
};

lll read() {
  char buff[40];
  scanf("%s", buff);
  lll res = 0;
  for (char* ptr = buff; *ptr; ptr++)
    res = 10 * res + *ptr - '0';
  return res;
}

void output(lll x) {
  if (!x)
    return;
  output(x / 10);
  printf("%d", (int)(x % 10));
}

int N, M;
lll a[MAXN], b[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    a[i] = read();
  for (int i = 0; i < M; i++)
    b[i] = read();
}

bool attempt(list <Tournament> &A, list <Tournament> &B) {
  for (auto it = A.begin(); it != A.end(); it++)
    if ((*it).bad()) {
      int tmp = (*it).getIdx();
      for (auto &elem : B)
        elem.update(tmp);
      A.erase(it);
      return true;
    }
  return false;
}

void finish(const list <Tournament> &l) {
  for (auto it : l) {
    output(it.getNum());
    printf(" ");
  }
  puts("");
}

void solve() {
  list <Tournament> a_gcd, b_gcd;
  for (int i = 0; i < N; i++)
    a_gcd.push_back(Tournament(a[i], i, vector <lll> (b, b + M)));
  for (int i = 0; i < M; i++)
    b_gcd.push_back(Tournament(b[i], i, vector <lll> (a, a + N)));
  auto check_empty = [&]() {
    return a_gcd.empty() || b_gcd.empty();
  };
  while (!check_empty() && (attempt(a_gcd, b_gcd) || attempt(b_gcd, a_gcd)));
  if (check_empty()) {
    puts("NO");
    return;
  }
  puts("YES");
  printf("%d %d\n", a_gcd.size(), b_gcd.size());
  finish(a_gcd);
  finish(b_gcd);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}