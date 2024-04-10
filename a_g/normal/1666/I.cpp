#include <bits/stdc++.h>
using namespace std;

const bool testing = 0;
int tr1 = 1;
int tr2 = 2;
int tc1 = 4;
int tc2 = 3;


int scan(int r, int c) {
  cout << "SCAN " << r << " " << c << endl;
  if (testing) {
    return abs(tr1-r) + abs(tr2-r) + abs(tc1-c) + abs(tc2-c);
  }
  int k;
  cin >> k;
  return k;
}

int dig(int r, int c) {
  cout << "DIG " << r << " " << c << endl;
  if (testing) {
    return (r == tr1 && c == tc1 || r == tr2 && c == tc2);
  }
  int k;
  cin >> k;
  return k;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int a = scan(1, 1); // r1 + r2 + c1 + c2 - 4
    int b = scan(1, m); // r1 + r2 - (c1 + c2) + 2m - 2
    int rsum = (a + b)/2 + 3 - m;
    int csum = a + 4 - rsum;
    //cout << rsum << " " << csum << endl;
    int c = scan(rsum/2, 1); // r2 - r1 + c1 + c2 - 2
    int d = scan(1, csum/2); // c2 - c1 + r1 + r2 - 2
    int rdiff = c - csum + 2;
    int cdiff = d - rsum + 2;
    //cout << rdiff << " " << cdiff << " " << endl;
    int r1 = (rsum-rdiff)/2;
    int r2 = (rsum+rdiff)/2;
    int c1 = (csum-cdiff)/2;
    int c2 = (csum+cdiff)/2;
    if (dig(r1, c1)) {
      assert(dig(r2, c2));
    }
    else {
      dig(r1, c2);
      dig(r2, c1);
    }
  }
}