#include <iostream>
#include <vector>

const int MAX_REQ = 100000;
const int MAX_ANS = 1000000;

using namespace std;

int zeroc [MAX_ANS];

int main () {
  zeroc[5] = 1;
  for (int i = 6; i < MAX_ANS; i++) {
    zeroc[i] = zeroc[i - 1];
    for (int j = i; j % 5 == 0; j /= 5) {
      zeroc[i]++;
    }
  }

  int zreq;
  cin >> zreq;
  vector<int> ans (0);
  for (int i = 0; i < MAX_ANS; i++) {
    if (zeroc[i] == zreq) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
  }
}