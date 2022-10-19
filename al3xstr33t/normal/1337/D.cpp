#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

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

const ll inf = 1LL << 62;

int t, r, g, b, x;
vector< pair<int, int> > gems;
vector<int> ord[3];
ll last[3];
ll answer;

void readGems(int cnt, int id) {
  for (int i = 1; i <= cnt; i++) {
    scanf("%d", &x);
    gems.pb(mp(x, id));
  }
}

void orderGems() {
  sort(gems.begin(), gems.end());
  for (auto e: gems) 
    ord[e.second].pb(e.first);
}

void update(ll x, ll y, ll z) {
  ll aux = (x - y) * (x - y) + 
           (y - z) * (y - z) +
           (z - x) * (z - x);
  answer = min(answer, aux);
}

void check(ll x, ll y, int id) {
  ll z = (x + y) >> 1;
  int pos = lower_bound(ord[id].begin(), ord[id].end(), z) - ord[id].begin();
  if (pos < ord[id].size())
    update(x, y, ord[id][pos]);
  if (pos > 0)
    update(x, y, ord[id][pos - 1]);
}

void solve() {
  last[0] = last[1] = last[2] = -1;
  for (auto e: gems) {
    last[e.second] = e.first;

    if (last[0] == -1) continue;
    if (last[1] == -1) continue;
    if (last[2] == -1) continue;

    int id1 = (e.second + 1) % 3;
    int id2 = (id1 + 1) % 3;
    check(e.first, last[id1], id2);
    check(e.first, last[id2], id1);
  }
}

int main()
{
  //freopen("test.in", "r", stdin);

  scanf("%d", &t);
  for (int ti = 1; ti <= t; ti++) {
    ord[0].clear();
    ord[1].clear();
    ord[2].clear();
    gems.clear();
    answer = inf;

    scanf("%d%d%d", &r, &g, &b);
    gems.reserve(r + g + b);
    ord[0].reserve(r);
    ord[1].reserve(g);
    ord[2].reserve(b);

    readGems(r, 0);
    readGems(g, 1);
    readGems(b, 2);

    orderGems();
    solve();
    printf("%lld\n", answer);
  }


  return 0;
}