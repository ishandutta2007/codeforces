#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>
#include <stack>

using ll = long long;

int const modulo = 1000000007;
int const modulo2= 1000000009;
int const nmax = 300000;
int powp[2][1 + nmax];

void precompute() {
  powp[0][0] = powp[1][0] = 1;
  for(int i = 1;i <= nmax; i++)
    powp[0][i] = 1LL * powp[0][i - 1] * nmax % modulo;
  for(int i = 1;i <= nmax; i++)
    powp[1][i] = 1LL * powp[1][i - 1] * nmax % modulo2;
}

class Hash{
  int l;
  int number;
  int number2;
public:
  Hash(int val = 0) {
    l = 1;
    number = number2 = val;
  }
  Hash(int l_, int number_, int number2_) {
    l = l_;
    number = number_;
    number2 = number2_;
  }
  Hash operator + (Hash const oth) const {
    Hash result;
    result.l = l + oth.l;
    result.number = (1LL * number * powp[0][oth.l] + oth.number) % modulo;
    result.number2 = (1LL * number2 * powp[1][oth.l] + oth.number2) % modulo2;
    return result;
  }
  bool operator < (Hash const oth) const {
    if(l != oth.l)
      return l < oth.l;
    else if(number != oth.number)
      return number < oth.number;
    else
      return number2 < oth.number2;
  }
};
int v[1 + nmax];
int sol[1 + nmax];
std::map<Hash, int> mp;

ll divide(int from, int to) {
  if(from == to)
    return 0;

  int mid = (from + to) / 2;
  ll result = divide(from, mid) + divide(mid + 1, to);
  mp.clear();
  std::stack<int> st;
  std::stack<Hash> sthash;

  for(int i = mid; from <= i; i--) {
    if(0 == st.size()) {
      st.push(v[i]);
      sthash.push(v[i]);
    } else if(0 < st.size() && st.top() != v[i]) {
      st.push(v[i]);
      sthash.push(sthash.top() + Hash(v[i]));
    } else {
      st.pop();
      sthash.pop();
    }
    if(st.size() == 0)
      mp[Hash{0, 0, 0}]++;
    else
      mp[sthash.top()]++;
  }

  while(0 < st.size())
    st.pop();
  while(0 < sthash.size())
    sthash.pop();

  for(int i = mid + 1; i <= to; i++) {
    if(0 == st.size()) {
      st.push(v[i]);
      sthash.push(v[i]);
    } else if(0 < st.size() && st.top() != v[i]) {
      st.push(v[i]);
      sthash.push(sthash.top() + Hash(v[i]));
    } else {
      st.pop();
      sthash.pop();
    }
    if(st.size() == 0)
      result += mp[{0, 0, 0}];
    else
      result += mp[sthash.top()];
  }
  return result;
}

ll solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    v[i]--;
  }
  return divide(1, n);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  precompute();
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}