#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
#include <cstring>
using namespace std;

const int INF = 1 << 30;
const double EPS = 1e-10;

int main()
{
  int n, m, k;
  while (cin >> n >> m >> k) {
    vector<vector<int> > p(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cin >> p[i][j];
    }

    vector<int> col(m);
    for (int i = 0; i < m; ++i)
      col[i] = i;

    vector<int> row(n);
    for (int i = 0; i < n; ++i)
      row[i] = i;

    string s;
    int x, y;
    for (int i = 0; i < k; ++i) {
      cin >> s >> x >> y;
      --x;
      --y;
      if (s == "c")
        swap(col[x], col[y]);
      else if (s == "r")
        swap(row[x], row[y]);
      else
        cout << p[row[x]][col[y]]<< endl;
    }
  }
  return 0;
}