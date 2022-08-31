#include <iostream>
#include <queue>
#include <vector>

const int MAX_WIDTH = 305;
const int MAX_L = 6;
const int DIR = 8;
const int MAX_GEN = 31;

using namespace std;

int visv [MAX_WIDTH][MAX_WIDTH][DIR];
int visq [MAX_WIDTH][MAX_WIDTH];
int length [MAX_GEN];
int nx [DIR] = {0, 1, 1, 1, 0, -1, -1, -1};
int ny [DIR] = {1, 1, 0, -1, -1, -1, 0, 1};

struct firework {
  int x, y, len, dir, gen;

  firework () {
  }

  firework (int _x, int _y, int _dir, int _gen) {
    x = _x;
    y = _y;
    dir = _dir;
    gen = _gen;
  }

  bool isset () {
    return visv[x][y][dir] & (1 << gen);
  }

  void set () {
    visv[x][y][dir] |= 1 << gen;
  }
};

int main () {
  int genc;
  cin >> genc;

  for (int i = 0; i < genc; i++) {
    cin >> length[i];
  }

  queue<firework> que;
  que.push(firework(152, 152, 0, 0));
  while (!que.empty()) {
    firework qtop = que.front();
    que.pop();

    for (int i = 0; i < length[qtop.gen]; i++) {
      visq[qtop.x][qtop.y] = 1;

      if (i < length[qtop.gen] - 1) {
        qtop.x += nx[qtop.dir];
        qtop.y += ny[qtop.dir];
      }
    }

    if (qtop.gen != genc - 1) {
      firework lchild (qtop.x, qtop.y, (qtop.dir - 1 + DIR) % DIR, qtop.gen + 1);
      lchild.x += nx[lchild.dir];
      lchild.y += ny[lchild.dir];

      if (!lchild.isset()) {
        lchild.set();
        que.push(lchild);
      }

      firework rchild (qtop.x, qtop.y, (qtop.dir + 1 + DIR) % DIR, qtop.gen + 1);
      rchild.x += nx[rchild.dir];
      rchild.y += ny[rchild.dir];
      
      if (!rchild.isset()) {
        rchild.set();
        que.push(rchild);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < MAX_WIDTH; i++) {
    for (int j = 0; j < MAX_WIDTH; j++) {
      ans += visq[i][j];
    }
  }

  cout << ans << endl;
}