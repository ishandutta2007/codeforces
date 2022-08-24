#include <cmath>
#include <functional>
#include <fstream>
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
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int MEM = 2e8;

char c[MEM];

int ptr = 0;

void *operator new(size_t n) {
  ptr += n;
  return (void*)(c+ptr-n);
}

void operator delete(void*){
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  vector <int> queue, temp;
  set <int> q;
  for (int i = 0; i < n; i++) {
    q.insert(i);
    queue.push_back(i);
  }
  int rounds = 0;
  auto check = [&] (int i) {
    if (!q.count(i)) return false;
    auto it= q.find(i);
    if (it != q.begin() && s[*prev(it)] != s[i]) {
      return true;
    }
    if (next(it) != q.end() && s[*next(it)] != s[i]) {
      return true;
    }
    return false;
  };
  while (!queue.empty()) {
    sort(queue.begin(),queue.end());
    queue.resize(unique(queue.begin(),queue.end()) - queue.begin());
    temp.clear();
    bool done = false;
    vector <int> ok;
    for (int i : queue) {
      if (check(i)) {
          auto it = q.find(i);
        if (it != q.begin())
          temp.push_back(*prev(it));
        if (next(it) != q.end())
          temp.push_back(*next(it));
        ok.push_back(i);
        done = true;
      }
    }
    for (int x : ok) q.erase(x);
    if(!done) break;
    rounds++;
    queue = temp;
  }
  cout << rounds << endl;
}