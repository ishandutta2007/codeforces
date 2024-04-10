#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_B = 24;

short ans [1 << MAX_B];
int cur [MAX_B];

int main () {
  int tripc;
  cin >> tripc;

  for (int i = 1; i <= tripc; i++) {
    string triple;
    cin >> triple;

    for (char c : triple) {
      cur[c - 'a'] = i;
    }
    vector<int> cur_uniq;
    for (int j = 0; j < MAX_B; j++) {
      if (cur[j] == i) {
        cur_uniq.push_back(j);
      }
    }

    ans[1 << cur_uniq[0]]++;
    if ((int) cur_uniq.size() >= 2) {
      ans[1 << cur_uniq[1]]++;
      ans[(1 << cur_uniq[0]) | (1 << cur_uniq[1])]--;
    }

    if ((int) cur_uniq.size() >= 3) {
      ans[1 << cur_uniq[2]]++;
      ans[(1 << cur_uniq[0]) | (1 << cur_uniq[2])]--;
      ans[(1 << cur_uniq[1]) | (1 << cur_uniq[2])]--;
      ans[(1 << cur_uniq[0]) | (1 << cur_uniq[1]) | (1 << cur_uniq[2])]++;
    }
  }

  for (int k = 0; k < MAX_B; k++) {
    int m = 1 << k;
    for (int i = 0; i < 1 << MAX_B; i++) {
      if (i & m) {
        ans[i] += ans[i - m];
      }
    }
  }

  int res = 0;
  for (int i = 0; i < 1 << MAX_B; i++) {
    res ^= (int) ans[i] * (int) ans[i];
  }
  cout << res << endl;
}