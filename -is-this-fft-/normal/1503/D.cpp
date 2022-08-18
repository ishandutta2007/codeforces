#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

struct Card {
  int x, y, id, cost;
};

const int MAX_N = 2e5 + 5;

bool byx (Card p, Card q) {
  return p.x < q.x;
}

bool byy (Card p, Card q) {
  return p.y < q.y;
}

int lninv [MAX_N];
int rninv [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int ans = 0;
  vector<Card> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
    if (arr[i].x > arr[i].y) {
      swap(arr[i].x, arr[i].y);
      arr[i].cost = -1;
      ans++;
    } else {
      arr[i].cost = 1;
    }
  }

  sort(arr.begin(), arr.end(), byx);

  for (int i = 0; i < n; i++) {
    arr[i].id = i;
  }

  sort(arr.begin(), arr.end(), byy);

  set<int> seen;
  for (auto c : arr) {
    seen.insert(c.id);
    lninv[c.id] = *seen.begin();
  }
  seen.clear();

  reverse(arr.begin(), arr.end());

  for (auto c : arr) {
    seen.insert(c.id);
    rninv[c.id] = *seen.rbegin();
  }

  sort(arr.begin(), arr.end(), byx);

  int cmx = 0;
  vector<int> black, white;
  int bcost = 0, wcost = 0;
  for (int i = 0; i < n; i++) {
    cmx = max(cmx, rninv[i]);

    if (lninv[i] != i && rninv[i] != i) {
      failure();
    }
    
    if (lninv[i] != i) {
      black.push_back(i);
      bcost += arr[i].cost;
    } else {
      white.push_back(i);
      wcost += arr[i].cost;
    }

    if (cmx == i) {
      if (bcost > wcost) {
        swap(black, white);
        swap(bcost, wcost);
      }

      for (int u : black) {
        swap(arr[u].x, arr[u].y);
      }

      ans += bcost;

      black.clear();
      white.clear();
      bcost = 0;
      wcost = 0;
    }
  }

  sort(arr.begin(), arr.end(), byx);
  for (int i = 0; i < n - 1; i++) {
    if (arr[i].y < arr[i + 1].y) {
      failure();
    }
  }

  cout << ans << endl;
}