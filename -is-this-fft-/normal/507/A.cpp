#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int instrc, dayc;
  cin >> instrc >> dayc;

  vector<pair<int, int> > instruments (instrc);
  for (int i = 0; i < instrc; i++) {
    cin >> instruments[i].first;
    instruments[i].second = i + 1;
  }

  sort(instruments.begin(), instruments.end());

  vector<int> ans;
  for (int i = 0; i < (int) instruments.size(); i++) {
    if (dayc >= instruments[i].first) {
      dayc -= instruments[i].first;
      ans.push_back(instruments[i].second);
    }
  }

  cout << (int) ans.size() << endl;
  for (int idx : ans) {
    cout << idx << " ";
  }
  cout << endl;
}