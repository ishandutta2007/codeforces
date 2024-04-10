#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll llf = (~0ull >> 2);

const int L = 1024;

template <typename T>
bool vmax(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}

int cti(char x) {
  return x - 'a';
}

typedef class AhoCorasick {
  public:
    int tp;
    int ch[L][14], fail[L], w[L];

    AhoCorasick() : tp(1) { }

    void insert(char* s, int v) {
      int p = 1;
      for ( ; *s; s++) {
        int x = cti(*s);
        if (!ch[p][x]) {
          ch[p][x] = ++tp;
        }
        p = ch[p][x];
      }
      w[p] += v;
    }

    void build() {
      queue<int> Q;
      for (int i = 0; i < 14; i++) {
        if (ch[1][i]) {
          fail[ch[1][i]] = 1;
          Q.push(ch[1][i]);
        } else {
          ch[1][i] = 1;
        }
      }
      while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        int f = fail[p];
        w[p] += w[f];
        for (int i = 0; i < 14; i++) {
          int& e = ch[p][i];
          if (!e) {
            e = ch[f][i];
          } else {
            fail[e] = ch[f][i];
            Q.push(e);
          }
        } 
      }
    }

    int* operator [] (int p) {
      return ch[p];
    }
    int operator () (int p) {
      return w[p];
    }
} AhoCorasick;

int n, m, maxL = 0;
char t[1005];
char s[500004];
AhoCorasick ac;

vector<int> pos;
int tr[16];
ll trw[16];
ll f[1024][1 << 14];
vector<int> status[15];

pair<int, ll> trans(int p, int t) {
  int l = pos[t] + 1, r = pos[t + 1] - 1;
  if (r - l + 1 >= maxL) {
    ll w = 0;
    for (int i = maxL; i--; l++) {
      p = ac[p][cti(s[l])];
      w += ac(p);
    } 
    if (!tr[t]) {
      int& q = tr[t];
      q = p;
      for (int i = l; i <= r; i++) {
        q = ac[q][cti(s[i])];
        trw[t] += ac(q);
      }
    }
    return make_pair(tr[t], trw[t] + w);
  }
  int q = p;
  ll w = 0;
  for (int i = l; i <= r; i++) {
    q = ac[q][cti(s[i])];
    w += ac(q);
  }
  return make_pair(q, w);
}

int main() {
  scanf("%d", &m);
  for (int i = 0, w; i < m; i++) {
    scanf("%s%d", t, &w);
    ac.insert(t, w);
    maxL = max(maxL, (int) strlen(t));
  }
  ac.build();
  scanf("%s", s + 1);
  pos.push_back(0);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '?') {
      pos.push_back(i);
    }
  }
  pos.push_back(n + 1);
  int k = pos.size();
  for (int i = 0; i <= ac.tp; i++) {
    for (int s = 0; s < (1 << 14); s++) {
      f[i][s] = -llf;
    }
  }
  for (int s = 0; s < (1 << 14); s++) {
    status[__builtin_popcount(s)].push_back(s);
  }
  f[1][0] = 0;
  ll ans = -llf;
  for (int i = 0; i < k - 1; i++) {
    for (int p = 1; p <= ac.tp; p++) {
      auto tmp = trans(p, i);
      int np = tmp.first;
      ll tw = tmp.second;
      for (auto s : status[i]) {
        ll v = f[p][s];
        if (v >= -(llf >> 1)) {
          v += tw;
          if (i == k - 2) {
            vmax(ans, v);
          } else {
            for (int c = 0; c < 14; c++) {
              if (!((s >> c) & 1)) {
                int q = ac[np][c];
                vmax(f[q][s | (1 << c)], v + ac(q));
              }
            }
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}