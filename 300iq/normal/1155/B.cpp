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
  vector <int> l, r;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '8') l.push_back(i);
    else r.push_back(i);
  }
  reverse(l.begin(), l.end());
  reverse(r.begin(), r.end());
  for (int it = 0; it < n - 11; it++)
  {
    if (it % 2 == 1)
    {
      if (!l.empty())
      {
        l.pop_back();
      }
      else
      {
        r.pop_back();
      }
    }
    else
    {
      if (!r.empty()) r.pop_back();
      else l.pop_back();
    }
  }
  reverse(l.begin(), l.end());
  reverse(r.begin(), r.end());
  if (!l.empty() && (r.empty() || l[0] < r[0]))
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }
}