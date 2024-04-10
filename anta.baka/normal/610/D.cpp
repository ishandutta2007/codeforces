#include <bits/stdc++.h>

using namespace std;

#define x1 dkfjdfljdkjf
#define y1 dkfjkdfjdkjl

int n;
int x1[100000], y1[100000], x2[100000], y2[100000];
int st[2 * 200000];
map<int, int> inx, iny;
vector<pair<int, int>> xx[200000], yy[200000];
vector<pair<int, int>> xx1[200000], yy1[200000];
long long ans;
vector<int> qin[200000], qout[200000];
int revx[200000], revy[200000];

void upd(int v, int d) {
  st[v += 200000] += d;
  for(v >>= 1; v; v >>= 1)
    st[v] = st[v * 2] + st[v * 2 + 1];
}

int get(int l, int r) {
  int res = 0;
  for(l += 200000, r += 200000; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
    if(l & 1)
      res += st[l];
    if(!(r & 1))
      res += st[r];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    inx[x1[i]];
    inx[x2[i]];
    iny[y1[i]];
    iny[y2[i]];
  }
  int cx = 0;
  for(auto it = inx.begin(); it != inx.end(); it++) {
    it->second = cx;
    revx[cx] = it->first;
    cx++;
  }
  int cy = 0;
  for(auto it = iny.begin(); it != iny.end(); it++) {
      it->second = cy;
      revy[cy] = it->first;
      cy++;
  }
  for(int i = 0; i < n; i++)
    if(x1[i] == x2[i]) {
      if(y1[i] > y2[i])
        swap(y1[i], y2[i]);
      xx[inx[x1[i]]].push_back({iny[y1[i]], iny[y2[i]]});
    } else {
      if(x1[i] > x2[i])
        swap(x1[i], x2[i]);
      yy[iny[y1[i]]].push_back({inx[x1[i]], inx[x2[i]]});
    }
  for(int i = 0; i < cx; i++) {
    if(xx[i].empty())
      continue;
    sort(xx[i].begin(), xx[i].end());
    xx1[i].push_back(xx[i][0]);
    for(int j = 1; j < xx[i].size(); j++)
      if(revy[xx[i][j].first] <= revy[xx1[i].back().second] + 1)
        xx1[i].back().second = max(xx1[i].back().second, xx[i][j].second);
      else
        xx1[i].push_back(xx[i][j]);
    for(pair<int, int> seg : xx1[i])
      ans += (revy[seg.second] - revy[seg.first] + 1);
  }
  for(int i = 0; i < cy; i++) {
    if(yy[i].empty())
      continue;
    sort(yy[i].begin(), yy[i].end());
    yy1[i].push_back(yy[i][0]);
    for(int j = 1; j < yy[i].size(); j++)
      if(revx[yy[i][j].first] <= revx[yy1[i].back().second] + 1)
        yy1[i].back().second = max(yy1[i].back().second, yy[i][j].second);
      else
        yy1[i].push_back(yy[i][j]);
    for(pair<int, int> seg : yy1[i])
      ans += (revx[seg.second] - revx[seg.first] + 1);
  }
  for(int i = 0; i < cy; i++)
    for(pair<int, int> seg : yy1[i]) {
      qin[seg.first].push_back(i);
      qout[seg.second].push_back(i);
    }
  for(int i = 0; i < cx; i++) {
    for(int y : qin[i])
      upd(y, 1);
    for(pair<int, int> seg : xx1[i])
      ans -= get(seg.first, seg.second);
    for(int y : qout[i])
      upd(y, -1);
  }
  cout << ans;
}