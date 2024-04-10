#include <bits/stdc++.h>

using namespace std;

const int MOD = int(1e9) + 7;

using lint = long long;

#define debug if(0)printf 

struct modint {
  int v;
  modint (int v_ = 0): v(v_ % MOD) { }
  modint operator+ (const modint &m) const {
    return modint(v + m.v);
  }
  modint operator- (const modint &m) const {
    return modint(v - m.v + MOD);
  }
  modint operator* (const modint &m) const {
    return modint((lint)v * m.v % MOD);
  }
  modint operator+= (const modint m) {
    v = (v + m.v) % MOD;
    return *this;
  }
  modint operator*= (const modint m) {
    v = (lint(v) * m.v) % MOD;
    return *this;
  }
  modint inv() const {
    modint ret = 1, base = v;
    int ex = MOD - 2;
    while(ex > 0) {
      if(ex & 1) ret *= base;
      base *= base;
      ex >>= 1;
    }
    return ret;
  }
};

const int N_ = int(4.1e5);
char S[N_];

int IDX;

void print_spaces(int n) {
  while(n--) putchar(' ');
}

struct Expression {
  int l, r;
  modint value;
  vector<Expression*> ch;
  vector<modint> pref;

  virtual modint calc(int s, int e) { return 0; };

  int left_bound (int x) {
    int low = 0, high = int(ch.size()) - 1;
    int pos = ch.size();
    x += 1;
    while(low <= high) {
      int mid = (low + high) >> 1;
      if(x <= ch[mid]->l) {
        pos = mid;
        high = mid - 1;
        // (1, 3) (4, 5) (6, 9) (11, 13) x = 2
      }else {
        low = mid + 1;
      }
    }
    return pos;
  }

  int right_bound (int x) {
    int low = 0, high = int(ch.size()) - 1;
    int pos = -1;
    while(low <= high) {
      int mid = (low + high) >> 1;
      if(ch[mid]->r >= x) {
        high = mid - 1;
        pos = mid;
        // 1 2 3 4 5, x = 3
      }else {
        low = mid + 1;
      }
    }
    return pos;
  }

  modint get (int s, int e) {
    debug("s=%d e=%d l=%d r=%d\n", s, e, l, r);
    return (max(l, s) == l && min(r, e) == r) ? value : calc(max(l, s), min(r, e));
  }
  
  virtual void print(int) { };
};

vector<Expression*> stk;
Expression *wh[N_];

void adv() {
  wh[IDX++] = stk.empty() ? NULL : stk.back();  
}

modint pw10[N_];
modint pwinv10[N_];
const modint INV10 = modint(10).inv();

struct Number : Expression {
  Number() {
    value = 0;
    pref.push_back(0);
    l = IDX;
    for(; isdigit(S[IDX]); adv()) {
      value = value * 10 + (S[IDX] - '0');
      pref.push_back(value);
      r = IDX;
    }
  }

  modint calc (int s, int e) { 
    // I THINK CORRECT
    debug(" Number calc %d %d\n", s, e);
    e -= l-1; s -= l-1;
    return (pref[e] - pref[s-1] * pw10[e-s+1]);
  }
  // 12300
  // 12345

  void print(int indent) {
    //print_spaces(indent);
    //debug("[%d, %d]\n", a, b);
  }
};

struct Hang : Expression {
  Hang();

  void print(int indent) {
  }

  modint calc(int s, int e) {
    int i = left_bound(s);
    int j = right_bound(e);
    debug(" Hang calc %d %d [%d, %d]\n", s, e, i, j);
    for(Expression *xx : ch) {
      debug("  (%d, %d) ", xx->l, xx->r);
    }
    debug("\n");
    for(modint v : pref) {
      debug("  %d ", v.v);
    }
    debug("\n");
    modint ret = 1;
    if(i < j) {
      ret *= pref[j] * pref[i].inv();
    }
    i -= 1;
    //debug(" here [%d, %d]\n", i, j);
    if(i >= 0) {
      ret *= ch[i]->get(s, e);
    }
    if(i != j && j < ch.size()) {
      ret *= ch[j]->get(s, e);
    }
    debug(" HANG calc %d %d returned %d\n", s, e, ret.v);
    return ret;
  }
};

struct SAE : Expression {
  SAE() {
    value = 0;
    pref.push_back(0);
    l = IDX;
    assert(S[IDX] == '('); adv();
    stk.push_back(this);

    while(true) {
      ch.push_back(new Hang());
      value += ch.back()->value;
      pref.push_back(value);
      if(S[IDX] != '+') {
        break;
      }
      adv();
    }
    r = IDX;
    stk.pop_back();

    assert(S[IDX] == ')'); adv();

  }

  modint calc(int s, int e) {
    int i = left_bound(s);
    int j = right_bound(e);
    debug(" SAE calc %d %d [%d, %d]\n", s, e, i, j);
    for(Expression *xx : ch) {
      debug("  (%d, %d) ", xx->l, xx->r);
    }
    debug("\n");
    for(modint v : pref) {
      debug("  %d ", v.v);
    }
    debug("\n");
    modint ret = 0;
    if(i < j) {
      ret += pref[j] - pref[i];
    }
    i -= 1;
    //debug(" here [%d, %d]\n", i, j);
    if(i >= 0) {
      ret += ch[i]->get(s, e);
    }
    if(i != j && j < ch.size()) {
      ret += ch[j]->get(s, e);
    }
    debug(" SAE calc %d %d returned %d\n", s, e, ret.v);
    return ret;
  }

  void print(int indent) {
    debug(" value = %d\n", value.v);
  }
};

Hang::Hang() {
  value = 1;
  pref.push_back(1);
  l = IDX;
  while(true) {
    if(S[IDX] == '(') {
      ch.push_back(new SAE());
    }else {
      ch.push_back(new Number());
    }
    value *= ch.back()->value;
    pref.push_back(value);
    if(S[IDX] != '*') break;
    adv();
  }
  r = IDX-1;
}

int N;

int main() {
#ifdef IN_MY_COMPUTER
  freopen("l.in", "r", stdin);
#endif
  pwinv10[0] = 1;
  pw10[0] = 1;
  assert((INV10 * 10).v == 1);
  for(int i = 1; i < N_; i++) {
    pw10[i] = pw10[i-1] * 10;
    pwinv10[i] = pwinv10[i-1] * INV10;
  }

  S[0] = '(';
  scanf("%s", S+1);
  S[strlen(S+1)+1] = ')';
  N = strlen(S);

  new SAE();

  int Q; scanf("%d", &Q);
  while(Q--) {
    int l, r; scanf("%d%d", &l, &r);
    bool good = true;
    good &= isdigit(S[l]) || (S[l] == '(');
    good &= isdigit(S[r]) || (S[r] == ')');
    good &= (wh[l] == wh[r]);
    if(good) {
      printf("%d\n", wh[l]->get(l, r).v);
    }else {
      printf("-1\n");
    }
  }
  return 0;
}