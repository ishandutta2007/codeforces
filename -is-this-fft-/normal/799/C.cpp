#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct fountain {
  int beauty, cost, id;

  fountain (int _beauty, int _cost, int _id) {
    beauty = _beauty;
    cost = _cost;
    id = _id;
  }
};

bool operator< (fountain p, fountain q) {
  if (p.beauty == q.beauty) {
    return p.id < q.id;
  } else {
    return p.beauty > q.beauty;
  }
}

bool bycost (fountain p, fountain q) {
  return p.cost < q.cost;
}

int main () {
  ios::sync_with_stdio(false);

  int fountainc, coinc, diamondc;
  cin >> fountainc >> coinc >> diamondc;

  int maxc = -1, maxd = -1;
  vector<fountain> coinfs, diamondfs;
  set<fountain> coinbs, diamondbs;
  for (int i = 0; i < fountainc; i++) {
    int beauty, cost;
    char type;

    cin >> beauty >> cost >> type;
    if (type == 'C' && cost <= coinc) {
      maxc = max(maxc, beauty);
      coinfs.push_back(fountain(beauty, cost, i));
      coinbs.insert(fountain(beauty, cost, i));
    } else if (type == 'D' && cost <= diamondc) {
      maxd = max(maxd, beauty);
      diamondfs.push_back(fountain(beauty, cost, i));
      diamondbs.insert(fountain(beauty, cost, i));
    }
  }

  int ans = 0;
  if (maxc != -1 && maxd != -1) {
    ans = maxc + maxd;
  }

  if (coinfs.size() > 1) {
    sort(coinfs.begin(), coinfs.end(), bycost);
    int rptr = coinfs.size() - 1;

    for (int i = 0; i < rptr; i++) {
      coinbs.erase(coinfs[i]);

      while (i < rptr && coinfs[i].cost + coinfs[rptr].cost > coinc) {
        coinbs.erase(coinfs[rptr]);
        rptr--;
      }

      if (i == rptr) {
        break;
      }

      ans = max(ans, coinfs[i].beauty + (*coinbs.begin()).beauty);
    }
  }

  if (diamondfs.size() > 1) {
    sort(diamondfs.begin(), diamondfs.end(), bycost);
    int rptr = diamondfs.size() - 1;

    for (int i = 0; i < rptr; i++) {
      diamondbs.erase(diamondfs[i]);

      while (i < rptr && diamondfs[i].cost + diamondfs[rptr].cost > diamondc) {
        diamondbs.erase(diamondfs[rptr]);
        rptr--;
      }

      if (i == rptr) {
        break;
      }

      ans = max(ans, diamondfs[i].beauty + (*diamondbs.begin()).beauty);
    }
  }

  cout << ans << endl;
}