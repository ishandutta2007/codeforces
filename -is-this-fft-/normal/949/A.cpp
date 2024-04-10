#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> seq [MAX_N];

int main () {
  int seqc = 0;

  string s;
  cin >> s;

  vector<int> cur0;
  vector<int> cur1;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '0') {
      if (cur1.empty()) {
        seq[seqc].push_back(i);
        cur0.push_back(seqc);
        seqc++;
      } else {
        int t = cur1.back();
        seq[t].push_back(i);
        cur1.pop_back();
        cur0.push_back(t);
      }
    } else {
      if (cur0.empty()) {
        cout << -1 << endl;
        return 0;
      } else {
        int t = cur0.back();
        seq[t].push_back(i);
        cur0.pop_back();
        cur1.push_back(t);
      }
    }
  }

  if (!cur1.empty()) {
    cout << -1 << endl;
    return 0;
  }
  
  cout << seqc << endl;
  for (int i = 0; i < seqc; i++) {
    cout << seq[i].size();
    for (int u : seq[i]) {
      cout << " " << u + 1;
    }
    cout << '\n';
  }
}