#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 4e5 + 5;
int arr [MAX_N];

void solve () {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  vector<int> blocks;
  for (int i = 0; i < N; i++) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      blocks.push_back(0);
    }
    blocks.back()++;
  }

  int rem = N;
  while (rem > N / 2) {
    rem -= blocks.back();
    blocks.pop_back();
  }

  if ((int) blocks.size() < 3) {
    cout << "0 0 0" << '\n';
    return;
  }

  set<int> ends;
  ends.insert(blocks[0]);
  for (int i = 1; i < (int) blocks.size(); i++) {
    blocks[i] += blocks[i - 1];
    ends.insert(blocks[i]);
  }

  vector<int> sol = {0, 0, 0};
  for (int i = 0; i < (int) blocks.size(); i++) {
    int g = blocks[i];
    int gsm = 2 * blocks[i] + 1;
    auto lb = ends.lower_bound(gsm);
    if (lb != ends.end()) {
      int gs = *lb;
      int b = rem - gs;
      if (g < b) {
        sol = {g, gs - g, b};
      }
    }
  }
  cout << sol[0] << " " << sol[1] << " " << sol[2] << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}