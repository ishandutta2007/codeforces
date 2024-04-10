#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << 0 << '\n';
  exit(0);
}

int sgn (int x) {
  if (x < 0) return -1;
  if (x == 0) return 0;
  return 1;
}

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> blocks; // -1 = desc, 1 = asc; <dir, len>
  for (int i = 1; i < n; i++) {
    int dir = sgn(arr[i] - arr[i - 1]);
    if (blocks.empty() || dir != blocks.back().first) {
      blocks.push_back(make_pair(dir, 0));
    }
    blocks.back().second++;
  }

  int k = blocks.size();
  pair<int, int> maxp = make_pair(-1, -1); // <height, pos>
  for (int i = 1; i < k; i++) {
    auto pre = blocks[i - 1];
    auto post = blocks[i];

    if (pre.first != 1 || post.first != -1) {
      continue;
    }

    maxp = max(maxp, make_pair(max(pre.second, post.second), i));
  }

  int qpos = maxp.second;
  if (qpos == -1) {
    failure();
  }

  for (int i = 0; i < k; i++) {
    if (i == qpos || i == qpos - 1) {
      continue;
    }

    if (blocks[i].second >= maxp.first) {
      failure();
    }
  }

  if (blocks[qpos].second != blocks[qpos - 1].second) {
    failure();
  }

  if (blocks[qpos].second % 2 == 1) {
    failure();
  }

  cout << 1 << endl;
}