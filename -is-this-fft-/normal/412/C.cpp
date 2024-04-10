#include <iostream>
#include <string>

const int MAX_LEN = 100005;

using namespace std;

char ans [MAX_LEN];

int main () {
  ios::sync_with_stdio(false);

  int stringc, length;
  cin >> stringc;

  for (int i = 0; i < stringc; i++) {
    string cur;
    cin >> cur;

    length = cur.size();

    for (int j = 0; j < (int) cur.size(); j++) {
      if (cur[j] != '?') {
        if (cur[j] != ans[j]) {
          if (ans[j] == 0) {
            ans[j] = cur[j];
          } else {
            ans[j] = '?';
          }
        }
      }
    }
  }

  for (int i = 0; i < length; i++) {
    cout << (ans[i] == 0 ? 'a' : ans[i]);
  }
  cout << endl;
}