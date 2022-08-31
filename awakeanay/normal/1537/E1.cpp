#include <iostream>
#include <vector>

#define int long long

// Code for suffix array copied from https://cp-algorithms.com/string/suffix-array.html3
// Start of copied code
std::vector<int> sort_cyclic_shifts(std::string const& s) {
  int n = s.size();
  const int alphabet = 256;

  std::vector<int> p(n), c(n), cnt(std::max(alphabet, n), 0);
  for (int i = 0; i < n; i++)
    cnt[s[i]]++;
  for (int i = 1; i < alphabet; i++)
    cnt[i] += cnt[i-1];
  for (int i = 0; i < n; i++)
    p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i-1]])
      classes++;
    c[p[i]] = classes - 1;
  }

  std::vector<int> pn(n), cn(n);
  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0)
        pn[i] += n;
    }
    std::fill(cnt.begin(), cnt.begin() + classes, 0);
    for (int i = 0; i < n; i++)
      cnt[c[pn[i]]]++;
    for (int i = 1; i < classes; i++)
      cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; i--)
      p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; i++) {
      std::pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
      std::pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
      if (cur != prev)
        ++classes;
      cn[p[i]] = classes - 1;
    }
    c.swap(cn);
  }
  return p;
}

std::vector<int> suffix_array_construction(std::string s) {
  s += "$";
  std::vector<int> sorted_shifts = sort_cyclic_shifts(s);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}
// End of copied code

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;

  std::string s;
  std::cin >> s;

  std::vector<int> sa = sort_cyclic_shifts(s);

  int min = n;
  int done = false;
  for(int i = 0; i < n; i++) {
    if(sa[i] == 0)
      done = true;
    else if(done) {
      min = std::min(min, sa[i]);
    }
  }

  for(int i = 0; i < k; i++)
    std::cout << s[i%min];
  std::cout << std::endl;

  return 0;
}