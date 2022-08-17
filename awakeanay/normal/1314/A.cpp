/*
Author: AwakeAnay
Date: 23/02/2020
Time: 21:37:58
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define int long long 

signed main() {
  int n;
  std::cin >> n;

  int cur = 0;
  std::pair<int, int> a[n];

  for(int i = 0; i < n; i++)
    std::cin >> a[i].first;

  for(int j = 0; j < n; j++)
    std::cin >> a[j].second;

  std::sort(a, a+n);

  std::multiset<int> min;
  int ans = 0;

  for(int i = 0; i < n; i++) {
    while(i < n && a[i+1].first == a[i].first) {
      cur += a[i].second;
      min.insert(-a[i].second);
      i++;
    }
    
    if(i < n) {
      cur += a[i].second;
      min.insert(-a[i].second);
    }

    ans += cur;
    ans += *(min.begin());
    cur += *(min.begin());
    min.erase(min.begin());
    
    int val = a[i].first+1;
    while(cur > 0 && (i == n-1 || val < a[i+1].first)) {
      ans += cur;
      ans += *(min.begin());
      cur += *(min.begin());
      min.erase(min.begin());
      val++;
    }
  }

  std::cout << ans << std::endl;


  return 0;
}