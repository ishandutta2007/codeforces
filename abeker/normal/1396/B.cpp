#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    vector <int> a(N);
    for (auto &it : a)
      scanf("%d", &it);
    int maks = *max_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    puts(2 * maks > sum || sum % 2 ? "T" : "HL");
  }
  return 0;
}