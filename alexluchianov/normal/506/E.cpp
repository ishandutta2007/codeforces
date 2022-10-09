#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;

int const modulo = 10007;
int const sigma = 26;

int add(int x, int y) {
  x += y;
  if(modulo <= x)
    x -= modulo;
  return x;
}

std::vector<int> computeNaiveDP(std::string s) {
  int n = s.size(), m;
  m = 1 + 7 * n;
  std::vector<std::vector<std::vector<int> > > dp;

  dp.resize(1 + n);
  for(int i = 0; i <= n; i++)
    dp[i].resize(1 + n);
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
      dp[i][j].resize(1 + m);
  dp[0][0][0] = 1;

  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
      for(int h = 0; h < m; h++) {
        if(i + j + 2 <= n && s[i] == s[n - 1 - j]) {
          dp[i + 1][j + 1][h] = add(dp[i + 1][j + 1][h], dp[i][j][h]);
          if(h + 2 < m)
            dp[i][j][h + 2] = add(dp[i][j][h + 2], 1LL * dp[i][j][h] * (sigma - 1) % modulo);
        } else if(i + j + 2 <= n && h + 1 < m) {
          dp[i + 1][j][h + 1] = add(dp[i + 1][j][h + 1], dp[i][j][h]);
          dp[i][j + 1][h + 1] = add(dp[i][j + 1][h + 1], dp[i][j][h]);
          if(h + 2 < m)
            dp[i][j][h + 2] = add(dp[i][j][h + 2], 1LL * dp[i][j][h] * (sigma - 2) % modulo);
        } else if(i + j + 1 == n && h + 1 < m) {
          dp[i + 1][j][h + 1] = add(dp[i + 1][j][h + 1], dp[i][j][h]);
          if(h + 2 < m)
            dp[i][j][h + 2] = add(dp[i][j][h + 2], 1LL * dp[i][j][h] * (sigma - 1) % modulo);
        } else {
          if(h + 2 < m)
            dp[i][j][h + 2] = add(dp[i][j][h + 2], 1LL * dp[i][j][h] * sigma % modulo);
        }
      }
  std::vector<int> answer(m);
  for(int i = 0; i < m; i++) {
    for(int j = 0; j <= n; j++) 
      answer[i] = add(answer[i], dp[j][n - j][i]);
    if(0 < i)
      for(int j = 0; j <= n; j++) 
        answer[i] = add(answer[i], 1LL * dp[j][n - j][i - 1] * sigma % modulo);
    for(int j = 0; j < n; j++)
      answer[i] = add(answer[i], dp[j][n - j - 1][i]);
  }
  return answer;
}

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int inverse(int number) {
  return lgpow(number, modulo - 2);
}

std::vector<int> berlekamp(std::vector<int> dp) {
  std::vector<int> curr;
  curr.push_back(1);
  int l = 0;

  std::vector<int> last;
  last.push_back(1);
  int lastval = 1;
  int x = 1;

  for(int i = 0; i < dp.size(); i++) {
    int result = 0;
    for(int j = 0; j < curr.size(); j++)
      result = (result + 1LL * dp[i - j] * curr[j]) % modulo;
    if(result != 0 && 2 * l > i) {
      for(int j = 0; j < last.size(); j++)
        curr[j + x] = (modulo + curr[j + x] - 1LL * result * inverse(lastval) % modulo * last[j] % modulo) % modulo;
      x++;
    } else if(result != 0) {
      std::vector<int> aux = curr;
      curr.resize(last.size() + x);
      for(int j = 0; j < last.size(); j++)
        curr[j + x] = (modulo + curr[j + x] - 1LL * result * inverse(lastval) % modulo * last[j] % modulo) % modulo;
      l = i + 1 - l;
      lastval = result;
      last = aux;
      x = 1;
    } else
      x++;
  }
  return curr;
}

std::vector<int> multiply(std::vector<int> f1, std::vector<int> f2) {
  std::vector<int> result(f1.size() + f2.size() + 1);
  for(int i = 0; i < f1.size(); i++)
    for(int j = 0; j < f2.size(); j++)
      result[i + j] = (result[i + j] + 1LL * f1[i] * f2[j]) % modulo;
  while(0 < result.size() && result.back() == 0)
    result.pop_back();
  return result;
}

std::vector<int> divide(std::vector<int> f1, std::vector<int> f2) {
  if(f1.size() < f2.size())
    return f1;
  
  for(int i = f1.size() - 1; f2.size() - 1 <= i; i--) {
    int coef = 1LL * f1[i] * inverse(f2.back()) % modulo;
    int offset = i - (f2.size() - 1);
    for(int j = 0; j < f2.size(); j++) {
      f1[j + offset] = add(f1[j + offset], modulo - (1LL * f2[j] * coef % modulo));
    }
    assert(f1[i] == 0);
  }
  while(0 < f1.size() && f1.back() == 0)
    f1.pop_back();
  return f1;
}

std::vector<int> lgpow(std::vector<int> a, int b, std::vector<int> polymod) {
  if(b == 1)
    return a;
  else {
    std::vector<int> result = lgpow(a, b / 2, polymod);
    if(b % 2 == 0)
      return divide(multiply(result, result), polymod);
    else
      return divide(multiply(divide(multiply(result, result), polymod), a), polymod);
  }
}

int main() {
  std::string s;
  std::cin >> s;
  std::vector<int> answer = computeNaiveDP(s);
  std::vector<int> recurr = berlekamp(answer);

  int n;
  std::cin >> n;
  std::reverse(recurr.begin(), recurr.end());
  std::vector<int> state = lgpow({0, 1}, n, recurr);
  
  int result = 0;
  for(int i = 0; i < state.size(); i++) {
    result = (result + 1LL * state[i] * answer[i]) % modulo;
  }
  std::cout << result << '\n';
  return 0;
}