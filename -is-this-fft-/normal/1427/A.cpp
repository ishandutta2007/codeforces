#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int n;
  cin >> n;

  vector<int> pos, neg, zs;
  int psum = 0, nsum = 0;
  
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x < 0) {
      neg.push_back(x);
      nsum += x;
    } else if (x == 0) {
      zs.push_back(x);
    } else {
      pos.push_back(x);
      psum += x;
    }

    sum += x;
  }

  if (sum == 0) {
    cout << "NO" << '\n';
    return;
  }

  cout << "YES" << '\n';
  if (psum > -nsum) {
    for (int u : pos) {
      cout << u << " ";
    }
    for (int u : neg) {
      cout << u << " ";
    }
    for (int u : zs) {
      cout << u << " ";
    }
  } else {
    for (int u : neg) {
      cout << u << " ";
    }
    for (int u : pos) {
      cout << u << " ";
    }    
    for (int u : zs) {
      cout << u << " ";
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}