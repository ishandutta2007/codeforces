#include <iostream>

using namespace std;

const int MAX_N = 2e3 + 5;

int arr [MAX_N];
int suff_blocks [MAX_N][MAX_N];
int pref_blocks [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    // start times
    int bal = 0;
    for (int j = i; j <= n; j++) {
      if (arr[j] == 1) bal++;
      else bal--;

      suff_blocks[i][j - i + 1] = bal;
    }
  }

  for (int i = 1; i <= n; i++) {
    suff_blocks[n + 1][i] = -MAX_N * MAX_N;
  }

  for (int i = n; i >= 1; i--) {
    for (int k = 1; k <= n; k++) {
      suff_blocks[i][k] = max(suff_blocks[i][k], suff_blocks[i + 1][k]);
    }
  }
  
  for (int i = 1; i <= n; i++) {
    pref_blocks[i] = MAX_N * MAX_N;
  }

  int pref1 = 0, suff2 = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 2) suff2++;
  }

  int ans = suff2;
  for (int i = 1; i < n; i++) {
    // i is the last thing in the prefix
    if (arr[i] == 1) pref1++;
    if (arr[i] == 2) suff2--;
    ans = max(ans, pref1 + suff2);

    int bal = 0;
    for (int j = i; j >= 1; j--) {
      // look at all the prefix-blocks we have created
      if (arr[j] == 1) bal++;
      else bal--;

      int k = i - j + 1;
      int bbal = suff_blocks[i + 1][k];
      ans = max(ans, pref1 + suff2 + bbal - bal);
      pref_blocks[k] = min(pref_blocks[k], bal);
    }

    bal = 0;
    for (int j = i + 1; j <= n; j++) {
      if (arr[j] == 1) bal++;
      else bal--;

      int k = j - (i + 1) + 1;
      int bbal = pref_blocks[k];
      ans = max(ans, pref1 + suff2 - bbal + bal);
    }
  }

  if (arr[n] == 1) pref1++;
  ans = max(ans, pref1);

  cout << ans << endl;
}