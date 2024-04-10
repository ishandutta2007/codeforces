#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
  int x, y, z, id;
};

bool operator< (point p, point q) {
  if (p.x != q.x) {
    return p.x < q.x;
  }
  if (p.y != q.y) {
    return p.y < q.y;
  }
  if (p.z != q.z) {
    return p.z < q.z;
  }
  return p.id < q.id;
}

int dist (point p, point q) {
  return abs(p.x - q.x) + abs(p.y - q.y) + abs(p.z - q.z);
}

const int MAX_N = 5e4 + 5;
const int INF = 1e9 + 5;

vector<pair<int, int>> ans;
point solve_line (const vector<point> &line, point leftover) { // all have same x and y
  pair<int, point> bestm = make_pair(INF, point());
  if (leftover.id != 0) {
    for (point p : line) {
      bestm = min(bestm, make_pair(dist(p, leftover), p));
    }

    ans.push_back(make_pair(leftover.id, bestm.second.id));
  }

  vector<point> rline;
  for (point p : line) {
    if (p.id != bestm.second.id) {
      rline.push_back(p);
    }
  }

  for (int i = 0; i + 1 < (int) rline.size(); i += 2) {
    ans.push_back(make_pair(rline[i].id, rline[i + 1].id));
  }

  if ((int) rline.size() % 2 == 0) {
    return point();
  } else {
    return rline.back();
  }
}

point solve_plane (const vector<point> &plane, point leftover) { // all have same x
  pair<int, point> bestm = make_pair(INF, point());
  if (leftover.id != 0) {
    for (point p : plane) {
      bestm = min(bestm, make_pair(dist(p, leftover), p));
    }

    ans.push_back(make_pair(leftover.id, bestm.second.id));
  }

  vector<point> rplane;
  for (point p : plane) {
    if (p.id != bestm.second.id) {
      rplane.push_back(p);
    }
  }

  vector<vector<point>> lines;
  for (int i = 0; i < (int) rplane.size(); i++) {
    if (i == 0 || rplane[i].y != rplane[i - 1].y) {
      lines.push_back(vector<point> ());
    }
    lines.back().push_back(rplane[i]);
  }

  point last = point();
  for (int i = 0; i < (int) lines.size(); i++) {
    last = solve_line(lines[i], last);
  }
  return last;
}

void solve (const vector<point> &space) {
  vector<vector<point>> planes;
  for (int i = 0; i < (int) space.size(); i++) {
    if (i == 0 || space[i].x != space[i - 1].x) {
      planes.push_back(vector<point> ());
    }
    planes.back().push_back(space[i]);
  }

  point last = point();
  for (int i = 0; i < (int) planes.size(); i++) {
    last = solve_plane(planes[i], last);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;

  vector<point> points (length);
  for (int i = 0; i < length; i++) {
    cin >> points[i].x >> points[i].y >> points[i].z;
    points[i].id = i + 1;
  }

  sort(points.begin(), points.end());
  solve(points);
  for (pair<int, int> pr : ans) {
    cout << pr.first << " " << pr.second << '\n';
  }
}