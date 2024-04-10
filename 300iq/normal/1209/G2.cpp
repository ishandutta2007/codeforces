#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 3e5 + 7;

int a[N];
set <int> q[N];
int cnt[N];

struct segm {
  int l, r, x;
};

set <segm> e;

bool operator < (const segm &a, const segm &b) {
  return a.l < b.l;
}

const int B = 300;
const int BL = B;

int suf[N];
int max_x[N];
int jump_r[N];
int cnt_here[N];
int sum_here[N];

vector <segm> orz[N];

int w[N];
int tr[N];
bool vis[N];

void rebuild_block(int l) {
  l -= l % B;
  static vector <segm> p;
  p.clear();
  for (int i = l; i < l + B && i < N; i++) {
    if (vis[i]) {
      p.push_back({i, tr[i], w[i]});
    }
  }
  segm ret;
  ret.l = 0;
  ret.r = -1;
  ret.x = 0;
  static vector <segm> ans;
  ans.clear();
  for (auto c : p) {
    if (c.l > ret.r) {
      if (ret.r != -1) {
        ans.push_back(ret);
      }
      ret = c;
    } else {
      ret.r = max(ret.r, c.r);
      ret.x = max(ret.x, c.x);
    }
  }
  if (ret.r != -1) {
    ans.push_back(ret);
  }
  orz[l] = ans;
  int j = -1;
  int mx = 0;
  int r = -1;
  int sum = 0;
  for (int i = l; i < l + B && i < N; i++) {
    while (j + 1 < (int) ans.size() && ans[j + 1].l <= i) {
      j++;
      mx = max(mx, ans[j].x);
      r = max(r, ans[j].r);
      sum += ans[j].x;
    }
    sum_here[i] = sum;
    cnt_here[i] = j + 1;
    max_x[i] = mx;
    jump_r[i] = r;
  }
}

void del(int x, int i) {
  int l = *q[x].begin(), r = *prev(q[x].end());
  vis[l] = false;
  e.erase({l, r, cnt[x]});
  cnt[x]--;
  q[x].erase(i);
  rebuild_block(l);
  if (cnt[x]) {
    int l = *q[x].begin(), r = *prev(q[x].end());
    vis[l] = true;
    w[l] = cnt[x];
    tr[l] = r;
    e.insert({l, r, cnt[x]});
    rebuild_block(l);
  }
}

void add(int x, int i) {
  if (cnt[x]) {
    int l = *q[x].begin(), r = *prev(q[x].end());
    vis[l] = false;
    e.erase({l, r, cnt[x]});
    rebuild_block(l);
  }
  cnt[x]++;
  q[x].insert(i);
  int l = *q[x].begin(), r = *prev(q[x].end());
  vis[l] = true;
  w[l] = cnt[x];
  tr[l] = r;
  e.insert({l, r, cnt[x]});
  rebuild_block(l);
}

int ans() {
  int vr = -1;
  int tot = 0;
  int gao = 0;
  for (int i = 0; i < 200000; i += B) {
    if (orz[i].empty()) continue;
    if (vr <= i) {
      tot += gao;
      tot += sum_here[i + BL - 1] - orz[i].back().x;
      gao = orz[i].back().x;
      vr = orz[i].back().r;
    } else {
      int value = min(vr, i + BL - 1);
      gao = max(gao, max_x[value]);
      vr = max(vr, jump_r[value]);
      if (cnt_here[value] != cnt_here[i + BL - 1]) {
        tot += gao;
        tot += sum_here[i + BL - 1] - sum_here[value] - orz[i].back().x;
        gao = orz[i].back().x;
        vr = orz[i].back().r;
      }
    }
  }
  return tot + gao;
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 200000, tq = 200000;
  cin >> n >> tq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    q[a[i]].insert(i);
    cnt[a[i]]++;
    //add(a[i], i);
  }
  for (int i = 0; i < N; i++)  {
    if (!q[i].empty()) {
      vis[*q[i].begin()] = true;
      w[*q[i].begin()] = cnt[i];
      tr[*q[i].begin()] = *q[i].rbegin();
      e.insert({*q[i].begin(), *q[i].rbegin(), cnt[i]});
    }
  }
  for (int i = 0; i < N; i += BL) {
    rebuild_block(i);
  }
  cout << n - ans() << '\n';
  for (int j = 0; j < tq; j++) {
    int i, x;
    cin >> i >> x;
    i--, x--;
    del(a[i], i);
    a[i] = x;
    add(a[i], i);
    cout << n - ans() << '\n';
  }
}