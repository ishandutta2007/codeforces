#include <bits/stdc++.h>

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

struct point {
  static int X, Y, Z;

  int x, y, z;

  point() : x(), y(), z() {}

  point(int id) : x(id / (Y * Z)), y(id / Z % Y), z(id % Z) {}

  point(int t_x, int t_y, int t_z) : x(t_x), y(t_y), z(t_z) {}

  point next(int dir) const {
    return point(x + dx[dir], y + dy[dir], z + dz[dir]);
  }

  bool valid() const {
    return 0 <= x && x < X && 0 <= y && y < Y && 0 <= z && z < Z;
  }

  int id() const {
    return x * Y * Z + y * Z + z;
  }

  static int total() {
    return X * Y * Z;
  }
};

int point::X, point::Y, point::Z;

struct sensor {
  point p;
  int dir;
  int col;

  sensor() : p(), dir(), col() {}

  sensor(point t_p, int t_dir, int t_col) : p(t_p), dir(t_dir), col(t_col) {}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> point::X >> point::Y >> point::Z;

  std::vector<int> a(point::total(), -1);
  std::vector<std::vector<int>> b(point::total());

  std::queue<sensor> Q;

  auto erase = [&](int id) {
    point t(id);
    for (int d : b[id]) {
      point nx = t.next(d);
      if (nx.valid()) {
        Q.emplace(nx, d, a[id]);
      }
    }
    b[id].clear();
    a[id] = 0;
  };

  for (int i = 0; i < point::Y; ++i) {
    for (int j = 0; j < point::Z; ++j) {
      int c;
      std::cin >> c;
      Q.emplace(point(0, i, j), 0, c);
    }
  }
  for (int i = 0; i < point::Y; ++i) {
    for (int j = 0; j < point::Z; ++j) {
      int c;
      std::cin >> c;
      Q.emplace(point(point::X - 1, i, j), 1, c);
    }
  }
  for (int i = 0; i < point::X; ++i) {
    for (int j = 0; j < point::Z; ++j) {
      int c;
      std::cin >> c;
      Q.emplace(point(i, 0, j), 2, c);
    }
  }
  for (int i = 0; i < point::X; ++i) {
    for (int j = 0; j < point::Z; ++j) {
      int c;
      std::cin >> c;
      Q.emplace(point(i, point::Y - 1, j), 3, c);
    }
  }
  for (int i = 0; i < point::X; ++i) {
    for (int j = 0; j < point::Y; ++j) {
      int c;
      std::cin >> c;
      Q.emplace(point(i, j, 0), 4, c);
    }
  }
  for (int i = 0; i < point::X; ++i) {
    for (int j = 0; j < point::Y; ++j) {
      int c;
      std::cin >> c;
      Q.emplace(point(i, j, point::Z - 1), 5, c);
    }
  }
  
  while (!Q.empty()) {
    auto now = Q.front();
    Q.pop();
    if (!now.col) {
      while (now.p.valid()) {
        erase(now.p.id());
        now.p = now.p.next(now.dir);
      }
    } else {
      bool ok = false;
      while (now.p.valid()) {
        if (a[now.p.id()] != -1 && a[now.p.id()] != now.col) {
          erase(now.p.id());
        } else {
          ok = true;
          a[now.p.id()] = now.col;
          b[now.p.id()].push_back(now.dir);
          break;
        }
        now.p = now.p.next(now.dir);
      }
      if (!ok) {
        std::cout << -1 << "\n";
        return 0;
      }
    }
  }

  for (int i = 0; i < point::X; ++i) {
    for (int j = 0; j < point::Y; ++j) {
      for (int k = 0; k < point::Z; ++k) {
        int c = a[point(i, j, k).id()];
        if (c == -1) {
          c = 0;
        }
        std::cout << c << " \n"[k + 1 == point::Z];
      }
    }
    if (i + 1 < point::X) {
      std::cout << "\n";
    }
  }
}