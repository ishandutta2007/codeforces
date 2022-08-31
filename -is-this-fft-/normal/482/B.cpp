#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

const int MAX_N = 1e5 + 5;
const int MAX_LG = 30;

vector<int> opens [MAX_N];
vector<pair<int, int>> closes [MAX_N];
int stk [MAX_N];
int lastnon [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int l, r, q;
    cin >> l >> r >> q;

    opens[l].push_back(q);
    closes[r].push_back(make_pair(l, q));
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (int q : opens[i]) {
      for (int j = 0; j < MAX_LG; j++) {
        if (q & 1 << j) {
          stk[j]++;
        }
      }
    }

    int cur = 0;
    for (int j = 0; j < MAX_LG; j++) {
      if (stk[j] == 0) {
        lastnon[j] = i;
      } else {
        cur |= 1 << j;
      }
    }
    ans.push_back(cur);

    for (auto pr : closes[i]) {
      int l = pr.first;
      int q = pr.second;

      int real = 0;
      for (int j = 0; j < MAX_LG; j++) {
        if (lastnon[j] < l) {
          real |= 1 << j;
        }
      }

      if (real != q) failure();

      for (int j = 0; j < MAX_LG; j++) {
        if (q & 1 << j) {
          stk[j]--;
        }
      }
    }
  }

  cout << "YES" << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}