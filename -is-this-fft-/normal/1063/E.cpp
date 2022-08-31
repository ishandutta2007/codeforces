#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

const int MAX_N = 1e3 + 5;

int targ [MAX_N];
char grid [MAX_N][MAX_N];

int cur;
void shift_right (vector<int> idxs) {
  grid[cur][0] = '\\';
  grid[cur][idxs.back()] = '\\';
  cur++;

  grid[cur][0] = '/';
  for (int i : idxs) {
    grid[cur][i] = '/';
  }
  cur++;

  int tmp = targ[idxs.back()];
  for (int i = (int) idxs.size() - 1; i > 0; i--) {
    targ[idxs[i]] = targ[idxs[i - 1]];
  }
  targ[idxs[0]] = tmp;
}

bool right_ok (vector<int> idxs) {
  int cnt = 0;
  for (int i = (int) idxs.size() - 1; i > 0; i--) {
    if (idxs[i] == targ[idxs[i - 1]]) cnt++;
  }
  if (idxs[0] == targ[idxs.back()]) cnt++;

  return cnt > 1;
}

void shift_left (vector<int> idxs) {
  grid[cur][0] = '\\';
  for (int i : idxs) {
    grid[cur][i] = '\\';
  }
  cur++;

  grid[cur][0] = '/';
  grid[cur][idxs.back()] = '/';
  cur++;

  int tmp = targ[idxs[0]];
  for (int i = 0; i < (int) idxs.size() - 1; i++) {
    targ[idxs[i]] = targ[idxs[i + 1]];
  }
  targ[idxs.back()] = tmp;
}

bool left_ok (vector<int> idxs) {
  int cnt = 0;
  for (int i = 0; i < (int) idxs.size() - 1; i++) {
    if (idxs[i] == targ[idxs[i + 1]]) cnt++;
  }
  if (idxs.back() == targ[idxs[0]]) cnt++;

  return cnt > 1;
}

void shift_tar0 (int tar0, int pre) {
  if (pre < tar0) {
    grid[cur][0] = '\\';
    grid[cur][tar0] = '\\';
    cur++;

    grid[cur][pre] = '/';
    grid[cur][tar0] = '/';
    cur++;
  } else {
    grid[cur][0] = '\\';
    grid[cur][pre] = '\\';
    grid[cur][tar0] = '\\';
    cur++;
  }
}

void shift_tar0 (int tar0) {
  grid[cur][0] = '\\';
  grid[cur][tar0] = '\\';
}

int main () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = '.';
    }
  }
  
  bool perf = true;
  for (int i = 0; i < n; i++) {
    cin >> targ[i];
    targ[i]--;
    if (targ[i] != i) {
      perf = false;
    }
  }

  if (perf) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << '.';
      }
      cout << '\n';
    }
    return 0;
  }

  while (true) {
    int st = -1;
    for (int i = 1; i < n; i++) {
      if (targ[i] != i && targ[i] != 0 && targ[targ[i]] != 0) {
        st = i;
      }
    }

    if (st != -1) {
      if (targ[targ[st]] == st) {
        vector<int> sub = {st, targ[st]};
        sort(sub.begin(), sub.end());
        shift_right(sub);
      } else {
        vector<int> sub = {st, targ[st], targ[targ[st]]};
        sort(sub.begin(), sub.end());

        if (right_ok(sub)) {
          shift_right(sub);
        } else if (left_ok(sub)) {
          shift_left(sub);
        } else {
          assert(false);
        }
      }
      continue;
    }

    for (int i = 1; i < n; i++) {
      if (targ[i] != i && targ[i] != 0) {
        st = i;
      }
    }

    if (st != -1) {
      shift_tar0(targ[st], st);
      break;
    }

    for (int i = 1; i < n; i++) {
      if (targ[i] != i) {
        st = i;
      }
    }

    if (st != -1) {
      shift_tar0(st);
      break;
    } else {
      // we are done!
      break;
    }
  }

  cout << n - 1 << endl;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
}