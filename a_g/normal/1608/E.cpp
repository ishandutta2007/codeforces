#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<pii> pts[3];
vector<int> sx[3];
vector<int> sy[3];
vector<vector<int>> perms = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
const int INF = 1e9+1e6;

bool possible(int k) {
  // purely vertical partition
  for (vector<int> perm: perms) {
    int coord = -INF;
    bool good = 1;
    for (int i: perm) {
      int x = lower_bound(sx[i].begin(), sx[i].end(), coord)-sx[i].begin();
      if (x+k-1 < n/3) {
        coord = sx[i][x+k-1] + 1;
      }
      else {
        good = 0;
        break;
      }
    }
    if (good) return 1;
  }

  // purely horizontal parition
  for (vector<int> perm: perms) {
    int coord = -INF;
    bool good = 1;
    for (int i: perm) {
      int y = lower_bound(sy[i].begin(), sy[i].end(), coord)-sy[i].begin();
      if (y+k-1 < n/3) {
        coord = sy[i][y+k-1] + 1;
      }
      else {
        good = 0;
        break;
      }
    }
    if (good) return 1;
  }

  // one color on its own side
  for (int i = 0; i < 3; i++) {
    for (int sgn = -1; sgn <= 1; sgn += 2) {
      for (int vert = 0; vert < 2; vert++) {
        int l;
        if (vert) {
          if (sgn > 0) l = sx[i][k-1]+1;
          else l = -(sx[i][n/3-k]-1);
        }
        else {
          if (sgn > 0) l = sy[i][k-1]+1;
          else l = -(sy[i][n/3-k]-1);
        }
        vector<int> a;
        vector<int> b;
        for (pii pt: pts[(i+1)%3]) {
          if (vert) {
            if (sgn*pt.first >= l) {
              a.push_back(pt.second);
            }
          }
          else {
            if (sgn*pt.second >= l) {
              a.push_back(pt.first);
            }
          }
        }
        for (pii pt: pts[(i+2)%3]) {
          if (vert) {
            if (sgn*pt.first >= l) {
              b.push_back(pt.second);
            }
          }
          else {
            if (sgn*pt.second >= l) {
              b.push_back(pt.first);
            }
          }
        }
        if (a.size() < k || b.size() < k) continue;
        nth_element(a.begin(), a.begin()+k-1, a.end());
        nth_element(b.begin(), b.end()-k, b.end());
        if (a[k-1] < b[b.size()-k]) return 1;
        nth_element(a.begin(), a.end()-k, a.end());
        nth_element(b.begin(), b.begin()+k-1, b.end());
        if (b[k-1] < a[a.size()-k]) return 1;
      }
    }
  }

  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    pts[c-1].push_back({x, y});
    sx[c-1].push_back(x);
    sy[c-1].push_back(y);
  }
  for (int i = 0; i < 3; i++) {
    sort(sx[i].begin(), sx[i].end());
    sort(sy[i].begin(), sy[i].end());
  }

  int low = 1;
  int high = n/3+1;
  while (low + 1 < high) {
    int mid = (low+high)/2;
    if (possible(mid)) low = mid;
    else high = mid;
  }
  cout << 3*low << endl;
}