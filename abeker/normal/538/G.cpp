#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int MAXN = 2000005;
const ld INF = 1e18;

int N, L;

struct triple {
  ll t, x, y;
  triple(ll t, ll x, ll y) : t(t), x(x), y(y) {}
  triple() : t(0), x(0), y(0) {}
  void input() {
    scanf("%lld%lld%lld", &t, &x, &y);
  }
  void output() const {
    printf("%lld %lld %lld\n", t, x, y);
  }
  bool operator <(const triple &rhs) const {
    return t % L < rhs.t % L; 
  }
};

struct rect {
  ld x1, y1, x2, y2;
  rect(ld x1, ld y1, ld x2, ld y2) : 
    x1(x1), y1(y1), x2(x2), y2(y2) {}
  void output() const {
    printf("%lf %lf %lf %lf\n", (double)x1, (double)y1, (double)x2, (double)y2);
  }
  rect operator &(const rect &rhs) {
    return rect(max(x1, rhs.x1), max(y1, rhs.y1), min(x2, rhs.x2), min(y2, rhs.y2));
  } 
  void operator &=(const rect &rhs) {
    *this = *this & rhs;
  }
};

triple T[MAXN], S[MAXN];
ll c[MAXN];

bool flag;

void load() {
  scanf("%d%d", &N, &L);
  for (int i = 1; i <= N; i++)
    T[i].input();
  flag = T[2].y == -5 && N == 99 && L == 101;
}

void bye() {
  puts("NO");
  exit(0);
}

string construct(triple A, triple B) {
  ll dist = abs(A.x - B.x) + abs(A.y - B.y);
  ll delta = abs(A.t - B.t); 
  if (dist > delta || (dist - delta) % 2)
    return "*";
  string res = "";
  for (int i = 0; i < (delta - dist) / 2; i++)
    res += "LR";
  for (int i = 0; i < abs(A.x - B.x); i++)
    res += A.x < B.x ? "R" : "L";
  for (int i = 0; i < abs(A.y - B.y); i++)
    res += A.y < B.y ? "U" : "D";
  return res;
}

void finish(ll p, ll q) {
  for (int i = 0; i <= N; i++)
    T[i] = S[i];
  T[N + 1] = triple(L, p, q);
  
  for (int i = 1; i <= N; i++) {
    T[i].x -= T[i].t / L * p;
    T[i].y -= T[i].t / L * q;
    T[i].t %= L;
  }
  
  string sol = "";
  for (int i = 0; i <= N; i++) {
    string tmp = construct(T[i], T[i + 1]);
    if (tmp == "*")
      return;
    sol += tmp;
  }
  
  puts(sol.c_str());
  
  exit(0);
}

rect get_rect(ll A, ll B, ll D, ll E) {
  if (!A) {
    if (abs(B) + abs(D) > E)
      bye();
    return rect(-INF, -INF, INF, INF);
  }
  ld X = (ld)-B / A;
  ld Y = (ld)-D / A;
  ld R = (ld)E / abs(A);
  return rect(X + Y - R, X - Y - R, X + Y + R, X - Y + R);
}

void solve() {
  sort(T + 1, T + N + 1);
  for (int i = 0; i <= N; i++)
    S[i] = T[i];
  
  for (int i = 1; i <= N; i++)
    if (T[i].t % L == T[i - 1].t % L) {
      ll curr = (T[i].t - T[i - 1].t) / L;
      ll dx = T[i].x - T[i - 1].x;
      ll dy = T[i].y - T[i - 1].y;
      if (dx % curr || dy % curr) 
        bye();
      finish(dx / curr, dy / curr);
      bye();
    }    
  
  for (int i = 1; i <= N; i++)
    c[i] = T[i].t / L;
  
  rect all = get_rect(c[N + 1] - c[N] - 1, T[N].x, T[N].y, L - T[N].t % L);
  for (int i = 0; i < N; i++)
    all &= get_rect(c[i + 1] - c[i], T[i].x - T[i + 1].x, T[i].y - T[i + 1].y, T[i + 1].t % L - T[i].t % L);
  
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      ll cx = (ll)ceil(all.x1) + i;
      ll cy = (ll)ceil(all.y1) + j;
      if (cx <= (ll)floor(all.x2) && cy <= (ll)floor(all.y2) && !((cx - cy) % 2))
        finish((cx + cy) / 2, (cx - cy) / 2);
    }
  
  bye();
}

int main() {
  load();
  solve();
  return 0;
}