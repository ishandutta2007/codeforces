#include <bits/stdc++.h>
using namespace :: std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
struct SuffixArray {
  int N;
  string S;
  vector<int> sa, rank;
  SuffixArray(string S) : S(S), N(S.size()), rank(S.size()+1), sa(S.size()+1) {
  }
  void build() {
    vector<char> ch;
    for (char c : S) ch.pb(c);
    sort(all(ch)); uniq(ch);
    rep(i, N) rank[i] = 1+index(ch, S[i]);
    rank[N] = 0;
    int k = 1;
    while (k <= N) {
      vector<P> ps;
      rep(i, N+1) ps.pb(P(rank[i], rank[min(i+k, N)]));
      sort(all(ps)); uniq(ps);
      rep(i, N+1) rank[i] = index(ps, P(rank[i], rank[min(i+k, N)]));
      k *= 2;
    }
    rep(i, N+1) sa[rank[i]] = i;
  }
  vector<int> f(string T) {
    vector<int> ret;
    int lo = -1, hi = N;
    while (hi - lo > 1) {
      int mid = (lo+hi)/2;
      if (S.compare(sa[mid], T.length(), T) < 0) lo = mid;
      else hi = mid;
    }
    if (S.compare(sa[hi], T.length(), T) != 0) return {};

    int left = hi;
    lo = left, hi = N+1;
    while (hi - lo > 1) {
      int mid = (lo+hi)/2;
      if (S.compare(sa[mid], T.length(), T) <= 0) lo = mid;
      else hi = mid;
    }
    int right = lo;
    assert(S.compare(sa[right], T.length(), T) == 0);
    assert(left <= right);
    for (int i=left; i<=right; i++) ret.pb(sa[i]);
    return ret;
  }
};

string S;
int Q;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> S >> Q;
  SuffixArray sa(S);
  sa.build();
  rep(i, Q) {
    int k; string t;
    cin >> k >> t;
    vector<int> pos = sa.f(t);
    sort(all(pos));
    if (pos.size() < k) {
      cout << -1 << "\n";
    }
    else {
      int m = INF;
      rep(i, pos.size()+1-k) m = min(m, pos[i+k-1]-pos[i]);
      cout << m+t.length() << "\n";
    }
  }
}