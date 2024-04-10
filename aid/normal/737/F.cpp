#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

int n, a, b;
vector<int> p, q;
vector< pair<int, int> > ans;

int read() {
  if (scanf("%d%d%d", &n, &a, &b) < 3) {
    return false;
  }
  p.resize(n);
  q.clear();
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  reverse(p.begin(), p.end());
  return true;
}

bool check() {
  for (int i = 0; i < sz(q);) {
    int j = i + 1;
    while (j < sz(q) && q[j] == q[j - 1] - 1) {
      j++;
    }
    if (j - i > b) {
      return false;
    }
    if (j < sz(q) && q[j] < q[j - 1]) {
      return false;
    }
    i = j;
  }
  return true;
}

void solve() {
  ans.clear();
  while (!p.empty() || !q.empty()) {
    for (int i = 0; i < sz(p); i++) {
      eprintf("%d ", p[i]);
    }
    eprintf("\n");
    for (int i = 0; i < sz(q); i++) {
      eprintf("%d ", q[i]);
    }
    eprintf("\n\n");
    if (!check()) {
      printf("NO\n");
      return;
    }
    int x = sz(p) + sz(q) - 1;
    int pos = find(q.begin(), q.end(), x) - q.begin();
    if (pos < sz(q)) {
      assert(sz(q) - pos <= b);
      ans.push_back(make_pair(2, sz(q) - pos));
      q.resize(pos);
    } else {
      pos = find(p.begin(), p.end(), x) - p.begin();
      assert(pos < sz(p));
      bool ok = true;
      for (int i = pos + 1; i < sz(p); i++) {
        if (p[i] != p[i - 1] - 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans.push_back(make_pair(1, 1));
        q.push_back(p.back());
        p.pop_back();
        continue;
      }
      for (pos = sz(p) - 1;; pos--) {
        if (p[pos - 1] > p[pos] + 1) {
          break;
        }
      }
      ok = true;
      for (int i = pos + 1; i < sz(p); i++) {
        if (p[i] != p[i - 1] - 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        int lst = pos;
        for (int i = pos - 1; i >= 0; i--) {
          if (p[i] > p[pos]) {
            lst = i;
          }
        }
        bool canRot = (q.empty() || q.back() <= p.back() + 1);
        for (int i = lst; i < pos; i++) {
          if (p[i] < p[pos]) {
            canRot = false;
            break;
          }
        }
        if (canRot) {
          ans.push_back(make_pair(1, 1));
          q.push_back(p.back());
          p.pop_back();
        } else {
          if (sz(p) - pos > a) {
            printf("NO\n");
            return;
          }
          ans.push_back(make_pair(1, sz(p) - pos));
          q.insert(q.end(), p.begin() + pos, p.end());
          p.resize(pos);
        }
        continue;
      }
      bool canRot = *max_element(p.begin() + pos, p.end()) - *min_element(p.begin() + pos, p.end()) + 1 == sz(p) - pos;
      if (!canRot) {
        if (sz(p) - pos > a) {
          printf("NO\n");
          return;
        }
        ans.push_back(make_pair(1, sz(p) - pos));
        q.insert(q.end(), p.begin() + pos, p.end());
        p.resize(pos);
      } else {
        bool needRot = !q.empty() && q.back() > *min_element(p.begin() + pos, p.end()) + 1;
        int lst = pos;
        for (int i = pos - 1; i >= 0; i--) {
          if (p[i] > p[pos]) {
            lst = i;
          }
        }
        for (int i = lst; i < pos; i++) {
          if (p[i] < p[pos]) {
            needRot = true;
            break;
          }
        }
        if (!needRot) {
          int cnt = 0;
          int pos0 = -1;
          for (int i = pos + 1; i < sz(p); i++) {
            if (p[i] != p[i - 1] - 1) {
              cnt++;
              pos0 = i;
            }
          }
          if (cnt > 1) {
            if (sz(p) - pos > a) {
              for (pos = sz(p) - 1;; pos--) {
                if (p[pos - 1] != p[pos] + 1) {
                  break;
                }
              }
              if (sz(p) - pos > a) {
                printf("NO\n");
                return;
              }
              ans.push_back(make_pair(1, sz(p) - pos));
              q.insert(q.end(), p.begin() + pos, p.end());
              p.resize(pos);
            } else {
              ans.push_back(make_pair(1, sz(p) - pos));
              q.insert(q.end(), p.begin() + pos, p.end());
              p.resize(pos);
            }
          } else {
            int tocut = -1;
            for (int i = sz(p) - 1; i >= pos; i--) {
              int maxlen;
              if (i >= pos0) {
                maxlen = max(i - pos0, sz(p) - i + pos0 - pos);
              } else {
                maxlen = max(pos0 - i, sz(p) - pos0 + i - pos);
              }
              if (maxlen <= b && sz(p) - i <= a && i - pos <= a) {
                tocut = i;
                break;
              }
            }
            if (tocut == -1) {
              printf("NO\n");
              return;
            }
            ans.push_back(make_pair(1, sz(p) - tocut));
            q.insert(q.end(), p.begin() + tocut, p.end());
            p.resize(tocut);
            if (pos < sz(p)) {
              ans.push_back(make_pair(1, sz(p) - pos));
              q.insert(q.end(), p.begin() + pos, p.end());
              p.resize(pos);
            }
          }
        } else {
          for (pos = sz(p) - 1;; pos--) {
            if (p[pos - 1] != p[pos] + 1) {
              break;
            }
          }
          if (sz(p) - pos > a) {
            printf("NO\n");
            return;
          }
          ans.push_back(make_pair(1, sz(p) - pos));
          q.insert(q.end(), p.begin() + pos, p.end());
          p.resize(pos);
        }
      }
    }
  }
  printf("YES\n");
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}