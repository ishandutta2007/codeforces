#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int MAXA = 300005;
const int MAXN = 200005;

std::vector<int> rev(MAXA, -1);
std::vector<int> divr[MAXA];
int n;
int a[MAXN];

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

int val[MAXN];

struct seg
{
  std::vector<int> s1, lazy, s2;

  void push(int id, int l, int r) {
    if(lazy[id]) {
      lazy[left] += lazy[id];
      lazy[right] += lazy[id];
      s2[left] += lazy[id]*s1[left];
      s2[right] += lazy[id]*s1[right];
      lazy[id] = 0;
    }
  }

  void upd1(int x, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      s1[id]++;
      return;
    }

    push(id, l, r);

    if(x <= mid)
      upd1(x, left, l, mid);
    else
      upd1(x, right, mid+1, r);

    s1[id] = s1[left] + s1[right];
  }

  void upd2(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(r < x || y < l)
      return;

    if(x <= l && r <= y) {
      lazy[id]++;
      s2[id] += s1[id];
      return;
    }

    push(id, l, r);

    upd2(x, y, left, l, mid);
    upd2(x, y, right, mid+1, r);

    s2[id] = s2[left] + s2[right];
  }

  int sum(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return 0;

    if(x <= l && r <= y)
      return s2[id];

    push(id, l, r);
    return sum(x, y, left, l, mid) + sum(x, y, right, mid+1, r);
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;

  int ans[n];
  int pref = 0;
  for(int i = 0; i < n; i++) {
    ans[i] = pref;
    std::cin >> a[i];
    pref += a[i];
    ans[i] += i*a[i];
    rev[a[i]] = i;
  }

  for(int i = 1; i < MAXA; i++)
    for(int j = i; j < MAXA; j += i)
      divr[j].push_back(i);

  seg tree;
  tree.s1 = tree.s2 = tree.lazy = std::vector<int>(2*n-1, 0);

  for(int i = 1; i < MAXA; i++) {
    for(int j : divr[i]) {
      if(rev[j] != -1) {
        add(rev[j], j);
        tree.upd1(rev[j]);
      }
    }

    if(rev[i] != -1) {
      ans[rev[i]] -= sum(rev[i]-1);
      tree.upd2(rev[i]+1, n-1);
    }
  }

  for(int i = 0; i < n; i++) {
    ans[i] -= a[i]*tree.sum(i, i);
    if(i) ans[i] += ans[i-1];
    std::cout << ans[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}