#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 100005;

ll piles [MAX_N];

int main () {
  ll pilec;
  cin >> pilec;

  ll losingCnt = (pilec * (pilec - 1) / 2);
  // cerr << losingCnt << endl;
  ll pileSum = 0;
  for (int i = 0; i < pilec; i++) {
    cin >> piles[i];
    pileSum += piles[i];
  }

  // check if we can make a valid first move
  sort(piles, piles + pilec);
  vector<pair<int, int>> blocks;
  for (int i = 0; i < pilec; i++) {
    if (i == 0 || piles[i] != piles[i - 1]) {
      blocks.push_back(make_pair(piles[i], 1));
    } else {
      blocks.back().second++;
    }
  }

  int doublec = 0;
  bool valid = true;
  for (int i = 0; i < (int) blocks.size(); i++) {
    if (blocks[i].second > 2) {
      doublec += 2;
    } else if (blocks[i].second == 2) {
      doublec++;
      if (i != 0 && blocks[i - 1].first + 1 == blocks[i].first) {
        valid = false;
      } else if (i == 0 && blocks[i].first == 0) {
        valid = false;
      }
    }
  }

  if (doublec > 1 || !valid) {
    cout << "cslnb" << endl;
  } else if (pileSum % 2 == losingCnt % 2) {
    cout << "cslnb" << endl;
  } else {
    cout << "sjfnb" << endl;
  }
}