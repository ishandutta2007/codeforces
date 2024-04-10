#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 2e5 + 5;

char mxcl [MAX_N];

int main () {
  int n, k;
  cin >> n >> k;

  string str;
  cin >> str;

  bool pfx_ok = true;
  bool passed = false;
  for (int i = 0; i < n; i++) {
    if (str[i % k] < str[i] && !passed) {
      pfx_ok = false;
    } else if (str[i % k] > str[i]) {
      passed = true;
    }
  }

  if (pfx_ok) {
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << str[i % k];
    }
    cout << '\n';
    return 0;
  }

  for (int i = k - 1; i >= 0; i--) {
    str[i]++;
    if (str[i] == '9' + 1) {
      str[i] = '0';
    } else {
      break;
    }
  }
  
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << str[i % k];
  }
  cout << '\n';  
}