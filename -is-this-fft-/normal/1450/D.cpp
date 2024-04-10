#include <iostream>

using namespace std;

const int MAX_N = 3e5 + 5;

int arr [MAX_N];
int cnt [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }
  
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }

  int minl = 1;
  int l = 1, r = n, cur = 1;
  while (l <= r) {
    if (cnt[cur] == 0) {
      minl = r - l + 2;
      break;
    } else if (cnt[cur] > 1 || (arr[l] != cur && arr[r] != cur)) {
      minl = r - l + 1;
      break;
    } else if (arr[l] == cur) {
      l++;
    } else if (arr[r] == cur) {
      r--;
    }
    
    cur++;
  }

  bool perm = true;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] != 1) {
      perm = false;
    }
  }

  cout << perm;
  for (int i = 2; i <= n; i++) {
    cout << (minl <= i);
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