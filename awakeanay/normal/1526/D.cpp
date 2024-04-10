#include <iostream>
#include <map>

#define int long long

std::string s, t;
int n;

const int MAXN = 100005;

int bit[MAXN];
std::map<char, int> r;
std::string cs = "ANTO";

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

int moves() {
  int p[n];

  int it[4];
  it[0] = it[1] = it[2] = it[3] = -1;

  for(int i = 0; i < n; i++) {
    int k = r[t[i]];
    it[k]++;
    while(s[it[k]] != t[i])
      it[k]++;
    p[i] = it[k];
  }

  int ret = 0;
  for(int i = n-1; i >= 0; i--) {
    ret += sum(p[i]);
    add(p[i], 1);
  }

  for(int i = 0; i < n; i++)
    add(i, -1);

  return ret;
}

signed main() {
  r['A'] = 0;
  r['N'] = 1;
  r['T'] = 2;
  r['O'] = 3;

  int T;
  std::cin >> T;

  while(T--) {
    std::cin >> s;
    n = s.length();
    t = s;

    int ans = -1;
    std::string best;

    int ct[4] = {0};
    for(int i = 0; i < n; i++)
      ct[r[s[i]]]++;

    for(int a = 0; a < 4; a++) {
      for(int b = 0; b < 4; b++) {
        if(a == b)
          continue;
        for(int c = 0; c < 4; c++) {
          if(c == a || c == b)
            continue;
          for(int d = 0; d < 4; d++) {
            if(d == a || d == b || d == c)
              continue;

            int ptr = 0;
            for(int i = 0; i < ct[a]; i++)
              t[ptr++] = cs[a];
            for(int i = 0; i < ct[b]; i++)
              t[ptr++] = cs[b];
            for(int i = 0; i < ct[c]; i++)
              t[ptr++] = cs[c];
            for(int i = 0; i < ct[d]; i++)
              t[ptr++] = cs[d];

            int next = moves();
            if(next > ans) {
              best = t;
              ans = next;
            }
          }
        }
      }
    }

    std::cout << best << std::endl;
  }

  return 0;
}