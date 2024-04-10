#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 50;

int arr [MAX_N];
int pos [MAX_N];

vector<int> ans;
void rev (int cnt) {
  reverse(arr, arr + cnt);
  for (int i = 0; i < cnt; i++) {
    pos[arr[i]] = i;
  }
  ans.push_back(cnt);
}

void solve () {
  int n;
  cin >> n;

  int on = n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
    pos[arr[i]] = i;
  }
  ans.clear();

  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 != i % 2) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int a = n - 2; a > 0; a -= 2) {
    int b = a + 1;

    // a - an odd value; b - the even value after it
    rev(pos[b] + 1);
    rev(pos[a]);
    rev(pos[a] + 2);
    rev(pos[b] + 1);
    rev(n);

    n -= 2;
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

  for (int t = 0; t < testc; t++) {
    solve();
  }
}