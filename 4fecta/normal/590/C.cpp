//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 1010;
char s[MAXN][MAXN];
int n, m;
int dist[3][MAXN][MAXN];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  scanf("%d%d",&n,&m);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);

  memset(dist, -1, sizeof(dist));

  for (int c = '1'; c <= '3'; c++) {
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (s[i][j] == c) {
          dist[c - '1'][i][j] = 0;
          q.push_back(make_pair(i, j));
        }

    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop_front();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && s[nx][ny] != '#') {
          int nd = dist[c - '1'][x][y] + (s[nx][ny] == '.');
          if (dist[c - '1'][nx][ny] == -1 || dist[c - '1'][nx][ny] > nd) {
            dist[c - '1'][nx][ny] = nd;
            if (s[nx][ny] == '.') {
              q.push_back(make_pair(nx, ny));
            } else {
              q.push_front(make_pair(nx, ny));
            }
          }
        }
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (dist[0][i][j] != -1 && dist[1][i][j] != -1 && dist[2][i][j] != -1) {
        int nval = dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2 * (s[i][j] == '.');
        //fprintf(stderr, "%d %d %d: %d %d %d\n", i, j, nval, dist[0][i][j], dist[1][i][j], dist[2][i][j]);
        if (ans == -1 || ans > nval) {
          ans = nval;
        }
      }
    }
  printf("%d\n", ans);
  return 0;
}