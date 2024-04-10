#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

namespace Rho {
  ull mul (ull a, ull b, ull mod) {
    ll ret = a * b - mod * (ull) (1.L / mod * a * b);
    return ret + mod * (ret < 0) - mod * (ret >= (ll) mod);
  }

  ull bigMod (ull a, ull e, ull mod) {
    ull ret = 1;
    while (e) {
      if (e & 1) ret = mul(ret, a, mod);
      a = mul(a, a, mod), e >>= 1;
    }
    return ret;
  }
    
  bool isPrime (ull n) {
    if (n < 2 or n % 6 % 4 != 1) return (n | 1) == 3;
    ull a[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n - 1), d = n >> s;
    for (ull x : a) {
      ull p = bigMod(x % n, d, n), i = s;
      while (p != 1 and p != n - 1 and x % n and i--) p = mul(p, p, n);
      if (p != n - 1 and i != s) return 0;
    }
    return 1;
  }
    
  ull pollard (ull n) {
    auto f = [&] (ull x) {return mul(x, x, n) + 1;};
    ull x = 0, y = 0, t = 0, prod = 2, i = 1, q;
    while (t++ % 40 or __gcd(prod, n) == 1) {
      if (x == y) x = ++i, y = f(x);
      if ((q = mul(prod, max(x, y) - min(x, y), n))) prod = q;
      x = f(x), y = f(f(y));
    }
    return __gcd(prod, n);
  }

  vector <ull> factor (ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
  }
};

const int N = 1005;

bitset <N> gd;
int n, k; ll a[N];
vector <ll> ppf[N];
map <ll, vector <int>> posSingle;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    ll x; scanf("%lld", &x); a[i] = x;
    vector <ull> facs = Rho::factor(x);
    sort(facs.begin(), facs.end());
    facs.erase(unique(facs.begin(), facs.end()), facs.end());
    for (ull p : facs) ppf[i].emplace_back(p);
  }
  map <ll, int> freq;
  for (int i = 1; i <= n; ++i) {
    if (ppf[i].size() == 1) ++freq[ppf[i][0]];
  }
  ll singleExtra = 0;
  vector <pair <ll, int>> goodSingles;
  set <ll> available;
  for (auto it : freq) if (it.second > 1) {
    goodSingles.emplace_back(it);
    singleExtra += it.second - 2;
    available.emplace(it.first);
  }
  ll goodMore = 0;
  for (int i = 1; i <= n; ++i) {
    if (ppf[i].size() == 1) {
      if (!available.count(ppf[i][0])) continue;
      posSingle[ppf[i][0]].emplace_back(i);
      continue;
    }
    bool good = 1;
    for (ll p : ppf[i]) if (!available.count(p)) {
      good = 0;
      break;
    }
    if (!good) continue;
    ++goodMore; gd[i] = 1;
  }
  if (singleExtra + 2 * goodSingles.size() + goodMore < k or k == 1) {
    cout << "0\n";
    return 0;
  }
  cerr << singleExtra + 2 * goodSingles.size() << " " << goodMore << '\n';
  if (2 * goodSingles.size() <= k) {
    vector <ll> ans;
    for (auto &it : posSingle) {
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
    }
    int rem = k - ans.size();
    for (auto it : posSingle) {
      for (int x : it.second) {
        if (!rem) break;
        ans.emplace_back(a[x]); --rem;
      }
      if (!rem) break;
    }
    for (int i = 1; i <= n and rem > 0; ++i) if (gd[i]) {
      --rem; ans.emplace_back(a[i]);
    }
    for (ll x : ans) printf("%lld ", x); puts("");
    return 0;
  }
  if (k % 2 == 0) {
    vector <ll> ans;
    int rem = k;
    for (auto &it : posSingle) {
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
      rem -= 2;
      if (!rem) break;
    }
    for (ll x : ans) printf("%lld ", x); puts("");
    return 0; 
  }
  vector <ll> ans;
  for (auto &it : posSingle) {
    if (it.second.size() > 2) {
      k -= 3;
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
      break;
    }
  }
  cerr << k << " " << ans.size() << '\n';
  if (k & 1) {
    if (goodMore == 0) {
      cout << "0\n";
      return 0;
    }
    for (int i = 1; i <= n; ++i) if (gd[i]) {
      if (2 * ppf[i].size() + 1 > k) continue;
      --k; ans.emplace_back(a[i]); 
      for (ll p : ppf[i]) {
        if (!k) break;
        ans.emplace_back(a[posSingle[p].back()]);
        posSingle[p].pop_back();
        ans.emplace_back(a[posSingle[p].back()]);
        posSingle[p].pop_back();
        posSingle.erase(p); k -= 2;
      }
      for (auto &it : posSingle) {
        if (!k) break;
        ans.emplace_back(a[it.second.back()]); it.second.pop_back();
        ans.emplace_back(a[it.second.back()]); it.second.pop_back();
        k -= 2;
      }
      break; 
    }
    if (ans.empty()) cout << "0\n";
    else {
      for (ll x : ans) cout << x << " "; cout << '\n';
    }
    return 0;
  } 
  for (auto &it : posSingle) {
    if (it.second.size() > 1) {
      if (k == 0) break;
      k -= 2;
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
      ans.emplace_back(a[it.second.back()]); it.second.pop_back();
    }
  }
  for (ll x : ans) printf("%lld ", x); puts("");
  return 0;
}