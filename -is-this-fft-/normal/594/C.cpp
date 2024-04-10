#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;
#define x first
#define y second

const int MAX_N = 1e5 + 5;

point arr [MAX_N];

struct byx {
  bool operator() (int p, int q) {
    if (arr[p].x != arr[q].x) {
      return arr[p].x < arr[q].x;
    }
    if (arr[p].y != arr[q].y) {
      return arr[p].y < arr[q].y;
    }
    return p < q;
  }
};

struct byy {
  bool operator() (int p, int q) {
    if (arr[p].y != arr[q].y) {
      return arr[p].y < arr[q].y;
    }
    if (arr[p].x != arr[q].x) {
      return arr[p].x < arr[q].x;
    }
    return p < q;
  }
};

set<int, byx> xset;
set<int, byy> yset;

void insert (int p) {
  xset.insert(p);
  yset.insert(p);
}

void erase (int p) {
  xset.erase(p);
  yset.erase(p);
}

ll norm (ll l, ll r) {
  if (l % 2 == r % 2) return max(2LL, r - l);
  if (r % 2 == 1) r++;
  if (l % 2 == 1) l--;
  return max(2LL, r - l);
}

ll ans;
void dfs (int idx, int state, int K) {
  if (idx == K) {
    ll xmn = arr[*xset.begin()].x;
    ll xmx = arr[*xset.rbegin()].x;
    ll ymn = arr[*yset.begin()].y;
    ll ymx = arr[*yset.rbegin()].y;
    ll w = norm(xmn, xmx);
    ll h = norm(ymn, ymx);
    ans = min(ans, h * w / 4);
  } else {
    int rem;
    if (state == 0) {
      rem = *xset.begin();
    } else if (state == 1) {
      rem = *xset.rbegin();
    } else if (state == 2) {
      rem = *yset.begin();
    } else if (state == 3) {
      rem = *yset.rbegin();
    }
    erase(rem);
    for (int i = state; i < 4; i++) {
      dfs(idx + 1, i, K);
    }
    insert(rem);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  ans = 1LL << 62;
  for (int i = 0; i < n; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    arr[i] = make_pair(x1 + x2, y1 + y2);
    insert(i);
  }

  for (int i = 0; i < 4; i++) {
    dfs(0, i, K);
  }

  cout << ans << endl;
}