#include <iostream>
#include <vector>
#include <map>

#define int long long

const int PRE = 10000007;

int pre[PRE];
int lp[PRE];
std::vector<int> pr;

int numf(int k) {
  int count = 0;
  for(int i = 0; pr[i]*pr[i] <= k; i++) {
    if(k < PRE) {
      count += pre[k];
      k = 1;
      break;
    }
    if(k%pr[i] == 0) {
      while(k%pr[i] == 0) {
        count++;
        k /= pr[i];
      }
    }
  }

  if(k > 1)
    count++;
  return count;
}

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  for(int i = 2; i < PRE; i++) {
    if(lp[i]) {
      pre[i] = 1 + pre[i/lp[i]];
      continue;
    }
    pre[i] = 1;
    pr.push_back(i);
    for(int j = i; j < PRE; j+=i)
      lp[j] = i;
  }

  while(t--) {
    int a, b, k;
    std::cin >> a >> b >> k;

    int min = 2;
    if(a == b) {
      min = 0;
    }
    else if(b%a == 0 || a%b == 0)
      min = 1;
    else
      min = 2;

    int max = numf(a) + numf(b);
    if(min == 0 && k == 1) {
      std::cout << "NO" << std::endl;
      continue;
    }
    std::cout << (min <= k && k <= max ? "YES" : "NO") << std::endl;
  }

  return 0;
}