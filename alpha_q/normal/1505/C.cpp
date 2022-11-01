#include <bits/stdc++.h>

using namespace std;

bool good (vector <int> vec) {
  for (int i = 2; i < vec.size(); ++i) {
    if (vec[i] != (vec[i - 1] + vec[i - 2]) % 26) return 0;
  }
  return 1;
}

int main() {
  string s; cin >> s;
  vector <int> vec;
  for (char c : s) vec.emplace_back(c - 'A');
  puts(good(vec) ? "YES" : "NO");
  return 0;
}