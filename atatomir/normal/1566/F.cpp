#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

typedef pair<int, int> segment;

const int inf = 1 << 30;

void eliminate_wider(vector<segment> &segms) {
  int cnt = 0;
  int last = -inf;

  sort(segms.begin(), segms.end(), [](const segment a, const segment b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
  });

  for (auto segm: segms) {
    if (segm.first <= last) continue;
    last = segm.first;
    segms[cnt++] = segm;
  }

  segms.resize(cnt);
}

void eliminate_containing(vector<segment> &segms, vector<int> &pts) {
  sort(pts.begin(), pts.end());

  int cnt = 0;
  int pos = 0;

  for (auto segm: segms) {
    while (pos < pts.size() && pts[pos] < segm.first)
      pos++;

    if (pos == pts.size() || pts[pos] > segm.second)
      segms[cnt++] = segm;
  }

  segms.resize(cnt);
}

vector<segment> get_group(vector<segment> &segms, int lo, int hi) {
  auto it = lower_bound(segms.begin(), segms.end(), mp(lo, -inf));
  vector<segment> answer(0);

  while (it != segms.end() && it->first <= hi) {
    answer.pb(*it);
    it++;
  }

  return answer;
}

vector<ll> combine(vector<ll> cost, vector<ll> left, vector<ll> right) {
  assert(cost.size() == left.size());
  reverse(cost.begin(), cost.end());
  reverse(left.begin(), left.end());

  // cost decreasing
  // left increasing
  // right increasing

  vector<ll> more_left(left.size());
  vector<ll> more_right(left.size());

  for (int i = 0; i < left.size(); i++) {
    more_left[i] = cost[i] +  left[i];
    more_right[i] = cost[i] + 2LL * left[i];
  }

  for (int i = 1; i < left.size(); i++)
    more_right[i] = min(more_right[i], more_right[i - 1]);

  for (int i = left.size() - 2; i >= 0; i--)
    more_left[i] = min(more_left[i], more_left[i + 1]);

  for (int i = 0; i < right.size(); i++) {
    ll val = right[i];
    int pos = lower_bound(left.begin(), left.end(), val) - left.begin();

    ll more_left_option = (pos < left.size() ? more_left[pos] + val : 1LL << 60);
    ll more_right_option = (pos > 0 ? more_right[pos - 1] : 1LL << 60);

    right[i] = min(more_left_option, more_right_option) + val;
  }

  return right;
}

vector<ll> next_group(vector<ll> curr, vector<segment> prv, ll mid, vector<segment> nxt) {
  assert(curr.size() == prv.size() + 1);

  vector<ll> dists = vector<ll>(0);
  for (int i = 0; i + 1 < curr.size(); i++)  
    dists.pb(mid - prv[i].second);
  dists.pb(0);

  vector<ll> answer = vector<ll>(nxt.size() + 1, 0);
  for (int i = 1; i < answer.size(); i++) 
    answer[i] = nxt[i - 1].first - mid;

  answer = combine(curr, dists, answer);
  return answer;
}


ll compute(const vector< vector<segment> > &groups, const vector<int> &pts) {
  vector<ll> aux = vector<ll>(groups[0].size() + 1, 1LL << 60);
  aux[0] = 0;

  for (int i = 1; i < groups.size(); i++) 
    aux = next_group(aux, groups[i - 1], pts[i - 1], groups[i]);

  return aux[aux.size() - 1];
}

void solve_test() {
  int n, m, x, y;
  vector<int> pts(0);
  vector<segment> segms(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    pts.pb(x);
  }

  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    segms.pb(mp(x, y));
  }

  eliminate_wider(segms);
  eliminate_containing(segms, pts);

  vector< vector<segment> > groups;
  for (int i = 0; i < n; i++) {
    int lo = (i == 0 ? -inf : pts[i - 1]);
    int hi = pts[i];
    groups.pb(get_group(segms, lo, hi));
  }
  groups.pb(get_group(segms, pts[n - 1], inf));

  cout << compute(groups, pts) << '\n';
}

int main()
{
  //freopen("test.in", "r", stdin);

  int t;
  cin >> t;

  for (int ti = 0; ti < t; ti++) {
    solve_test();
  }


  return 0;
}