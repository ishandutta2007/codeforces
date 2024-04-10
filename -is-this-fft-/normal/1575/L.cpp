#include <bits/stdc++.h>

using namespace std;

template <class E_T, class C_T, C_T n_inf, class R_T>
struct BIT {
  vector<C_T> pos;
  vector<E_T> elems;
  bool act = false;

  BIT() { pos.push_back(n_inf); }
  void init() {
    if (act) {
      for (E_T &c_elem : elems) c_elem.init();
    } else {
      act = true;
      sort(pos.begin(), pos.end());
      pos.resize(
        unique(pos.begin(), pos.end()) - pos.begin());
      elems.resize(pos.size());
    }
  }
  template <typename... loc_form>
  void update(C_T cx, loc_form... args) {
    if (act) {
      int x = lower_bound(pos.begin(), pos.end(), cx) -
              pos.begin();
      for (; x < (int)pos.size(); x += x & -x)
        elems[x].update(args...);
    } else {
      pos.push_back(cx);
    }
  }
  template <typename... loc_form>
  R_T query(
    C_T cx, loc_form... args) { // sum in (-inf, cx)
    R_T res = 0;
    int x = lower_bound(pos.begin(), pos.end(), cx) -
            pos.begin() - 1;
    for (; x > 0; x -= x & -x)
      res = max(res, elems[x].query(args...));
    return res;
  }
};

template <typename I_T>
struct wrapped {
  I_T a = 0;
  void update(I_T b) { a = max(a, b); }
  I_T query() { return a; }
  // Should never be called, needed for compilation
  void init() { }
  void update() { }
};

const int MAX_N = 2e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = i - arr[i];
  }

  BIT<BIT<wrapped<int>, int, INT_MIN, int>, int, INT_MIN, int> dp;
  for (int k = 0; k < 2; k++) {
    for (int i = 1; i <= n; i++) {
      if (arr[i] < 0) continue;
      dp.update(1 + arr[i], 1 + i - arr[i]);
    }
    dp.init();
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] < 0) continue;
    int cur = 1 + dp.query(1 + 1 + arr[i], 1 + i - arr[i]);
    dp.update(1 + arr[i], 1 + i - arr[i], cur);
    ans = max(ans, cur);
  }

  cout << ans << endl;
}