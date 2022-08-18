#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 5;

int arr [MAX_N];
int cnt [MAX_N];

int mex () {
  for (int i = 0; true; i++) {
    if (cnt[i] == 0) return i;
  }
}

void setmex (int idx) {
  int mx = mex();
  cnt[arr[idx]]--;
  arr[idx] = mx;
  cnt[arr[idx]]++;
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    cnt[i] = 0;
  }
  
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  vector<int> ans;
  while (true) {
    int mx = mex();
    if (mx == n) {
      // is it sorted?
      bool ok = 1;
      for (int i = 0; i < n; i++) {
        if (arr[i] != i) {
          ok = 0;
        }
      }
      if (ok) break;

      int pos = -1;
      for (int i = 0; i < n; i++) {
        if (arr[i] != i) {
          pos = i;
          break;
        }
      }
      setmex(pos);
      ans.push_back(pos);
    } else {
      setmex(mx);
      ans.push_back(mx);
    }
  }
  
  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u + 1 << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}