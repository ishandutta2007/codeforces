#include <bits/stdc++.h>
using namespace std;

const int P = 3;
const int N = 5e5+5;
const int MOD[P] = {712293997, 643476907, 990352709};

struct hashval {
  int r[P] = {};
  hashval(int k = 0) {
    for (int i = 0; i < P; i++) {
      r[i] = k;
    }
  }
};

hashval p10[N];


hashval operator + (hashval a, hashval b) {
  for (int i = 0; i < P; i++) {
    a.r[i] += b.r[i];
    if (a.r[i] >= MOD[i]) a.r[i] -= MOD[i];
  }
  return a;
};

hashval operator - (hashval a, hashval b) {
  for (int i = 0; i < P; i++) {
    a.r[i] -= b.r[i];
    if (a.r[i] < 0) a.r[i] += MOD[i];
  }
  return a;
};

hashval operator * (hashval a, hashval b) {
  for (int i = 0; i < P; i++) {
    a.r[i] = 1LL * a.r[i] * b.r[i] % MOD[i];
  }
  return a;
}

hashval operator * (int a, hashval b) {
  return hashval(a)*b;
}

bool operator == (hashval a, hashval b) {
  for (int i = 0; i < P; i++) {
    if (a.r[i] != b.r[i]) return 0;
  }
  return 1;
}

// cp-algorithms
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  p10[0] = 1;
  for (int j = 1; j < N; j++) {
    p10[j] = 10*p10[j-1];
  }

  string s, x;
  cin >> s >> x;
  int n = s.size();
  int m = x.size();
  vector<hashval> prefs(n+1, 0);
  for (int i = 1; i <= n; i++) {
    prefs[i] = 10*prefs[i-1] + hashval(s[i-1]-'0');
  }

  auto get = [&] (int l, int r) {
    return prefs[r+1]-p10[r-l+1]*prefs[l];
  };

  hashval target;
  for (char c: x) {
    target = 10*target+hashval(c-'0');
  }

  auto check = [&] (int l1, int r1, int l2, int r2) {
    if (l1 < 0) return;
    if (r2 >= n) return;
    if (l1 > r1 || l2 > r2) return;
    assert(l2 == r1+1);
    if (get(l1, r1)+get(l2, r2) == target) {
      cout << l1+1 << " " << r1+1 << '\n';
      cout << l2+1 << " " << r2+1 << '\n';
      exit(0);
    }
  };

  if (m >= 2) {
    for (int i = 0; i+2*m-3 < n; i++) {
      check(i, i+m-2, i+m-1, i+2*m-3);
    }
  }

  vector<int> z = z_function(x+' '+s);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      check(i, i+m-1, i+m, i+2*m-z[i+m+1]-1-j);
      check(i-m+z[i+m+1]+j, i-1, i, i+m-1);
    }
  }
}