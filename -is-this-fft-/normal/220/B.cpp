#include <iostream>
#include <vector>

using namespace std;

class Fenwick {
  vector<int> tree;
  
public:
  Fenwick (int _n) : tree(_n + 5, 0) {
  }
  
  void add (int pos, int val) {
    for (int i = pos; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  int get (int pos) {
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }
};

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
vector<int> pos [MAX_N];

vector<pair<int, int>> adds [MAX_N];
vector<pair<int, int>> dels [MAX_N];
vector<pair<int, int>> qs [MAX_N]; // r, id
int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] < MAX_N) {
      pos[arr[i]].push_back(i);
    }
  }

  for (int i = 1; i < MAX_N; i++) {
    for (int j = 0; j + i - 1 < (int) pos[i].size(); j++) {
      int ll = j == 0 ? 1 : pos[i][j - 1] + 1;
      int lr = pos[i][j];

      int rl = pos[i][j + i - 1];
      int rr = j + i == (int) pos[i].size() ? n : pos[i][j + i] - 1;

      // we sweep up by l
      adds[ll].push_back(make_pair(rl, rr));
      dels[lr].push_back(make_pair(rl, rr));
    }
  }

  for (int i = 0; i < qc; i++) {
    int l, r;
    cin >> l >> r;

    qs[l].push_back(make_pair(r, i));
  }

  Fenwick fen (MAX_N);
  for (int l = 0; l < MAX_N; l++) {
    for (auto pr : adds[l]) {
      fen.add(pr.first, 1);
      fen.add(pr.second + 1, -1);
    }

    for (auto q : qs[l]) {
      ans[q.second] = fen.get(q.first);
    }

    for (auto pr : dels[l]) {
      fen.add(pr.first, -1);
      fen.add(pr.second + 1, 1);
    }
  }

  for (int i = 0; i < qc; i++) {
    cout << ans[i] << '\n';
  }
}