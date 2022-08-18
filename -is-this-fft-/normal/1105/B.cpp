#include <iostream>
#include <string>

using namespace std;

int streak [200];
int cnt [200];

int main () {
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;

  string str;
  cin >> str;

  for (int i = 0; i < n; i++) {
    char c = str[i];
    if (i == 0 || str[i] != str[i - 1]) {
      streak[c] = 1;
    } else {
      streak[c]++;
    }
    
    if (streak[c] == k) {
      cnt[c]++;
      streak[c] = 0;
    }
  }

  int ans = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    ans = max(ans, cnt[c]);
  }

  cout << ans << endl;
}