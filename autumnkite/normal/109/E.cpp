#include <bits/stdc++.h>

class bigint {
  std::vector<int> v;

public:
  bigint() : v() {}

  bigint(int x) {
    while (x) {
      v.push_back(x % 10);
      x /= 10;
    }
  }

  bigint(std::string s) : v(s.size()) {
    for (int i = 0; i < (int)s.size(); ++i) {
      v[i] = s[s.size() - i - 1] - '0';
    }
    while (!v.empty() && !v.back()) {
      v.pop_back();
    }
  }

  bigint &operator+=(const bigint &rhs) {
    v.resize(std::max(v.size(), rhs.v.size()));
    int d = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      if (i < (int)rhs.v.size()) {
        d += rhs.v[i];
      }
      v[i] += d;
      d = v[i] / 10;
      v[i] %= 10;
    }
    if (d) {
      v.push_back(d);
    }
    return *this;
  }

  bigint &operator-=(const bigint &rhs) {
    int d = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
      if (i < (int)rhs.v.size()) {
        d += rhs.v[i];
      }
      if (v[i] < d) {
        v[i] += 10 - d;
        d = 1;
      } else {
        v[i] -= d;
        d = 0;
      }
    }
    while (!v.empty() && !v.back()) {
      v.pop_back();
    }
    return *this;
  }

  std::size_t size() const {
    return v.size();
  }

  std::string to_string(std::size_t n = 0) {
    n = std::max(n, v.size());
    std::string res;
    res.reserve(n);
    while (n > v.size()) {
      --n;
      res.push_back('0');
    }
    while (n > 0) {
      --n;
      res.push_back(v[n] + '0');
    }
    return res;
  }

  friend bigint operator+(const bigint &lhs, const bigint &rhs) {
    return bigint(lhs) += rhs;
  }

  friend bigint operator-(const bigint &lhs, const bigint &rhs) {
    return bigint(lhs) -= rhs;
  }

  friend bigint operator<(const bigint &lhs, const bigint &rhs) {
    if (lhs.v.size() != rhs.v.size()) {
      return lhs.v.size() < rhs.v.size();
    }
    for (int i = (int)lhs.v.size() - 1; i >= 0; --i) {
      if (lhs.v[i] != rhs.v[i]) {
        return lhs.v[i] < rhs.v[i];
      }
    }
    return false;
  }
};

int calc(const std::string &s) {
  int res = 0;
  for (char c : s) {
    res += c == '4' || c == '7';
  }
  return res;
}

std::vector<int> get(const bigint &x, int len) {
  std::vector<int> res(len);
  for (int i = 0; i < len; ++i) {
    res[i] = calc((x + i).to_string());
  }
  return res;
}

std::string solve(const std::string &left_str, int len) { // len <= 6

  bigint left(left_str);
  std::vector<int> tmp(100 + len);
  for (int i = 0; i < 100 + len; ++i) {
    tmp[i] = calc((left + i).to_string());
  }
  std::vector<int> st(tmp.begin(), tmp.begin() + len);
  for (int i = 1; i <= 100; ++i) {
    if (std::vector<int>(tmp.begin() + i, tmp.begin() + i + len) == st) {
      return (left + i).to_string();
    }
  }
  if (len == 1) {
    int cnt = st[0];
    std::string s = left.to_string(left.size() + 1);
    int now = calc(s);
    for (int i = (int)s.size() - 1; i >= 0; --i) {
      now -= s[i] == '4' || s[i] == '7';
      for (char c = s[i] + 1; c <= '9'; ++c) {
        int rem = cnt - now - (c == '4' || c == '7');
        if (0 <= rem && rem < (int)s.size() - i) {
          std::string res = s.substr(0, i) + c
                          + std::string(s.size() - i - 1 - rem, '0')
                          + std::string(rem, '4');
          return bigint(res).to_string();
        }
      }
    }
    return "";
  }

  int cnt = *std::min_element(st.begin(), st.end());

  bigint block(left_str.substr(0, left_str.empty() ? 0 : left_str.size() - 1));
  std::string s = block.to_string(block.size() + 1);

  std::vector<int> lst(s.size());
  for (int i = 0; i < (int)s.size(); ++i) {
    lst[i] = s[i] == '9' ? lst[i - 1] : i;
  }

  int now = calc(s);
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    now -= s[i] == '4' || s[i] == '7';
    for (char c = s[i] + 1; c <= '9'; ++c) {
      int rem = cnt - now - (c == '4' || c == '7');
      if (0 <= rem && rem < (int)s.size() - i) {
        for (int x = 0; x + len <= 10; ++x) {
          bool ok = true;
          for (int i = 0; i < len && ok; ++i) {
            if (st[i] - cnt != (x + i == 4 || x + i == 7)) {
              ok = false;
            }
          }
          if (ok) {
            std::string res = s.substr(0, i) + c
                            + std::string(s.size() - i - 1 - rem, '0')
                            + std::string(rem, '4')
                            + char(x + '0');
            return bigint(res).to_string();
          }
        }
      }
      if (0 <= rem && rem < (int)s.size() - i - 1) {
        for (int x = 10 - len + 1; x < 10; ++x) {
          bool ok = true;
          for (int i = 0; i < 10 - x && ok; ++i) {
            if (st[i] - cnt != (x + i == 4 || x + i == 7)) {
              ok = false;
            }
          }
          for (int i = 0; i < len - (10 - x) && ok; ++i) {
            if (st[10 - x + i] - cnt != (i == 4 || i == 7)) {
              ok = false;
            }
          }
          if (ok) {
            std::string res = s.substr(0, i) + c
                            + std::string(s.size() - i - 2 - rem, '0')
                            + std::string(rem, '4')
                            + char('0')
                            + char(x + '0');
            return bigint(res).to_string();
          }
        }
      }
      if (0 <= rem && rem < (int)s.size() - i - 1) {
        for (int x = 10 - len + 1; x < 10; ++x) {
          bool ok = true;
          for (int i = 0; i < 10 - x && ok; ++i) {
            if (st[i] - cnt != (x + i == 4 || x + i == 7)) {
              ok = false;
            }
          }
          for (int i = 0; i < len - (10 - x) && ok; ++i) {
            if (st[10 - x + i] - cnt != 1 + (i == 4 || i == 7)) {
              ok = false;
            }
          }
          if (ok) {
            std::string res = s.substr(0, i) + c
                            + std::string(s.size() - i - 2 - rem, '0')
                            + std::string(rem, '4')
                            + char('3')
                            + char(x + '0');
            return bigint(res).to_string();
          }
        }
      }
      if (0 <= rem && rem < (int)s.size() - i - 1) {
        for (int x = 10 - len + 1; x < 10; ++x) {
          bool ok = true;
          for (int i = 0; i < 10 - x && ok; ++i) {
            if (st[i] - cnt != 1 + (x + i == 4 || x + i == 7)) {
              ok = false;
            }
          }
          for (int i = 0; i < len - (10 - x) && ok; ++i) {
            if (st[10 - x + i] - cnt != (i == 4 || i == 7)) {
              ok = false;
            }
          }
          if (ok) {
            std::string res = s.substr(0, i) + c
                            + std::string(s.size() - i - 2 - rem, '0')
                            + std::string(rem, '4')
                            + char('4')
                            + char(x + '0');
            return bigint(res).to_string();
          }
        }
      }
      char lstc = c == '9' ? (i == 0 ? '9' : s[lst[i - 1]]) : c;
      if (rem == -1 && (lstc == '4' || lstc == '7')) {
        for (int x = 10 - len + 1; x < 10; ++x) {
          bool ok = true;
          for (int i = 0; i < 10 - x && ok; ++i) {
            if (st[i] - cnt != (x + i == 4 || x + i == 7) + 1) {
              ok = false;
            }
          }
          for (int i = 0; i < len - (10 - x) && ok; ++i) {
            if (st[10 - x + i] - cnt != (i == 4 || i == 7)) {
              ok = false;
            }
          }
          if (ok) {
            std::string res = s.substr(0, i) + c
                            + std::string(s.size() - i - 1, '9')
                            + char(x + '0');
            return bigint(res).to_string();
          }
        }
      }
    }
  }
  return "";
}

std::string solve(std::string left_str, std::string len_str) {
  bigint left(left_str), len(len_str), right = left + len - 1;
  std::string right_str = right.to_string();
  left_str = left.to_string(right.size());
  int now = 0, p = 0;
  while (p < (int)right_str.size()
          && now * 10 + right_str[p] - left_str[p] < 6) {
    now = now * 10 + right_str[p] - left_str[p];
    ++p;
  }
  return solve(left_str.substr(0, p), now + 1) + left_str.substr(p);
}

int main() {
  std::string left, len;
  std::cin >> left >> len;
  std::cout << solve(left, len) << "\n";
}