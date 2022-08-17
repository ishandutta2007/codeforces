#include <iostream>
#include <algorithm>
#include <set>

#define int long long

std::set<int> s;

void add(int a[], int pr[], int l, int r) {
  int ns = 0;
  s.insert(pr[r] - (l ? pr[l-1] : 0));
  if(a[l] == a[r])
    return;

  int s = (a[l] + a[r])/2;

  int lo = l, hi = r;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(a[mid] > s)
      hi = mid;
    else
      lo = mid+1;
  }

  add(a, pr, l, lo-1);
  add(a, pr, lo, r);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, q;
    std::cin >> n >> q;

    s.clear();

    int a[n], pr[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::sort(a, a+n);

    for(int i = 0; i < n; i++) {
      pr[i] = a[i];
      if(i) pr[i] += pr[i-1];
    }

    add(a, pr, 0, n-1);

    while(q--) {
      int x;
      std::cin >> x;
      
      if(s.count(x))
        std::cout << "Yes";
      else
        std::cout << "No";

      std::cout << std::endl;
    }
  }

  return 0;
}