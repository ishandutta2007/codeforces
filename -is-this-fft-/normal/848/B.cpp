#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

struct Dancer {
  int id, dir, pos, delay;

  Dancer (int _id = 0, int _dir = 0, int _pos = 0, int _delay = 0) :
    id(_id), dir(_dir), pos(_pos), delay(_delay) {}
  
  int key () {
    return pos + MAX_N - delay;
  }
};

bool cmpa (Dancer p, Dancer q) {
  if (p.dir != q.dir) {
    return p.dir > q.dir;
  }

  if (p.pos != q.pos) {
    if (p.dir == 2) {
      return p.pos > q.pos;
    } else {
      return p.pos < q.pos;
    }
  }

  return p.id < q.id;
}

bool cmpb (Dancer p, Dancer q) {
  if (p.dir != q.dir) {
    return p.dir < q.dir;
  }

  if (p.pos != q.pos) {
    if (p.dir == 2) {
      return p.pos > q.pos;
    } else {
      return p.pos < q.pos;
    }
  }

  return p.id < q.id;
}

pair<int, int> ans [MAX_N];
pair<int, int> pans [MAX_N];
vector<Dancer> eqcl [2 * MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, w, h;
  cin >> n >> w >> h;

  for (int i = 0; i < n; i++) {
    Dancer dan (i);
    cin >> dan.dir >> dan.pos >> dan.delay;

    eqcl[dan.key()].push_back(dan);
    if (dan.dir == 1) {
      ans[i] = make_pair(dan.pos, h);
    } else {
      ans[i] = make_pair(w, dan.pos);
    }
  }

  for (int i = 0; i < 2 * MAX_N; i++) {
    if (!eqcl[i].empty()) {
      sort(eqcl[i].begin(), eqcl[i].end(), cmpa);

      auto cpy = eqcl[i];
      sort(cpy.begin(), cpy.end(), cmpb);

      int m = eqcl[i].size();
      for (int j = 0; j < m; j++) {
        pans[eqcl[i][j].id] = ans[cpy[j].id];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << pans[i].first << " " << pans[i].second << '\n';
  }
}