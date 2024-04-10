#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 5;

int n;
vector<int> ask (vector<int> ws) {
  if (ws.empty()) {
    return vector<int> (n, INF);
  }

  cout << (int) ws.size() << endl;
  for (int w : ws) {
    cout << w + 1 << " ";
  }
  cout << endl;

  vector<int> ans (n);
  for (int i = 0; i < n; i++) {
    cin >> ans[i];
  }
  return ans;
}

vector<int> report (vector<int> ans) {
  cout << -1 << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;

  exit(0);
}

const int MAX_N = 1e3 + 5;
const int MAX_LG = 10;

vector<int> minof [MAX_LG][2];

void askbin (int bit, int state) {
  vector<int> ws;
  for (int i = 0; i < n; i++) {
    if (((i >> bit) & 1) == state) {
      ws.push_back(i);
    }
  }

  minof[bit][state] = ask(ws);
}

int main () {
  cin >> n;
  for (int i = 0; i < MAX_LG; i++) {
    for (int j = 0; j < 2; j++) {
      askbin(i, j);
    }
  }

  vector<int> ans (n, INF);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX_LG; j++) {
      ans[i] = min(ans[i], minof[j][!((i >> j) & 1)][i]);
    }
  }

  report(ans);
}