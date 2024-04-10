#include <iostream>
#include <vector>

#define MAX 10000007

#define int long long

int lp[MAX];
int mp[MAX];
int sum[MAX];
int imp[MAX];
int early[MAX];

signed main() {

  for(int i = 2; i < MAX; i++) {
    if(lp[i] == 0) {
      sum[i] = i+1;
      mp[i] = i;
      imp[i] = i+1;

      for(int j = i; j < MAX; j+=i)
        lp[j] = i;
    }
    else {
      int div = i/lp[i];
      sum[i] = sum[div];
      if(lp[i] == lp[div]) {
        mp[i] = lp[i]*mp[div];
        imp[i] = mp[i]+imp[div];
        sum[i] /= imp[div];
        sum[i] *= imp[i];
      }
      else {
        mp[i] = lp[i];
        imp[i] = 1+mp[i];
        sum[i] *= imp[i];
      }
    }

    if(sum[i] < MAX && early[sum[i]] == 0)
      early[sum[i]] = i;
  }

  early[1] = 1;

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;
    std::cout << early[n] - (early[n]==0) << std::endl;
  }

  return 0;
}