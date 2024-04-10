#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 20;
const int MAX_M = 85;
const int INF = 1 << 30;

int pos [MAX_M];
int rad [MAX_M];
int dp [MAX_N][MAX_M][2];

int ftree [MAX_N][2];
void add (int idx, int bit, int val) {
  idx = MAX_N - idx;
  for (int i = idx; i < MAX_N; i += i & -i) {
    ftree[i][bit] = min(ftree[i][bit], val);
  }
}

int get (int idx, int bit) {
  idx = MAX_N - idx;
  int ans = INF;
  for (int i = idx; i > 0; i -= i & -i) {
    ans = min(ans, ftree[i][bit]);
  }
  return ans;
}

int main () {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < 2; j++) {
      ftree[i][j] = INF;
    }
  }
  
  ios::sync_with_stdio(false);

  int antc, length;
  cin >> antc >> length;

  for (int i = 0; i < antc; i++) {
    cin >> pos[i] >> rad[i];
  }

  for (int i = 1; i < 2 * length + 5; i++) {
    for (int j = 0; j < antc; j++) {
      if (pos[j] <= i) {
        int cost0, cost1;
        int crad = i - pos[j];
        if (pos[j] - crad > 0) {
          cost0 = get(pos[j] - crad - 1, 0) + max(0, crad - rad[j]);
          cost1 = get(pos[j] - crad - 1, 1) + max(0, crad - rad[j]);
          cost0 = min(cost0, cost1);
        } else {
          cost0 = max(0, crad - rad[j]);
          cost1 = max(0, crad - rad[j]);
        }

        if (cost0 > INF) cost0 = INF;
        if (cost1 > INF) cost1 = INF;
        
        add(i, 0, cost0);
        add(i, 1, cost1);
      }
    }
  }

  cout << get(length, 1) << endl;
}