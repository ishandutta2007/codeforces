#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  
  int pairc;
  cin >> pairc;

  vector<pair<pair<int, int>, int>> asc;
  vector<pair<pair<int, int>, int>> desc;

  for (int i = 1; i <= pairc; i++) {
    int l, r;
    cin >> l >> r;

    if (l < r) {
      asc.push_back(make_pair(make_pair(r, l), i));
    } else {
      desc.push_back(make_pair(make_pair(r, l), i));
    }
  }

  if ((int) asc.size() > (int) desc.size()) {
    sort(asc.begin(), asc.end());
    reverse(asc.begin(), asc.end());

    cout << (int) asc.size() << '\n';
    for (int i = 0; i < (int) asc.size(); i++) {
      cout << asc[i].second << " ";
    }
    cout << '\n';
  } else {
    sort(desc.begin(), desc.end());

    cout << (int) desc.size() << '\n';
    for (int i = 0; i < (int) desc.size(); i++) {
      cout << desc[i].second << " ";
    }
    cout << '\n';
  }    
}