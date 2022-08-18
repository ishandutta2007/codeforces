#include <iostream>
#include <string>
#include <set>
#include <vector>

const int MAX_LEN = 2000005;

using namespace std;

vector<string> knowns;
vector<int> begins [MAX_LEN], endss [MAX_LEN];

int main () {
  ios::sync_with_stdio(false);

  int knownc;
  cin >> knownc;

  int length = 0;
  for (int i = 0; i < knownc; i++) {
    string k;
    cin >> k;
    knowns.push_back(k);

    int occ;
    cin >> occ;
    for (int j = 0; j < occ; j++) {
      int begins_at;
      cin >> begins_at;
      begins_at--;

      begins[begins_at].push_back(i);
      endss[begins_at + (int) k.size()].push_back(i);
      length = max(length, begins_at + (int) k.size());
    }
  }

  set<pair<int, int> > active;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < (int) begins[i].size(); j++) {
      active.insert(make_pair(begins[i][j], i));
    }

    for (int j = 0; j < (int) endss[i].size(); j++) {
      active.erase(make_pair(endss[i][j], i - knowns[endss[i][j]].size()));
    }

    if (active.empty()) {
      cout << 'a';
    } else {
      pair<int, int> pr = *active.begin();
      cout << knowns[pr.first][i - pr.second];
    }
  }
  cout << endl;
}