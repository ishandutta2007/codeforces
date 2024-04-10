#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    string s;
    cin >> s;
    int N = s.size();
    vector <int> blocks;
    int len = 0;
    for (int i = 0; i < N; i++) {
      len++;
      if (i == N - 1 || s[i] != s[i + 1]) {
        if (s[i] == '1')
          blocks.push_back(len);
        len = 0;
      }
    }
    sort(blocks.begin(), blocks.end(), greater <int> ());
    int alice = 0;
    for (int i = 0; i < blocks.size(); i += 2)
      alice += blocks[i];
    printf("%d\n", alice);
  }
  return 0;
}