#include <iostream>
#include <string>
#include <vector>

using namespace std;

string inverse (string vec) {
  string ans = "";
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == '+') {
      ans += '*';
    } else {
      ans += '+';
    }
  }
  return ans;
}


int main () {
  ios::sync_with_stdio(false);

  int exponent;
  
  cin >> exponent;
  vector<string> ans (1, "+");

  for (int i = 0; i < exponent; i++) {
    int asize = ans.size();
    for (int j = 0; j < asize; j++) {
      ans.push_back(ans[j] + inverse(ans[j]));
      ans[j] += ans[j];
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}