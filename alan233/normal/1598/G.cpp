//  /tuu 
/**
 *    author:  tourist
 *    created: 10.10.2021 12:49:55       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;

/*vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}*/

template <typename T>
vector<int> z_function(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

template <typename T>
vector<int> z_function(const T &s) {
  return z_function((int) s.size(), s);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s_;
  cin >> s_;
  string x_;
  cin >> x_;
  int n = (int) s_.size();
  int m = (int) x_.size();
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    s[i] = (int) (s_[i] - '0');
  }
  vector<int> x(m);
  for (int i = 0; i < m; i++) {
    x[i] = (int) (x_[i] - '0');
  }
  vector<int> seq = x;
  seq.insert(seq.end(), s.begin(), s.end());
  auto z = z_function(seq);
  auto Check = [&](int l1, int r1, int l2, int r2) {
    int i = r1;
    int j = r2;
    int c = 0;
    for (int q = m - 1; q >= 0; q--) {
      if (i >= l1) {
        c += s[i];
        i -= 1;
      }
      if (j >= l2) {
        c += s[j];
        j -= 1;
      }
      int nc = 0;
      if (c >= 10) {
        c -= 10;
        nc = 1;
      }
      if (x[q] != c) {
        return;
      }
      c = nc;
    }
    if (c != 0 || i >= l1 || j >= l2) {
      return;
    }
    cout << l1 + 1 << " " << r1 + 1 << '\n';
    cout << l2 + 1 << " " << r2 + 1 << '\n';
    exit(0);
  };
  {
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
      md = (int) 1e8 + rng() % (int) 9e8;
      bool pr = true;
      for (int i = 2; i * i <= md; i++) {
        if (md % i == 0) {
          pr = false;
          break;
        }
      }
      if (pr) {
        break;
      }
    }
  }
  vector<Mint> p10(n + 1);
  p10[0] = 1;
  for (int i = 1; i <= n; i++) {
    p10[i] = p10[i - 1] * 10;
  }
  Mint inv_10 = 1 / Mint(10);
  vector<Mint> inv_p10(n + 1);
  inv_p10[0] = 1;
  for (int i = 1; i <= n; i++) {
    inv_p10[i] = inv_p10[i - 1] * inv_10;
  }
  vector<Mint> suf(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + p10[n - 1 - i] * s[i];
  }
  vector<pair<int, int>> all_suf(n + 1);
  for (int i = 0; i <= n; i++) {
    all_suf[i] = make_pair(suf[i](), i);
  }
  sort(all_suf.begin(), all_suf.end());
/*  vector<Mint> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] * 10 + s[i];
  }
  vector<pair<int, int>> all_pref(n + 1);
  for (int i = 0; i <= n; i++) {
    all_pref[i] = make_pair(pref[i](), i);
  }
  sort(all_pref.begin(), all_pref.end());*/
  Mint x_val = 0;
  for (int i = 0; i < m; i++) {
    x_val = x_val * 10 + x[i];
  }
  for (int k = m; k >= m - 1 && k >= 1; k--) {
    for (int i = 0; i <= n - k; i++) {
      Mint me = (suf[i] - suf[i + k]) * inv_p10[n - (i + k)];
      Mint goal = x_val - me;
      { // pref[j] - pref[i + k] * p10[j - (i + k)] == goal
        // pref[j] * inv_p10[j] - pref[i + k] * inv_p10[i + k] == goal * inv_p10[j]
        // (suf[i + k] - suf[j]) * inv_p10[n - j] == goal
        // (suf[i + k] - suf[j]) * inv_p10[n - j] + (suf[i] - suf[i + k]) * inv_p10[n - (i + k)] == x_val
        // sad...
        auto Test = [&](int len) {
          if (len >= 1 && len <= m) {
            int j = i + k + len;
            if (j <= n) {
              if ((suf[i + k] - suf[j]) * inv_p10[n - j] == goal) {
                Check(i, i + k - 1, i + k, j - 1);
              }
            }
          }
        };
        if (k == m - 1) {
          Test(m - 1);
          Test(m);
        } else {
          int match = min(m, z[m + i]);
          Test(m - match);
          Test(m - match - 1);
        }
      }
      { // (suf[j] - suf[i]) * inv_p10[n - i] == goal
        Mint needle = goal * p10[n - i] + suf[i];
        auto it = lower_bound(all_suf.begin(), all_suf.end(), make_pair(needle(), -1));
        while (it != all_suf.end() && it->first == needle) {
          int j = it->second;
          if (j < i && i - j <= m) {
            Check(j, i - 1, i, i + k - 1);
          }
          ++it;
        }
      }
    }
  }
  assert(false);
  return 0;
}