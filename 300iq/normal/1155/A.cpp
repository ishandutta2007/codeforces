#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  int n;
  cin >> n;
  string s;
  cin >> s;
  map <char, int> ind;
  for (int i = n - 1; i >= 0; i--)
  {
    for (auto c : ind)
    {
      if (c.first < s[i])
      {
        cout << "YES" << endl;
        cout << i + 1 << ' ' << c.second + 1 << endl;
        return 0;
      }
    }
    ind[s[i]] = i;
  }
  cout << "NO" << endl;
}