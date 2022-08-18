#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

string cmd;

typedef pair<int, int> block;
set<block> obst;
block start, finish;
int height, width;

int nr [4] = {1, 0, -1, 0};
int nc [4] = {0, 1, 0, -1};

bool attempt (vector<int> mapping) {
  block cur = start;

  for (char c : cmd) {
    int id = c - '0';

    cur.first += nr[mapping[id]];
    cur.second += nc[mapping[id]];

    if (cur.first < 0 || cur.first >= height || cur.second < 0 || cur.second >= width) {
      return false;
    }

    if (obst.count(cur) != 0) {
      return false;
    }

    if (cur == finish) {
      return true;
    }
  }

  return false;
}

int ans;

bool vis [4];
void dfs (vector<int> cur) {
  if (cur.size() == 4) {
    if (attempt(cur)) {
      ans++;
    }
  } else {
    for (int i = 0; i < 4; i++) {
      if (!vis[i]) {
        vis[i] = true;
        cur.push_back(i);
        dfs(cur);
        cur.pop_back();
        vis[i] = false;
      }
    }
  }
}

int main () {
  cin >> height >> width;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      char c;
      cin >> c;

      if (c == '#') {
        obst.insert(make_pair(i, j));
      } else if (c == 'S') {
        start = make_pair(i, j);
      } else if (c == 'E') {
        finish = make_pair(i, j);
      }
    }
  }
  cin >> cmd;

  dfs(vector<int> ());

  cout << ans << endl;
}