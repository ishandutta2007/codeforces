#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector <int> in(N);
  for (auto &it : in)
    scanf("%d", &it);
  printf("%d\n", accumulate(in.begin(), in.end(), 0));
  return 0;
}