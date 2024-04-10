#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  puts(min(m, k) >= n ? "Yes" : "No");  
  return 0;
}