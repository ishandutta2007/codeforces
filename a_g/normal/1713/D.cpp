#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int ans;
  cin >> ans;
  return ans;
}

void answer(int x) {
  cout << "! " <<  x << endl;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> players(1<<n);
    iota(players.begin(), players.end(), 1);
    while ((int)players.size() >= 4) {
      vector<int> winners;
      for (int i = 0; i < (int)players.size(); i += 4) {
        int k = query(players[i], players[i+2]);
        if (k == 2) {
          winners.push_back(query(players[i+1], players[i+2]) == 1 ?
              players[i+1] : players[i+2]);
        }
        else if (k == 1) {
          winners.push_back(query(players[i], players[i+3]) == 1 ?
              players[i] : players[i+3]);
        }
        else {
          winners.push_back(query(players[i+1], players[i+3]) == 1 ?
              players[i+1] : players[i+3]);
        }
      }
      players = winners;
    }
    if ((int)players.size() == 1) {
      answer(players[0]);
    }
    else {
      assert((int)players.size() == 2);
      answer(players[query(players[0], players[1])-1]);
    }
  }
}