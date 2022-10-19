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
    printf("%d %d\n", min_element(a.begin(), a.end()) - a.begin() + 1, max_element(a.begin(), a.end()) - a.begin() + 1); 
  }
  return 0;
}