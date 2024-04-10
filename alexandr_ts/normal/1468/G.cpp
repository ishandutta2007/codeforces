#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2 * 1e9;
const ll N = 1e6;
const ld EPS = 1e-9;

struct PtInt {
    ll x, y;
    PtInt() {}
    PtInt(ll x, ll y): x(x), y(y) {}

    PtInt operator - (const PtInt& a) const {
        return {x - a.x, y - a.y};
    }
    void read() {
      cin >> x >> y;
    }
};


struct Pt {
    ld x, y;
    Pt() {}
    Pt(ld x, ld y): x(x), y(y) {}
    Pt(PtInt p): x(p.x), y(p.y) {}

    Pt operator - (const Pt& a) const {
        return {x - a.x, y - a.y};
    }
    Pt operator + (const Pt& a) const {
        return {x + a.x, y + a.y};
    }
    Pt operator * (ld k) const {
        return {x * k, y * k};
    }
    Pt operator / (ld k) const {
        return {x / k, y / k};
    }
    bool operator < (const Pt& a) const {
      if (x != a.x) return x < a.x;
      return y < a.y;
    }
    void read() {
      cin >> x >> y;
    }
};

struct Line {
    ld a, b, c;
    Line() {}
    Line(ld a, ld b, ld c): a(a), b(b), c(c) {}

    Line(Pt p1, Pt p2) {
      a = p1.y - p2.y;
      b = p2.x - p1.x; 
      c = p1.x * p2.y - p2.x * p1.y;
    }
};

Line get_ort_line(Pt a, Line l) {
    Line ans = Line(-l.b, l.a, 0);
    ans.c = -(ans.a * a.x + ans.b * a.y);
    return ans;
}

ld pt_line_dist(Pt p, Line l) {
  return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

ld pt_dist(Pt a, Pt b) {
  return hypotl(a.x - b.x, a.y - b.y);
}

bool is_pt_on_line(Pt p, Line l) {
  return pt_line_dist(p, l) < EPS; 
}

ld cross_product(Pt a, Pt b) {
    return a.x * b.y - a.y * b.x;
}

ld dot_product(Pt a, Pt b) {
    return a.x * b.x + a.y * b.y;
}

Pt get_lines_intersect(Line a, Line b) {
    return Pt((a.b * b.c - a.c * b.b) / (a.a * b.b - a.b * b.a), (a.a * b.c - a.c * b.a) / (a.b * b.a - a.a * b.b));
}

void test() {
  Pt p1{12, 134};
  Pt p2{31, -98};
  Pt p3{-52, 18};  
  assert(p3 < p1);
  Line l1(p1, p2);
  assert(is_pt_on_line(p1, l1));
  assert(is_pt_on_line(p2, l1));
  Line l2(p2, p3);
  assert(is_pt_on_line(p2, l2));
  assert(is_pt_on_line(p3, l2));
  Pt inter = get_lines_intersect(l1, l2);
  assert(abs(p2.x - inter.x) < EPS && abs(p2.y - inter.y) < EPS);

  Line l_ort = get_ort_line(p3, l1);
  assert(is_pt_on_line(p3, l_ort));
  Pt n1 = {l1.a, l1.b};
  Pt n_ort= {l_ort.a, l_ort.b};
  assert(abs(dot_product(n1, n_ort)) < EPS);

  {
    Pt p1{0, 4};
    Pt p2{3, 0};
    assert(abs(pt_dist(p1, p2) - 5) < EPS);
    assert(abs(abs(cross_product(p1, p2)) - 12) < EPS);
  }
}

PtInt a[N];

void solve() {
  int n, h;
  cin >> n >> h;
  for (int i = 0; i < n; ++i) {
    a[i].read();
  }

  PtInt eye = a[n - 1];
  eye.y += h;


  vector<pair<PtInt, int>> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = {a[i] - eye, i};
    //cout << v[i].first.x << " " << v[i].first.y << endl;
  }

  sort(v.begin(), v.end(), [](const pair<PtInt, int>& lhs, const pair<PtInt, int>& rhs) {
    ll crpr = lhs.first.x * rhs.first.y - lhs.first.y * rhs.first.x;
    if (!crpr) {
      return lhs.first.x > rhs.first.x;
    }
    return crpr < 0;
  });

  int cur_max = n - 1;
  set<int> left_ids;
  for (int i = 0; i < n; ++i) {
    left_ids.insert(i);
  }

  vector<int> ids;
  for (int i = 0; i < n; ++i) {
    if (cur_max == v[i].second) {
      ids.push_back(v[i].second); 
    }
    left_ids.erase(v[i].second);
    while (!left_ids.empty() && (*prev(left_ids.end())) < cur_max) {
      cur_max--;
    }
  }

  /*
  for (auto x: ids) {
    cout << x << " ";
  }
  cout << endl;
  */

  ld ans = 0;
  for (int i = 1; i < ids.size(); ++i) {
    Pt p1 = a[ids[i]];
    Pt p2 = a[ids[i] + 1];
    Pt q = a[ids[i - 1]];
    if (abs(q.x - p2.x) + abs(q.y - p2.y) < EPS) {
      ans += pt_dist(p1, p2);
    } else {
      auto l = Line(eye, q);
      auto l_set = Line(p1, p2);
      auto inter = get_lines_intersect(l, l_set);
      ans += pt_dist(inter, p1);
    }
  }

  cout << fixed << setprecision(12) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}