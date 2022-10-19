#include <bits/stdc++.h>
using namespace std;

struct coord {
  int x, y;
};

const int N = 1e5+2;
const int K = 17;
const long long INF = 1e18;
long long dp[N][2][K][2];
coord door[N][2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n-1; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> door[i][j].x >> door[i][j].y;
      if (j == 0) assert(door[i][j].x == i);
      else assert(door[i][j].y == i);
    }
  }

  for (int i = 1; i < n-1; i++) {
    for (int j = 0; j < 2; j++) {
      for (int z = 0; z < 2; z++) {
        if (j == 0) {
          dp[i][j][0][z] = 1+(i+1-door[i+1][z].x) + abs(door[i][j].y-door[i+1][z].y);
        }
        else {
          dp[i][j][0][z] = 1+(i+1-door[i+1][z].y) + abs(door[i][j].x-door[i+1][z].x);
        }
      }
    }
  }

  for (int k = 1; k < K; k++) {
    for (int i = 1; i+(1<<k) < n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int z = 0; z < 2; z++) {
          dp[i][j][k][z] = INF;
          for (int l = 0; l < 2; l++) {
            dp[i][j][k][z] = min(dp[i][j][k][z], dp[i][j][k-1][l]
                +  dp[i+(1<<(k-1))][l][k-1][z]);
          }
        }
      }
    }
  }

  int m;
  cin >> m;
  while (m--) {
    coord a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    int l1 = max(a.x, a.y);
    int l2 = max(b.x, b.y);
    if (l1 == l2) {
      cout << abs(a.x-b.x)+abs(a.y-b.y) << '\n';
      continue;
    }
    if (l1 > l2) {
      swap(a, b);
      swap(l1, l2);
    }
    long long ans = INF;
    long long d[2], e[2];
    for (int i = 0; i < 2; i++) {
      d[i] = abs(a.x-door[l1][i].x)+abs(a.y-door[l1][i].y);
    }
    int cur = l1;
    for (int k = K-1; k >= 0; k--) {
      if (cur+(1<<k) < l2) {
        for (int i = 0; i < 2; i++) {
          e[i] = INF;
          for (int j = 0; j < 2; j++) {
            e[i] = min(e[i], d[j]+dp[cur][j][k][i]);
          }
        }
        swap(d, e);
        cur += (1<<k);
      }
    }
    assert(cur == l2-1);
    ans = min(ans, 1+d[0]+l2-b.x+abs(door[l2-1][0].y-b.y));
    ans = min(ans, 1+d[1]+l2-b.y+abs(door[l2-1][1].x-b.x));
    cout << ans << '\n';
  }
}