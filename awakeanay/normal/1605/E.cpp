#include <iostream>
#include <algorithm>

#define int long long

const int MAXN = 200005;

int a[MAXN];
int ch[MAXN]; // change needed if b[1] = x[1];
int chp[MAXN]; // change needed in change if b[1] increases by 1
int ich[MAXN], rch[MAXN];


int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 1; i <= n; i++)
    std::cin >> a[i];

  int imp1 = a[1];

  for(int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[i] = x-a[i];
  }

  int q;
  std::cin >> q;

  int ans[q];
  std::pair<int, int> qs[q];

  for(int i = 0; i < q; i++) {
    int x;
    std::cin >> x;
    qs[i] = {x, i};
  }

  std::sort(qs, qs+q);

  a[1] = qs[0].first-imp1;
  int imp2 = qs[0].first;
  chp[1] = 1;

  int init = 0;
  int rate = 0;

  for(int i = 1; i <= n; i++) {
    ch[i] += a[i];
    init += abso(ch[i]);

    if(ch[i]*chp[i] < 0) {
      rate -= abso(chp[i]);

      int lo = 0, hi = q;
      while(lo < hi) {
        int mid = (lo+hi)/2;
        int uq = qs[mid].first;

        if(abso(ch[i]) - abso(chp[i])*(uq-imp2) <= 0)
          hi = mid;
        else
          lo = mid+1;
      }

      if(lo != q) {
        rch[lo] += 2*abso(chp[i]);
        ich[lo] += -2*abso(ch[i]);
      }
    }
    else {
      rate += abso(chp[i]);
    }

    for(int j = 2*i; j <= n; j += i) {
      chp[j] -= chp[i];
      ch[j] -= ch[i];
    }
  }

  for(int i = 0; i < q; i++) {
    init += ich[i];
    rate += rch[i];

    ans[qs[i].second] = init + rate*(qs[i].first-imp2);
  }

  for(int i = 0; i < q; i++)
    std::cout << ans[i] << std::endl;

  return 0;
}