#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

struct Restr {
  int l, r, x;
};

bool cmp (const Restr &p, const Restr &q) {
  if (p.l != q.l) {
    return p.l < q.l;
  }
  return p.r < q.r;
}

int allowed [MAX_N];
int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    allowed[i] = ~0;
  }

  vector<Restr> qs (m);
  for (int i = 0; i < m; i++) {
    cin >> qs[i].l >> qs[i].r >> qs[i].x;
    if (qs[i].l > qs[i].r) {
      swap(qs[i].l, qs[i].r);
    }
  }

  sort(qs.begin(), qs.end(), cmp);

  for (auto q : qs) {
    allowed[q.l] &= q.x;
    allowed[q.r] &= q.x;
  }

  for (auto q : qs) {
    arr[q.l] |= q.x & ~allowed[q.r];
  }
  
  for (auto q : qs) {
    if (q.l == q.r) {
      arr[q.l] |= q.x;
      continue;
    }

    int tr = q.x & allowed[q.r] & ~arr[q.l];
    arr[q.r] |= tr;
    arr[q.l] |= q.x ^ tr;
  }

  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}