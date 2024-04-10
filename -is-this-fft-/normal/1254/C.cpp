#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

ll area (int i, int j, int k) {
  cout << 1 << " " << i << " " << j << " " << k << '\n';
  ll ans;
  cin >> ans;
  return ans;
}

int orient (int i, int j, int k) {
  cout << 2 << " " << i << " " << j << " " << k << '\n';
  int ans;
  cin >> ans;
  return ans;
}

void report (deque<int> v) {
  cout << 0;
  for (int u : v) {
    cout << " " << u;
  }
  cout << '\n';
  exit(0);
}

const int MAX_N = 1005;

ll x [MAX_N];
int upper [MAX_N];

bool comp (int p, int q) {
  return x[p] < x[q];
}

int main () {
  int pointc;
  cin >> pointc;

  if (pointc == 3) {
    if (orient(1, 2, 3) == 1) {
      cout << "0 1 2 3" << endl;
    } else {
      cout << "0 1 3 2" << endl;
    }
    return 0;
  }
  
  int u = 1 + rand() % pointc;
  int v = 1 + rand() % pointc;
  while (v == u) {
    v = 1 + rand() % pointc;
  }

  for (int i = 1; i <= pointc; i++) {
    if (i != u && i != v) {
      x[i] = area(i, u, v);
      x[i] *= orient(u, v, i);
    }
  }

  int minx = u, maxx = v;
  for (int i = 1; i <= pointc; i++) {
    if (x[i] >= x[maxx]) {
      maxx = i;
    }

    if (x[i] <= x[minx]) {
      minx = i;
    }
  }

  for (int i = 1; i <= pointc; i++) {
    if (i != minx && i != maxx) {
      upper[i] = (orient(minx, maxx, i) > 0);
    }
  }

  vector<int> uppers;
  vector<int> lowers;

  for (int i = 1; i <= pointc; i++) {
    if (i != minx && i != maxx) {
      if (upper[i]) {
        uppers.push_back(i);
      } else {
        lowers.push_back(i);
      }
    }
  }

  sort(uppers.begin(), uppers.end(), comp);
  sort(lowers.begin(), lowers.end(), comp);
  reverse(uppers.begin(), uppers.end());

  deque<int> dq;
  dq.push_back(minx);
  for (int u : lowers) {
    dq.push_back(u);
  }
  dq.push_back(maxx);
  for (int u : uppers) {
    dq.push_back(u);
  }

  while (dq[0] != 1) {
    int bk = dq.back();
    dq.pop_back();
    dq.push_front(bk);
  }

  report(dq);
}