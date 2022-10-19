#include <bits/stdc++.h>
using namespace std;

int d[4];
void print_edge(int u, int v) {
  cout << u << " " << v << '\n';
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if ((x+y+z)%2 == 1) {
      cout << "NO\n";
      continue;
    }
    if (2*max({x, y, z}) > x+y+z) {
      cout << "NO\n";
      continue;
    }
    if ((x+y+z)/2+1 > n) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    d[1] = (x+z-y)/2;
    d[2] = (x+y-z)/2;
    d[3] = (y+z-x)/2;
    int v = 4;
    for (int s = 1; s <= 3; s++) {
      if (d[s] == 0) {
        int s2 = s+1;
        int s3 = s+2;
        if (s2 > 3) s2 -= 3;
        if (s3 > 3) s3 -= 3;
        if (d[s2] == 1) {
          print_edge(s, s2);
        }
        else {
          print_edge(s, v);
          for (int i = 1; i < d[s2]; i++) {
            print_edge(v, i+1==d[s2] ? s2 : v+1);
            v++;
          }
        }
        if (d[s3] == 1) {
          print_edge(s, s3);
        }
        else {
          print_edge(s, v);
          for (int i = 1; i < d[s3]; i++) {
            print_edge(v, i+1==d[s3] ? s3 : v+1);
            v++;
          }
        }
        for (; v <= n; v++) {
          print_edge(s, v);
        }
      }
    }
    if (*min_element(d+1, d+4) == 0) continue;
    v = 5;
    for (int s = 1; s <= 3; s++) {
      if (d[s] == 1) {
        print_edge(4, s);
      }
      else {
        print_edge(4, v);
        for (int i = 1; i < d[s]; i++) {
          print_edge(v, i+1==d[s] ? s : v+1);
          v++;
        }
      }
    }
    for (; v <= n; v++) {
      print_edge(4, v);
    }
  }
}