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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;

int main() {
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  string str = "";
  for (int i = 0; i < n; i++)
  {
    if (s[i] != 'a')
    {
      str += s[i];
    }
    if ((int) str.size() == n - 1 - i)
    {
      bool bad = false;
      for (int x = i + 1; x < n; x++)
      {
        if (s[x] != str[x - (i + 1)])
        {
          bad = true;
          break;
        }
      }
      if (!bad)
      {
        for (int j = 0; j <= i; j++) cout << s[j];
        cout << endl;
        return 0;
      }
      else
      {
          break;
      }
    }
  }
  cout << ":(" << endl;
}