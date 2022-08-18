#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

void failure () {
  cout << 0 << endl;
  exit(0);
}

struct Jump {
  ll cost, nxt;
};

vector<Jump> mul (const vector<Jump> &a, const vector<Jump> &b) {
  int n = a.size();
  vector<Jump> ans (n);
  for (int i = 0; i < n; i++) {
    ans[i].cost = a[i].cost + b[a[i].nxt].cost;
    ans[i].nxt = b[a[i].nxt].nxt;
  }
  return ans;
}

bool is_ok (const vector<Jump> &a, int maxc) {
  if (a[0].cost < maxc) return true;
  if (a[0].cost == maxc && a[0].nxt == 0) return true;
  return false;
}

ll max_power (const vector<Jump> &base, int maxc) {
  if (!is_ok(base, maxc)) {
    return 0;
  }

  vector<vector<Jump>> pws;
  pws.push_back(base);
  while (true) {
    auto nxtpw = mul(pws.back(), pws.back());
    if (!is_ok(nxtpw, maxc)) {
      break;
    }
    pws.push_back(nxtpw);
  }

  ll ans = 1LL << ((int) pws.size() - 1);
  auto cur = pws.back();
  pws.pop_back();

  while (!pws.empty()) {
    auto nxtcur = mul(cur, pws.back());
    if (is_ok(nxtcur, maxc)) {
      ans += 1LL << ((int) pws.size() - 1);
      cur = nxtcur;
    }
    pws.pop_back();
  }

  return ans;
}

const int ALPH = 128;

set<int> pos [ALPH];

Jump trace (int cur, const string &s, int asz) {
  Jump ans;
  ans.cost = 0;
  
  for (char c : s) {
    if (pos[c].empty()) {
      failure();
    }

    if (pos[c].lower_bound(cur) != pos[c].end()) {
      cur = *pos[c].lower_bound(cur) + 1;
    } else {
      ans.cost++;
      cur = *pos[c].begin() + 1;
    }

    if (cur == asz) {
      ans.cost++;
      cur = 0;
    } 
  }

  ans.nxt = cur;
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  int B, D;
  cin >> B >> D;

  string a, s;
  cin >> a >> s;

  for (int i = 0; i < (int) a.size(); i++) {
    pos[a[i]].insert(i);
  }
  
  vector<Jump> base;
  for (int i = 0; i < (int) a.size(); i++) {
    base.push_back(trace(i, s, a.size()));
  }

  auto ans = max_power(base, B);
  ans /= D;

  cout << ans << '\n';
}