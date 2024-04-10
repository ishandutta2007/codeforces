#include <bits/stdc++.h>
using namespace std;

const int N = 18;
int ind[1<<N], ord[1<<N], tmp[1<<N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int m = 1<<n;
  iota(ord, ord+m, 0);
  for (int i = 0; i < m; i++) ind[i] = s[i];
  for (int i = 0; i < n; i++) {
    int z = 1<<i;
    sort(ord, ord+m, [&] (int x, int y) {
        return ind[x] < ind[y] || (ind[x] == ind[y]) && ind[x^z] < ind[y^z];
        });
    tmp[ord[0]] = 0;
    for (int j = 1; j < m; j++) {
      if (ind[ord[j]] == ind[ord[j-1]] && ind[ord[j]^z] == ind[ord[j-1]^z]) {
        tmp[ord[j]] = tmp[ord[j-1]];
      }
      else {
        tmp[ord[j]] = tmp[ord[j-1]]+1;
      }
    }
    for (int j = 0; j < m; j++) {
      ind[j] = tmp[j];
    }
  }

  for (int i = 0; i < (1<<n); i++) {
    cout << s[i^ord[0]];
  }
  cout << '\n';
}