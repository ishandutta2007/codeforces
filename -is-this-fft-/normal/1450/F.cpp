#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
int cnt [MAX_N];
int cntp [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
    cntp[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, cnt[i]);
  }

  if (mx > n - mx + 1) {
    cout << -1 << '\n';
    return;
  }
    
  vector<pair<int, int>> dom;
  int bgn = arr[0];
  for (int i = 0; i < n; i++) {
    if (i == n - 1 || arr[i + 1] == arr[i]) {
      dom.push_back(make_pair(bgn, arr[i]));
      bgn = arr[i + 1];
    }
  }

  for (auto pr : dom) {
    if (pr.first == pr.second) {
      cntp[pr.first]++;
    }
  }

  pair<int, int> mxp = make_pair(0, -1);
  for (int i = 1; i <= n; i++) {
    mxp = max(mxp, make_pair(cntp[i], i));
  }

  int indc = 0;
  for (auto pr : dom) {
    if (pr.first != mxp.second && pr.second != mxp.second) {
      indc++;
    }
  }

  cout << max(0, mxp.first - (indc + 1)) + (int) dom.size() - 1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}