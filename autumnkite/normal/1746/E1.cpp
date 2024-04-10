#include <bits/stdc++.h>

bool query(std::vector<int> S) {
  std::cout << "? " << S.size();
  for (int x : S) {
    std::cout << " " << x;
  }
  std::cout << std::endl;
  std::string res;
  std::cin >> res;
  return res == "YES";
}

bool test(int x) {
  std::cout << "! " << x << std::endl;
  std::string res;
  std::cin >> res;
  return res == ":)";
}

std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}

bool solve(std::vector<int> S) {
  int n = S.size();
  if (n == 1) {
    return test(S[0]);
  }
  if (n == 2) {
    return test(S[0]) || test(S[1]);
  }
  int m1 = n / 4, m2 = n / 2, m3 = (m2 + n) / 2;
  std::vector<int> S0(S.begin(), S.begin() + m1);
  std::vector<int> S1(S.begin() + m1, S.begin() + m2);
  std::vector<int> S2(S.begin() + m2, S.begin() + m3);
  std::vector<int> S3(S.begin() + m3, S.end());
  auto A = merge(S0, S1), B = merge(S0, S2);
  bool b0 = query(A), b1 = query(B), b2 = query(B), b3 = query(A);
  if (b1 == b2) {
    if (b1) {
      return solve(B);
    } else {
      return solve(merge(S1, S3));
    }
  } else if (b0 == b3) {
    if (b0) {
      return solve(A);
    } else {
      return solve(merge(S2, S3));
    }
  } else {
    if (b0) {
      return solve(merge(S0, S3));
    } else {
      return solve(merge(S1, S2));
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> id(n);
  std::iota(id.begin(), id.end(), 1);
  assert(solve(id));
}