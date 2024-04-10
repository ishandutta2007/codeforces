#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int p[N], l[N], s[N];
int total_used = 0;
double ans = 0;

struct frac {
  int num;
  long long denom;
};

bool operator < (const frac& a, const frac& b) {
  return b.denom*a.num < a.denom*b.num;
}

double getval(frac a) {
  return (double)a.num/a.denom;
}

/*
bool operator <= (const frac& a, const frac& b) {
  return b.second*a.first <= a.second*b.first;
}

bool operator > (const frac& a, const frac& b) {
  return b < a;
}

bool operator >= (const frac& a, const frac& b) {
  return b <= a;
}

bool operator != (const frac& a, const frac& b) {
  return b.second*a.first != a.second*b.first;
}

bool operator == (const frac& a, const frac& b) {
  return b.second*a.first == a.second*b.first;
}

bool operator < (const pair<frac, int>& a, const pair<frac, int>& b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
*/

set<pair<frac, int>, greater<pair<frac, int>>> options;
set<pair<frac, int>> remove_options;

pair<frac, int> make_option(int i) {
  return make_pair(frac{p[i]*l[i], 1LL*(l[i]+s[i])*(l[i]+s[i]+1)}, i);
}

pair<frac, int> make_remove_option(int i) {
  return make_pair(frac{p[i]*l[i], 1LL*(l[i]+s[i])*(l[i]+s[i]-1)}, i);
}

void take_top_ticket() {
  assert(options.size());
  pair<frac, int> opt = *options.begin();
  ans += getval(opt.first);

  int i = opt.second;
  options.erase(opt);
  if (s[i]) remove_options.erase(make_remove_option(i));
  s[i]++;
  total_used++;
  remove_options.emplace(make_remove_option(i));
  if (s[i] < l[i]) options.emplace(make_option(i));
}

void remove_ticket(int i) {
  assert(s[i] >= 1);
  remove_options.erase(make_remove_option(i));
  if (s[i] < l[i]) options.erase(make_option(i));
  ans -= (double)(p[i]*s[i])/(l[i]+s[i]);
  s[i]--;
  total_used--;
  ans += (double)(p[i]*s[i])/(l[i]+s[i]);
  options.emplace(make_option(i));
  if (s[i]) remove_options.insert(make_remove_option(i));
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(12);
  int n, t, q;
  cin >> n >> t >> q;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> l[i];
  for (int i = 1; i <= n; i++) options.emplace(make_option(i));
  while (options.size() && total_used < t) {
    take_top_ticket();
  }

  while (q--) {
    int type, i;
    cin >> type >> i;
    if (type == 1) {
      if (s[i] < l[i]) options.erase(make_option(i));
      if (s[i]) remove_options.erase(make_remove_option(i));
      ans -= (double)(p[i]*s[i])/(l[i]+s[i]);
      l[i]++;
      if (s[i]) {
        s[i]--;
        total_used--;
      }
      ans += (double)(p[i]*s[i])/(l[i]+s[i]);
      options.emplace(make_option(i));
      if (s[i]) remove_options.emplace(make_remove_option(i));
    }
    else {
      assert(type == 2);
      if (s[i] == l[i]) remove_ticket(i);
      if (s[i] < l[i]) options.erase(make_option(i));
      if (s[i]) remove_options.erase(make_remove_option(i));
      ans -= (double)(p[i]*s[i])/(l[i]+s[i]);
      l[i]--;
      ans += (double)(p[i]*s[i])/(l[i]+s[i]);
      if (s[i] < l[i]) options.emplace(make_option(i));
      if (s[i]) remove_options.emplace(make_remove_option(i));
    }
    if (remove_options.size()) {
      remove_ticket((*remove_options.begin()).second);
    }
    while (options.size() && total_used < t) {
      take_top_ticket();
    }
    /*
    for (int i = 1; i <= n; i++) {
      cout << s[i] << ' ';
    }
    cout << total_used << '\n';
    */
    cout << ans << '\n';
  }
}