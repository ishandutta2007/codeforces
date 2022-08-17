#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define int long long

const int MAXN = 500010;
int bit[MAXN];

void upd(int x, int val) {
  x += 1;
  while(x < MAXN) {
    bit[x] = std::max(bit[x], val);
    x += x&(-x);
  }
}

int max(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret = std::max(ret, bit[x]);
    x -= x&(-x);
  }
  return ret;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n+5; i++)
      bit[i] = 0;
  
    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::stack<int> st;
    std::pair<int, int> helper[n];
    int lg[n];
    for(int i = 0; i < n; i++) {
      helper[i] = {a[i], i+1};
      lg[i] = 0;
      while(!st.empty()) {
        if(a[st.top()-1] <= a[i])
          st.pop();
        else
          break;
      }

      if(!st.empty())
        lg[i] = st.top();

      st.push(i+1);
    }

    std::sort(helper, helper+n);

    int ans = 0;
    for(int i = 0; i < n; i++) {
      int j = helper[i].second;
      int cur = max(j)+1;
      if(lg[j-1] > 0)
        cur = std::max(cur, max(lg[j-1]-1)+2);
      upd(j, cur);
      ans = std::max(ans, cur);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}