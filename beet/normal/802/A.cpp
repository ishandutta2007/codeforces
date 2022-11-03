#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

struct SegmentTree
{
  const int INF = 1 << 30;

  vector< int > small, add;
  int sz;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    small.assign(2 * sz - 1, 0);
    add.assign(2 * sz - 1, 0);
  }

  inline void Merge(int k)
  {
    small[k] = max(small[2 * k + 1] + add[2 * k + 1], small[2 * k + 2] + add[2 * k + 2]);
  }

  int rmq(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (0);
    if(a <= l && r <= b) return (small[k] + add[k]);
    int L = rmq(a, b, 2 * k + 1, l, (l + r) >> 1);
    int R = rmq(a, b, 2 * k + 2, (l + r) >> 1, r);
    return (max(L, R) + add[k]);
  }

  void rangeadd(int a, int b, int x, int k, int l, int r)
  {
    if(a >= r || b <= l) return;
    if(a <= l && r <= b) {
      add[k] += x;
      return;
    }
    rangeadd(a, b, x, 2 * k + 1, l, (l + r) >> 1);
    rangeadd(a, b, x, 2 * k + 2, (l + r) >> 1, r);
    Merge(k);
  }

  int rmq(int a, int b)
  {
    return (rmq(a, b, 0, 0, sz));
  }

  void rangeadd(int a, int b, int x)
  {
    return (rangeadd(a, b, x, 0, 0, sz));
  }
};

int main()
{
  int N, K;
  int ret = 0;

  cin >> N >> K;
  map< int, int > st;
  SegmentTree height(500001);

  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    height.rangeadd(i, i + 1, 1);
    ++ret;
    if(st.count(A)) {
      if(height.rmq(st[A] + 1, i) + 1 <= K) {
        --ret;
        height.rangeadd(st[A] + 1, i, 1);
      }
    }
    st[A] = i;
  }
  cout << ret << endl;
}