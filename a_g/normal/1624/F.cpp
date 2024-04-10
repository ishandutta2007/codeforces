#include <bits/stdc++.h>
using namespace std;

const bool testing = 0;
int testx = 512;
int added = 0;
int n;

int query(int c) {
  cout << "+ " << c << endl;
  added += c;
  if (!testing) {
    int y;
    cin >> y;
    return y;
  }
  else {
    testx += c;
    return testx/n;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int low = 1;
  int high = n;
  while (low+1 < high) {
    int mid = (low+high)/2;
    int z = mid+added;
    //cout << low << " " << high << " " << z << endl;
    if (z%n != 0) {
      if (query(n-z%n) >= z/n+1) low = mid;
      else high = mid;
    }
    else {
      if (query(n-1) >= z/n+1) high = mid;
      else low = mid;
    }
  }

  cout << "! " << low+added << endl;
  if (testing) cout << testx << endl;
}