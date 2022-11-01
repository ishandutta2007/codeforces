#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
char s[N];
string tt;
string uu;

string to (int x) {
  if (x == 0) return "0";
  string s = "";
  while (x > 0) {
    s += char('0' + x % 10);
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}

int digsum (int x) {
  int sum = 0;
  while (x) sum += x % 10, x /= 10;
  return sum;
}
 
bool check (int sum) {
  string s = to(sum);
  int sz = s.size();
  if (sum < 10) {
    tt = uu = s;
    return 1;
  }
  for (int mask = 0; mask < 1 << (sz - 1); ++mask) {
    int cur = 0, sm = 0;
    for (int i = 0; i < sz - 1; ++i) {
      cur *= 10, cur += (s[i] - '0');
      if (mask & 1 << i) {
        sm += cur;
        cur = 0;
      }
    }
    cur *= 10, cur += (s[sz - 1] - '0');
    sm += cur;
    if (digsum(sm) >= 10) continue;
    for (int i = 0; i < sz - 1; ++i) {
      tt += s[i];
      if (mask & 1 << i) tt += '+';
    }
    tt += s[sz - 1];
    string sms = to(sm);
    uu += sms[0];
    for (int i = 1; i < sms.size(); ++i) {
      uu += '+', uu += sms[i];
    }
    return 1;
  }
  return 0;
}

int num (int l, int r) {
  int ret = 0;
  for (int i = l; i <= r; ++i) {
    ret *= 10, ret += (s[i] - '0');
  }
  return ret;
}

int id[N], magic = 10;

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += (s[i] - '0');
  }
  if (check(sum)) {
    putchar(s[1]);
    for (int i = 2; i <= n; ++i) {
      putchar('+');
      putchar(s[i]);
    }
    puts("");
    cout << tt << endl << uu << endl;
    return 0;
  }
  sum = 0;
  for (int i = 2; i <= n; i += 2) {
    sum += (10 * (s[i - 1] - '0') + (s[i] - '0'));
  }
  if (n & 1) sum += (s[n] - '0');
  if (check(sum)) {
    putchar(s[1]);
    for (int i = 2; i <= n; ++i) {
      if (i & 1) putchar('+');
      putchar(s[i]);
    }
    puts("");
    cout << tt << endl << uu << endl;
    return 0;
  }
  for (int d = 2; d < magic; ++d) {
    sum = 0;
    for (int i = d; i <= n; i += d) {
      sum += num(i - d + 1, i);
    }
    int ex = 0, pwr = 1;
    for (int i = n; (i % d) != 0; --i) {
      ex += pwr * (s[i] - '0'), pwr *= 10;
    }
    sum += ex;
    if (check(sum)) {
      putchar(s[1]);
      for (int i = 2; i <= n; ++i) {
        if (i % d == 1) putchar('+');
        putchar(s[i]);
      }
      puts("");
      cout << tt << endl << uu << endl;
      return 0;
    }
  }
  for (int i = 1; i < n; ++i) id[i] = i;
  srand(2ll * n * 1ll * n);
  random_shuffle(id + 1, id + n);
  for (int it = 1; it < n; ++it) {
    int pos = id[it];
    sum = 0;
    int sum1 = 0;
    for (int i = 1; i <= n; ++i) {
      if (i == pos) { 
        sum += (10 * (s[i] - '0') + (s[i + 1] - '0'));
        ++i;
      }
      else sum += (s[i] - '0');
    }
    if (check(sum)) {
      putchar(s[1]);
      for (int i = 2; i <= n; ++i) {
        if (i != pos + 1) putchar('+');
        putchar(s[i]);
      }
      puts("");
      cout << tt << endl << uu << endl;
      return 0;
    }
    if (pos <= n - 2) {
      for (int i = 1; i <= n; ++i) {
        if (i == pos) { 
          sum1 += (100 * (s[i] - '0') + 10 * (s[i + 1] - '0') + (s[i + 2] - '0'));
          i += 2;
        }
        else sum1 += (s[i] - '0');
      }
      if (check(sum1)) {
        putchar(s[1]);
        for (int i = 2; i <= n; ++i) {
          if (i != pos + 1 and i != pos + 2) putchar('+');
          putchar(s[i]);
        }
        puts("");
        cout << tt << endl << uu << endl;
        return 0;
      }
    }
    sum1 = 0;
    if (pos <= n - 3) {
      for (int i = 1; i <= n; ++i) {
        if (i == pos) { 
          sum1 += (1000 * (s[i] - '0') + 100 * (s[i + 1] - '0') + 10 * (s[i + 2] - '0') + (s[i + 3] - '0'));
          i += 3;
        }
        else sum1 += (s[i] - '0');
      }
      if (check(sum1)) {
        putchar(s[1]);
        for (int i = 2; i <= n; ++i) {
          if (i != pos + 1 and i != pos + 2 and i != pos + 3) putchar('+');
          putchar(s[i]);
        }
        puts("");
        cout << tt << endl << uu << endl;
        return 0;
      }
    }
    sum1 = 0;
    if (pos <= n - 4) {
      for (int i = 1; i <= n; ++i) {
        if (i == pos) { 
          sum1 += (10000 * (s[i] - '0') + 1000 * (s[i + 1] - '0') + 100 * (s[i + 2] - '0') + 10 * (s[i + 3] - '0') + (s[i + 4] - '0'));
          i += 4;
        }
        else sum1 += (s[i] - '0');
      }
      if (check(sum1)) {
        putchar(s[1]);
        for (int i = 2; i <= n; ++i) {
          if (i != pos + 1 and i != pos + 2 and i != pos + 3 and i != pos + 4) putchar('+');
          putchar(s[i]);
        }
        puts("");
        cout << tt << endl << uu << endl;
        return 0;
      }
    }
  }
  // string s = to(sum);
  // int sz = s.size();
  // for (int mask = 0; mask < 1 << (sz - 1); ++mask) {
  //   int cur = 0, sm = 0;
  //   for (int i = 0; i < sz - 1; ++i) {
  //     cur *= 10, cur += (s[i] - '0');
  //     if (mask & 1 << i) {
  //       sm += cur;
  //       cur = 0;
  //     }
  //   }
  //   cur *= 10, cur += (s[sz - 1] - '0');
  //   sm += cur;
  //   if (sm >= 100) continue;
  //   if ((sm / 10) + (sm % 10) >= 10) continue;
  //   for (int i = 0; i < sz - 1; ++i) {
  //     putchar(s[i]);
  //     if (mask & 1 << i) putchar('+');
  //   }
  //   putchar(s[sz - 1]);
  //   puts("");
  //   if (sm < 10) cout << sm << endl;
  //   else cout << sm / 10 << "+" << sm % 10 << endl;
  //   return 0;
  // }
  return 0;
}