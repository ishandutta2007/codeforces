#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Event {
  int pos;
  int type;

  Event(int _pos, int _type) : pos(_pos), type(_type) {}
};

bool operator<(const Event& lhs, const Event& rhs) {
  if (lhs.pos != rhs.pos) {
    return lhs.pos < rhs.pos;
  }
  return lhs.type < rhs.type;
}

int main() {
  int n, m, t;
  scanf("%d%d%d", &n, &m, &t);
  vector<Event> a;
  for (int i = 0; i < n; ++i) {
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int tm = hh * 60 * 60 + mm * 60 + ss; 
    a.push_back(Event(tm, 0));
    a.push_back(Event(tm + t - 1, 1));
  }
  sort(a.begin(), a.end());
  deque<int> deq;
  int col_cnt = 0;
  int max_col = 0;
  bool get_m = false;
  vector<int> colors;
  for (int i = 0; i < a.size(); ++i) {
    Event e = a[i];
    if (e.type == 0) {
      if (col_cnt < m) {
        deq.push_back(max_col++);
        ++col_cnt;
      } else {
        deq.push_back(deq.back());
      }
      if (col_cnt == m) {
        get_m = true;
      }
    } else {
      int color = deq.front();
      colors.push_back(color + 1);
      deq.pop_front();
      if (deq.empty() || color != deq.front()) {
        --col_cnt;
      }
    }
  }
  if (!get_m) {
    cout << "No solution";
    return 0;
  }
  cout << max_col << "\n";
  for (int x : colors) {
    cout << x << "\n";
  }
  return 0;
}