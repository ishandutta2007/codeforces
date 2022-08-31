#include <iostream>
#include <string>

using namespace std;

void solve () {
  string s;
  cin >> s;

  int zc = 0, ec = 0, sum = 0;
  for (char c : s) {
    sum += c - '0';
    if (c == '0') {
      zc++;
    }
    if ((c - '0') % 2 == 0) {
      ec++;
    }
  }

  if (zc > 0 && ec > 1 && sum % 3 == 0){
    cout << "red" << '\n';
  } else {
    cout << "cyan" << '\n';
  }
}

int main (){
  ios::sync_with_stdio(false);

  int testc;
  cin >>testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}