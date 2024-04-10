#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 5e5 + 5;

int A [MAX_N];
int B [MAX_N];
vector<pair<int, int>> sta [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    sta[i].clear();
  }
  
  for (int i = 1; i <= n; i++) {
    cin >> B[i];

    int L = i / (B[i] + 1) + 1;
    int R = B[i] == 0 ? n : i / B[i];

    sta[L].push_back({R, i});
  }

  set<pair<int, int>> cur;
  for (int i = 1; i <= n; i++) {
    for (auto pr : sta[i]) {
      cur.insert(pr);
    }

    auto x = *cur.begin();
    cur.erase(x);

    A[x.second] = i;
  }

  for (int i = 1; i <= n; i++) {
    cout << A[i] << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}