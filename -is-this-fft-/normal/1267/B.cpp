#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
  string s;
  cin >> s;

  vector<pair<char, int>> blocks;
  for (char c : s) {
    if (blocks.empty() || c != blocks.back().first) {
      blocks.push_back(make_pair(c, 0));
    }
    blocks.back().second++;
  }

  if ((int) blocks.size() % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }

  int N = (int) blocks.size();
  for (int i = 0; i < N / 2; i++) {
    if (blocks[i].first != blocks[N - i - 1].first) {
      cout << 0 << endl;
      return 0;
    }

    if (blocks[i].second + blocks[N - i - 1].second < 3) {
      cout << 0 << endl;
      return 0;
    }
  }

  if (blocks[N / 2].second < 2) {
    cout << 0 << endl;
  } else {
    cout << blocks[N / 2].second + 1 << endl;
  }
}