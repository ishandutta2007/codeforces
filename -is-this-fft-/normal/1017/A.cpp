#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare (pair<int, int> p, pair<int, int> q) {
  if (p.first == q.first) {
    return p.second < q.second;
  }
  return p.first > q.first;
}

int main () {
  int length;
  cin >> length;

  vector<pair<int, int>> studs (length, make_pair(0, 0));
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < 4; j++) {
      int score;
      cin >> score;

      studs[i].first += score;
    }

    studs[i].second = i + 1;
  }

  sort(studs.begin(), studs.end(), compare);

  for (int i = 0; i < length; i++) {
    if (studs[i].second == 1) {
      cout << i + 1 <<  endl;
      return 0;
    }
  }
}