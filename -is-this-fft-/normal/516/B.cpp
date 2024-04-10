#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "Not unique" << endl;
  exit(0);
}

const int MAX_N = 2e3 + 5;

char grid [MAX_N][MAX_N];
int taken_nb [MAX_N][MAX_N];

int ni [4] = {1, 0, -1, 0};
int nj [4] = {0, 1, 0, -1};

vector<pair<int, int>> nxt;

int takenc;
void take (int i, int j) {
  takenc++;
  for (int k = 0; k < 4; k++) {
    int u = i + ni[k];
    int v = j + nj[k];
    taken_nb[u][v]++;
    if (taken_nb[u][v] == 3 && grid[u][v] == '.') nxt.push_back(make_pair(u, v));
  }
}

void process (pair<int, int> pr) {
  int x = pr.first;
  int y = pr.second;
  if (taken_nb[x][y] != 3 || grid[x][y] != '.') return;

  if (grid[x + 1][y] == '.') {
    grid[x][y] = '^';
    grid[x + 1][y] = 'v';
    take(x, y);
    take(x + 1, y);
  } else if (grid[x - 1][y] == '.') {
    grid[x - 1][y] = '^';
    grid[x][y] = 'v';
    take(x - 1, y);
    take(x, y);
  } else if (grid[x][y + 1] == '.') {
    grid[x][y] = '<';
    grid[x][y + 1] = '>';
    take(x, y);
    take(x, y + 1);
  } else if (grid[x][y - 1] == '.') {
    grid[x][y] = '>';
    grid[x][y - 1] = '<';
    take(x, y);
    take(x, y - 1);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      grid[i][j] = '*';
    }
  }

  int fw = 0, fb = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.') {
        if ((i + j) % 2 == 0) fw++;
        else fb++;
      } else {
        takenc++;
      }
    }
  }

  if (fw != fb) failure();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 4; k++) {
        taken_nb[i][j] += (int) (grid[i + ni[k]][j + nj[k]] == '*');
      }

      if (taken_nb[i][j] == 3 && grid[i][j] == '.') {
        nxt.push_back(make_pair(i, j));
      }
    }
  }

  while (!nxt.empty()) {
    pair<int, int> pr = nxt.back();
    nxt.pop_back();
    process(pr);
  }

  if (takenc == n * m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << grid[i][j];
      }
      cout << '\n';
    }
  } else {
    failure();
  }
}