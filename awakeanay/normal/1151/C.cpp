#include <iostream>

#define int long long

const int MOD = 1000000007;
const int INV2 = (MOD+1)/2;

int sum(int x) {
  int in[2];
  in[0] = 2;
  in[1] = 1;

  int done = 0;
  int cur = 1;
  int ty = 1;
  int ans = 0;
  while(true) {
    int add = std::min(x-done, cur);

    int valf = in[ty];
    int vall = in[ty] + (add-1)*2;
    vall %= MOD;
    int next = (vall + valf)%MOD;
    next = (next*INV2)%MOD;
    int n2 = add%MOD;
    next = (next*n2)%MOD;
    ans = (ans + next)%MOD;
    in[ty] = vall + 2;
    in[ty] %= MOD;
    
    done += add;
    if(done == x)
      return ans;
    ty ^= 1;
    cur *= 2;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int l, r;
  std::cin >> l >> r;


  int cur = sum(r);
  if(l > 1)
    cur -= sum(l-1);
  cur += MOD;
  cur %= MOD;

  std::cout << cur << std::endl;

  return 0;
}