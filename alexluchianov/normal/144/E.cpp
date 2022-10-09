#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

using ld = long double;
using ll = long long;

int const nmax = 100000;

struct Sport{
  int x;
  int y;
  int id;
  bool operator < (Sport const &a) const {
    return y < a.y;
  }
} v[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    v[i] = {n - x + 1, y, i};
  }
  sort(v + 1, v + m + 1);
  set<int> st;
  for(int i = 1;i <= n; i++)
    st.insert(i);
  vector<int> sol;
  for(int i = 1;i <= m; i++){
    set<int>::iterator it = st.lower_bound(v[i].x);
    if(it != st.end() && *it <= v[i].y) {
      st.erase(it);
      sol.push_back(v[i].id);
    }
  }
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
}
/*
3 3 1
1 2 4
1 3 4
2 3 5
6

*/