#include <iostream>
#include <set>

using namespace std;

const int MAX_C = 1e5 + 5;

int arrf [MAX_C];
int arrs [MAX_C];
int poss [MAX_C];

int main () {
  ios::sync_with_stdio(false);

  int carc;
  cin >> carc;

  for (int i = 1; i <= carc; i++) {
    cin >> arrf[i];
  }
  
  for (int i = 1; i <= carc; i++) {
    cin >> arrs[i];
    poss[arrs[i]] = i;
  }

  int ans = 0;
  set<int> ord;
  for (int i = 1; i <= carc; i++) {
    ord.insert(poss[arrf[i]]);
    if (*ord.rbegin() != poss[arrf[i]]) {
      ans++;
    }
  }
  cout << ans << endl;
}