#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];
set<int> excl;
set<int> pos [MAX_N];
int cnt [MAX_N];

void rem (int x) {
  cnt[x]--;
  if (cnt[x] == 0) {
    excl.insert(x);
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    pos[i].clear();
    cnt[i] = 0;
  }

  excl.clear();
  for (int i = 0; i <= n + 1; i++) {
    excl.insert(i);
  }
 
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    pos[arr[i]].insert(i);
    excl.erase(arr[i]);
    cnt[arr[i]]++;
  }

  vector<int> ans;
  int cur = 0;
  while (cur < n) {
    int mex = *excl.begin();
    int npos = cur + 1;
    for (int i = 0; i < mex; i++) {
      npos = max(npos, 1 + *pos[i].lower_bound(cur));
    }

    for (int i = cur; i < npos; i++) {
      rem(arr[i]);
    }

    ans.push_back(mex);
    cur = npos;
  }

  cout << (int) ans.size() << '\n';
  for (int u : ans) {
    cout << u << " ";
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