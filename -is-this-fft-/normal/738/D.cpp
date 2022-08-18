#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
  int length, shipc, shipl, shotc;
  cin >> length >> shipc >> shipl >> shotc;

  string field;
  cin >> field;

  vector<int> ans (0);
  int curz = 0;
  for (int i = 0; i < (int) field.size(); i++) {
    if (field[i] == '1') {
      curz = 0;
    } else {
      curz++;
      if (curz == shipl) {
        ans.push_back(i);
        curz = 0;
      }
    }
  }

  cout << (int) ans.size() - shipc + 1 << endl;
  for (int i = 0; i < (int) ans.size() - shipc + 1; i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
}