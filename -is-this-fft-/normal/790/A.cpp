#include <iostream>
#include <string>
#include <vector>

using namespace std;

string name (int index) {
  string ans;
  if (index < 26) {
    ans = "A";
  } else {
    ans = "B";
  }

  ans += 'a' + (index % 26);
  return ans;
}

int main () {
  int length, groups;
  cin >> length >> groups;

  vector<string> ans (length);
  string first;
  cin >> first;
  if (first == "YES") {
    for (int i = 0; i < groups; i++) {
      ans[i] = name(i);
    }
  } else {
    for (int i = 0; i < groups - 1; i++) {
      ans[i] = name(i);
    }
    ans[groups - 1] = ans[0];
  }

  for (int i = groups; i < length; i++) {
    string match;
    cin >> match;

    if (match == "YES") {
      ans[i] = name(i);
    } else {
      ans[i] = ans[i - (groups - 1)];
    }
  }

  for (int i = 0; i < length; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}