#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 35;
int N, T[N_];

const int O = 200;
bool field[O+O+1][O+O+1];
bool& getf (int x, int y) { return field[x+O][y+O]; }

const int dx[] = {-1, -1, -1, 0, +1, +1, +1, 0};
const int dy[] = {-1,  0, +1,+1, +1,  0, -1, -1};

bool chk[O+O+1][O+O+1][8];
bool& getc (int x, int y, int d) { return chk[x+O][y+O][d]; }
vector<tuple<int, int, int> > vec;

void paint (int x, int y, int d, int r) {
    while(r--) getf(x += dx[d], y += dy[d]) = true;
    if(!getc(x, y, d))
      vec.push_back(tie(x, y, d)), getc(x, y, d) = true;
}
int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    int t; scanf("%d", &t);
    if(i == 1) {
      for(int j = 1; j <= t; j++) getf(0, j) = true;
      getc(0, t, 3) = true;
      vec.push_back({0, t, 3});
    }else {
      auto prv = vec;
      vec.clear();
      for(auto p : prv) {
        int x, y, d; tie(x, y, d) = p;
        paint(x, y, (d+1)%8, t);
        paint(x, y, (d+7)%8, t);
      }
    }
    for(auto p : vec) {
      int x, y, d; tie(x, y, d) = p;
      getc(x, y, d) = false;
    }
  }

  int ans = 0;
  for(int i = -O; i <= O; i++) {
    for(int j = -O; j <= O; j++) {
      if(getf(i, j)) ans += 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}