#include <iostream>
#include <algorithm>
#include <vector>

typedef long long llong;

using namespace std;

struct incr {
  llong index, add;

  incr () {
  }

  incr (llong _index, llong _add) {
    index = _index;
    add = _add;
  }
};

bool operator< (incr p, incr q) {
  if (p.index == q.index) {
    return p.add < q.add;
  }
  return p.index < q.index;
}

int main () {
  int height, questionc, correctc = 1;
  cin >> height >> questionc;

  vector<incr> cum;
  cum.push_back(incr(1LL << (height - 1), 1));
  cum.push_back(incr(2LL << (height - 1), -1));
  for (int i = 0; i < questionc; i++) {
    llong level, left, right, ans;
    cin >> level >> left >> right >> ans;
    if (ans == 0) {
      ans = -1;
    } else {
      correctc++;
    }

    cum.push_back(incr(left * (1LL << (height - level)), ans));
    cum.push_back(incr((right + 1) * (1LL << (height - level)), -ans));
  }

  sort(cum.begin(), cum.end());

  llong posc = 0, ans = -1, cur_cum = 0;
  for (int i = 0; i < (int) cum.size() - 1; i++) {
    cur_cum += cum[i].add;
    if (cum[i].index != cum[i + 1].index && cur_cum == correctc) {
      posc += cum[i + 1].index - cum[i].index;
      ans = cum[i].index;
    }
  }

  if (posc == 0) {
    cout << "Game cheated!" << endl;
  } else if (posc == 1) {
    cout << ans << endl;
  } else {
    cout << "Data not sufficient!" << endl;
  }
}