#include <bits/stdc++.h>
using namespace std;

struct frac {
  long long num;
  int denom;
};

frac make_frac(int x) {
  return frac{x, 1};
}

bool operator < (const frac& a, const frac& b) {
  return b.denom*a.num < a.denom*b.num;
}

bool operator > (const frac& a, const frac& b) {
  return b < a;
}

frac operator + (int& a, const frac& b) {
  return frac{1LL*a*b.denom+b.num, b.denom};
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  sort(a.begin(), a.end());

  vector<long long> s(n+1);
  for (int i = 0; i < n; i++) {
    s[i+1] = s[i]+a[i];
  }
  frac best_skew{0, 1};
  pair<int, int> ans = {0, 0};

  for (int i = 0; i < n; i++) {
    int low = 0;
    int high = min(i, n-1-i)+1;
    while (high-low > 1) {
      int mid = (low+high)/2;
      frac mean = frac{s[n]-s[n-mid]+s[i+1]-s[i-mid], 2*mid+1};
      if (frac{a[i-mid]+a[n-mid], 2} > mean) low = mid;
      else high = mid;
    }
    frac skew{s[n]-s[n-low]+s[i+1]-s[i-low]-1LL*(2*low+1)*a[i], 2*low+1};
    if (skew > best_skew) {
      best_skew = skew;
      ans = {i, low};
    }
  }

  cout << 2*ans.second+1 << '\n';
  for (int i = ans.first-ans.second; i <= ans.first; i++) {
    cout << a[i] << ' ';
  }
  for (int i = n-1; i >= n-ans.second; i--) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}