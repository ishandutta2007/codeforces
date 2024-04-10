#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

class SetStruct {
  set<pair<int, int>> lw; // <left end, width>
  set<pair<int, int>> wl; // <width, left end>

  void del (int l, int w) {
    lw.erase(make_pair(l, w));
    wl.erase(make_pair(w, l));
  }

  void add (int l, int w) {
    lw.insert(make_pair(l, w));
    wl.insert(make_pair(w, l));
  }
public:
  SetStruct (int _w) {
    add(0, _w);
    add(_w, 0);
  }

  void cut (int pos) {
    auto lb = lw.upper_bound(make_pair(pos, 0));
    int rgt = lb->first;
    auto lft = prev(lb)->first;
    auto oldw = prev(lb)->second;

    del(lft, oldw);
    add(lft, pos - lft);
    add(pos, rgt - pos);
  }

  int get () {
    return wl.rbegin()->first;
  }
};

int main () {
  ios::sync_with_stdio(false);

  int w, h, n;
  cin >> w >> h >> n;

  SetStruct vert (w);
  SetStruct horiz (h);

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;

    int pos;
    cin >> pos;

    if (c == 'H') {
      horiz.cut(pos);
    } else {
      vert.cut(pos);
    }

    cout << (ll) horiz.get() * (ll) vert.get() << '\n';
  }
}