#include <iostream>
#include <set>
#include <vector>

const int MAX_TOY = 200005;

using namespace std;

int main () {
  int toyc, maxmon;
  cin >> toyc >> maxmon;

  set<int> owned;
  for (int i = 0; i < toyc; i++) {
    int toy;
    cin >> toy;
    owned.insert(toy);
  }

  long long cur = 0;
  vector<int> ans;
  for (int i = 1; i < MAX_TOY; i++) {
    if (cur + i <= maxmon &&
        owned.find(i) == owned.end()) {
      ans.push_back(i);
      cur += i;
    }
  }

  cout << (int) ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}