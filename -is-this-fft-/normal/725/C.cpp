#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> occ [200];

int main () {
  string arr;
  cin >> arr;

  for (int i = 0; i < (int) arr.size(); i++) {
    occ[arr[i]].push_back(i);
  }

  pair<int, int> rep = make_pair(-1, -1);
  for (char i = 'A'; i <= 'Z'; i++) {
    if ((int) occ[i].size() > 1) {
      if (occ[i].back() - occ[i].front() > 1) {
        rep = make_pair(occ[i].front(), occ[i].back());
        break;
      }
    }
  }

  if (rep.first == -1) {
    cout << "Impossible" << endl;
    return 0;
  }

  deque<int> ord;
  for (int i = 0; i < 27; i++) {
    if (i != rep.second) {
      ord.push_back(i);
    }
  }

  int avg = (rep.first + rep.second - 1) / 2;
  while (ord[12] != avg) {
    int temp = ord.back();
    ord.pop_back();
    ord.push_front(temp);
  }

  for (int i = 25; i >= 13; i--) {
    cout << arr[ord[i]];
  }
  cout << endl;
  for (int i = 0; i < 13; i++) {
    cout << arr[ord[i]];
  }
  cout << endl;
}