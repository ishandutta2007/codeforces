#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string a, b;
    std::cin >> a >> b;

    int n = a.length();

    int last[2][26];
    for(int i = 0; i < 26; i++)
      last[0][i] = last[1][i] = n;

    int next[n][26];
    for(int i = n-1; i >= 0; i--) {
      for(int j = 0; j < 26; j++)
        next[i][j] = last[!(i%2)][j];
      last[i%2][a[i]-'a'] = i;
    }

    int poss = 0;
    int k = b.length();
    for(int m = 0; m < 2; m++) {
      int f = last[m][b[0]-'a'];
      int i = 1;
      while(f < n && i < k) {
        f = next[f][b[i++]-'a'];
      }

      if(f < n && (n-f)%2 == 1)
        poss = 1;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}