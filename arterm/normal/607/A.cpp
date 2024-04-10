#include <bits/stdc++.h>

using namespace std;

const int M = 1000100;

int n;
int b[M];
int d[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int at, x;
    cin >> at >> x;
    ++at;
    b[at] = x + 1;
  }
}

    
void din() {
  for (int i = 1; i < M; ++i)
    if (b[i] == 0)
      d[i] = d[i - 1];
    else {
      d[i] = 1 + d[i - min(b[i], i)];
    }

  int ans = 0;
  for (int i = 0; i < M; ++i)
    ans = max(ans, d[i] + 1);

  cout << n + 1 - ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  din();
  return 0;
}