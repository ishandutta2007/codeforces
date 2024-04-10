#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

int main () {
  string s;
  cin >> s;

  int state = -1;
  vector<int> cnt (3, 0);

  for (char c : s) {
    int cur = c - 'a';

    if (cur == state) {
      cnt[cur]++;
    } else if (state != 2 && cur == state + 1) {
      state++;
      cnt[cur]++;
    } else {
      failure();
    }
  }

  if (state != 2) failure();
  if (cnt[2] != cnt[1] && cnt[2] != cnt[0]) failure();

  cout << "YES" << endl;
}