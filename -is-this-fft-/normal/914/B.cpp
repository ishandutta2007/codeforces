#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void win () {
  cout << "Conan" << endl;
  exit(0);
}

void lose () {
  cout << "Agasa" << endl;
  exit(0);
}

int main () {
  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<pair<int, int>> blocks;
  for (int u : arr) {
    if (blocks.empty() || u != blocks.back().first) {
      blocks.push_back(make_pair(u, 0));
    }
    blocks.back().second++;
  }

  for (auto b : blocks) {
    if (b.second % 2 == 1) {
      win();
    }
  }
  lose();
}