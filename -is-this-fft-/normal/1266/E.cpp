#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

int A [MAX_N];
int cnt [MAX_N];

ll milec;
ll crapc;
map<pair<int, int>, int> miles;
void del_mile (int s, int n) {
  if (miles.count({s, n}) == 0 || miles[{s, n}] == 0) {
    return;
  }

  int u = miles[{s, n}];
  miles[{s, n}] = 0;
  milec--;
  if (cnt[u] > A[u]) {
    crapc -= cnt[u] - A[u];
  }
  cnt[u]--;
  if (cnt[u] > A[u]) {
    crapc += cnt[u] - A[u];
  }
}

void add_mile (int s, int n, int u) {
  miles[{s, n}] = u;
  if (cnt[u] > A[u]) {
    crapc -= cnt[u] - A[u];
  }
  cnt[u]++;
  if (cnt[u] > A[u]) {
    crapc += cnt[u] - A[u];
  }
  milec++;
}

void query (int s, int n, int u) {
  del_mile(s, n);
  if (u > 0) {
    add_mile(s, n, u);
  }
}

int main () {
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    ans += A[i];
  }

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int s, n, u;
    cin >> s >> n >> u;

    query(s, n, u);
    // cerr << ans << " " << milec << " " << crapc << " " << cnt[1] << endl;
    cout << ans - milec + crapc << '\n';
  }
}