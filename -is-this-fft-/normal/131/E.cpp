#include <iostream>
#include <algorithm>

const int MAX_QUEEN = 100005;

using namespace std;

int cnt [9];

struct queen {
  int row, col, ans;

  void update () {
    ans++;
    cnt[ans - 1]--;
    cnt[ans]++;
  }
} queens [MAX_QUEEN];

bool horizord (queen p, queen q) {
  if (p.row == q.row) {
    return p.col < q.col;
  } else {
    return p.row < q.row;
  }
}

bool verticord (queen p, queen q) {
  if (p.col == q.col) {
    return p.row < q.row;
  } else {
    return p.col < q.col;
  }
}

bool mdiagord (queen p, queen q) {
  if (p.row - p.col == q.row - q.col) {
    return p.row < q.row;
  } else {
    return p.row - p.col < q.row - q.col;
  }
}

bool sdiagord (queen p, queen q) {
  if (p.row + p.col == q.row + q.col) {
    return p.row < q.row;
  } else {
    return p.row + p.col < q.row + q.col;
  }
}

int main () {
  int width, queenc;
  cin >> width >> queenc;

  for (int i = 0; i < queenc; i++) {
    cin >> queens[i].row >> queens[i].col;
  }

  cnt[0] = queenc;
  sort(queens, queens + queenc, horizord);
  for (int i = 0; i < queenc; i++) {
    if (i != 0 && queens[i].row == queens[i - 1].row) {
      queens[i].update();
    }

    if (i != queenc - 1 && queens[i].row == queens[i + 1].row) {
      queens[i].update();
    }
  }

  sort(queens, queens + queenc, verticord);
  for (int i = 0; i < queenc; i++) {
    if (i != 0 && queens[i].col == queens[i - 1].col) {
      queens[i].update();
    }

    if (i != queenc - 1 && queens[i].col == queens[i + 1].col) {
      queens[i].update();
    }
  }

  sort(queens, queens + queenc, mdiagord);
  for (int i = 0; i < queenc; i++) {
    if (i != 0 && 
        queens[i].row - queens[i].col == queens[i - 1].row - queens[i - 1].col) {
      queens[i].update();
    }

    if (i != queenc - 1 &&
        queens[i].row - queens[i].col == queens[i + 1].row - queens[i + 1].col) {
      queens[i].update();
    }
  }

  sort(queens, queens + queenc, sdiagord);
  for (int i = 0; i < queenc; i++) {
    if (i != 0 &&
        queens[i].row + queens[i].col == queens[i - 1].row + queens[i - 1].col) {
      queens[i].update();
    }

    if (i != queenc - 1 &&
        queens[i].row + queens[i].col == queens[i + 1].row + queens[i + 1].col) {
      queens[i].update();
    }
  }

  for (int i = 0; i <= 8; i++) {
    cout << cnt[i] << (i == 8 ? '\n' : ' ');
  }
}