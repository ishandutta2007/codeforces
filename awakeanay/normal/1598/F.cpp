#include <iostream>
#include <vector>

#define int long long

const int MAXN = 2000005;

int sb[MAXN];
int reach[MAXN];
int dp[MAXN];

std::vector<std::vector<int> > v[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  int min[n], sum[n];
  int minc[n];

  for(int i = 0; i < n; i++) {
    min[i] = sum[i] = minc[i] = 0;
    std::string s;
    std::cin >> s;

    int sz = s.size();
    v[i] = std::vector<std::vector<int> >(2*sz+1);

    for(int j = 0; j < sz; j++) {
      char c = s[j];
      if(c == '(') {
        sum[i]++;
      }
      else {
        sum[i]--;
      }

      v[i][sum[i]+sz].push_back(j);

      if(sum[i] < min[i]) {
        min[i] = sum[i];
        minc[i] = 1;
      }
      else if(sum[i] == min[i]) {
        minc[i]++;
      }
    }
  }

  int m = (1 << n);
  sb[0] = 0;
  for(int i = 1; i < m; i++) {
    sb[i] = 0;
    for(int j = 0; j < n; j++) {
      if((i >> j)&1)
        sb[i] += sum[j];
    }
  }

  dp[0] = 0;
  int ans = 0;
  reach[0] = 1;
  for(int i = 1; i < m; i++) {
    dp[i] = 0;
    reach[i] = 0;
    for(int j = 0; j < n; j++) {
      int k = i^(1 << j);
      if(((i >> j)&1) && reach[k]) {
        if(min[j] + sb[k] > 0) {
          dp[i] = std::max(dp[i], dp[k]);
          reach[i] = 1;
        }
        if(min[j] + sb[k] == 0) {
          dp[i] = std::max(dp[i], dp[k] + minc[j]);
          reach[i] = 1;
        }
        ans = std::max(ans, dp[i]);
        int tar = -sb[k]-1;
        int jsz = (((int)v[j].size())-1)/2;

        int rsz = 0;
        if(tar+jsz >= 0 && tar+jsz < v[j].size())
          rsz = v[j][tar+jsz].size();
        int mp = jsz;
        //std::cout << i << " " << j << " " << rsz << std::endl;
        if(rsz)
          mp = v[j][tar+jsz][0];
        //std::cout << i << " " << j << " " << mp << std::endl;
        if(-sb[k]+jsz >= 0 && -sb[k]+jsz < v[j].size()) {
          int it = std::lower_bound(v[j][-sb[k]+jsz].begin(), v[j][-sb[k]+jsz].end(), mp)-v[j][-sb[k]+jsz].begin();
          ans = std::max(ans, dp[k] + it);
        }

      }
    }
  }

  std::cout << ans << std::endl;
  return 0;
}