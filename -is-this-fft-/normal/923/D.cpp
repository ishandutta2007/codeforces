#include <iostream>
#include <string>
#include <bits/extc++.h> 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> sones;
ordered_set<int> tones;
int get_suff (const ordered_set<int> &ones, int l, int r) {
  auto ub = ones.upper_bound(r);
  if (ub == ones.begin()) {
    return r - l + 1;
  }

  int lo = *prev(ub);
  if (lo < l) {
    return r - l + 1;
  }

  return r - lo;
}

int get_ones (const ordered_set<int> &ones, int l, int r) {
  return ones.order_of_key(r + 1) - ones.order_of_key(l);
}

bool can (int s1, int ss, int t1, int ts) {
  if (s1 == 0 && t1 != 0) {
    s1 += 2;
    if (ss <= ts) return 0;
    ss = ts;
  }
  if (s1 % 2 != t1 % 2) return 0;
  if (ss < ts) return 0;
  if (s1 > t1) return 0;
  if (s1 == t1 && (ss % 3 != ts % 3)) return 0;
  return 1;
}

bool query (int a, int b, int c, int d) {
  return can(get_ones(sones, a, b),
             get_suff(sones, a, b),
             get_ones(tones, c, d),
             get_suff(tones, c, d));
}

int main () {
  ios::sync_with_stdio(false);
  
  string s, t;
  cin >> s >> t;

  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] != 'A') {
      sones.insert(i + 1);
    }
  }

  for (int i = 0; i < (int) t.size(); i++) {
    if (t[i] != 'A') {
      tones.insert(i + 1);
    }
  }

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << query(a, b, c, d);
  }
  cout << endl;
}