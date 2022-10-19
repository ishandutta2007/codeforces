#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> cnt(k);
  for (char c: s) {
    cnt[c-'A']++;
  }
  cout << k*(*min_element(cnt.begin(), cnt.end())) << '\n';
}