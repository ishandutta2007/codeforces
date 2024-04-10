/*
Author: AwakeAnay
Date: 15/02/2020
Time: 01:20:28
*/

#include <iostream>
#include <vector>

#define int long long

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> seq(n);
  for(int i = 0; i < n; i++) {
    std::cin >> seq[i];
    seq[i]--;
  }

  std::vector<int> p(2*n, 0);
  std::vector<int> q(2*n, 0);

  int l, r;
  for(int i = 0; i < n; i++) {
    l = i-seq[i];
    r = i;

    if(l < 0) {
      l += n;
      r += n;
    }
    
    //std::cout << l << " " << r << std::endl;

    p[l] += seq[i]-r;
    if(r+1 < 2*n) p[r+1] -= seq[i]-r;
    q[l]++;
    if(r+1 < 2*n) q[r+1]--;

    if(seq[i] == n-1)
      continue;

    l = i+1;
    r = i-seq[i]-1+n;
    
    //std::cout << " " << l << " " << r << std::endl;

    p[l] -= seq[i]-l-n+1;
    if(r+1 < 2*n) p[r+1] += seq[i]-l-n+1;
    q[l]--;
    if(r+1 < 2*n) q[r+1]++;
  }

  std::vector<int> ans(n, 0);
  for(int i = 0; i < 2*n; i++) {
    if(i) p[i] += p[i-1];
    if(i) q[i] += q[i-1];
    //std::cout << p[i] << " " << q[i] << " " << i << std::endl;
    ans[i%n] += p[i]+q[i]*i;
  }
  
  int min, id;
  min = ans[0]; id = 0;
  for(int i = 1; i < n; i++) {
    if(ans[i] < min) {
      min = ans[i];
      id = i;
    }
  }

  std::cout << min << " " << (n-id)%n << std::endl;

  return 0;
}