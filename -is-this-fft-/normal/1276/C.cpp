#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 4e5 + 5;

int cnt_ge [MAX_N];
int sum_ge [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;
  
  vector<int> arr (length);
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<pair<int, int>> blocks;
  for (int i = 0; i < length; i++) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      blocks.push_back({0, arr[i]});
    }
    blocks.back().first++;
  }

  sort(blocks.begin(), blocks.end());
  for (auto pr : blocks) {
    cnt_ge[pr.first]++;
    sum_ge[pr.first] += pr.first;
  }

  for (int i = MAX_N - 1; i >= 0; i--) {
    cnt_ge[i] += cnt_ge[i + 1];
    sum_ge[i] += sum_ge[i + 1];
  }

  pair<int, int> ans = {0, 0};
  for (int i = 1; i <= length; i++) { // group size
    int width = (length - sum_ge[i] + i * cnt_ge[i]) / i;
    if (width >= i) {
      ans = max(ans, {i * width, i});
    }
  }

  reverse(blocks.begin(), blocks.end());
  int grsz = ans.second;
  for (int i = 0; i < (int) blocks.size(); i++) {
    blocks[i].first = min(blocks[i].first, grsz);
  }

  vector<int> ansl;
  for (auto pr : blocks) {
    for (int i = 0; i < pr.first; i++) {
      ansl.push_back(pr.second);
    }
  }

  while ((int) ansl.size() % grsz != 0) {
    ansl.pop_back();
  }

  vector<vector<int>> anst (1, vector<int> (0));
  for (auto u : ansl) {
    if ((int) anst.back().size() == grsz) {
      anst.push_back(vector<int> (0));
    }
    anst.back().push_back(u);
  }

  cout << anst.size() * anst[0].size() << '\n';
  cout << anst.size() << " " << anst[0].size() << '\n';
  for (int i = 0; i < (int) anst.size(); i++) {
    for (int j = 0; j < grsz; j++) {
      cout << anst[(i - j + (int) anst.size()) % (int) anst.size()][j] << " ";
    }
    cout << '\n';
  }
}