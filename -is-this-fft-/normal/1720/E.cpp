#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 505;
const int MAX_A = MAX_N * MAX_N;

int arr [MAX_N][MAX_N];
int mni [MAX_A];
int mxi [MAX_A];
int mnj [MAX_A];
int mxj [MAX_A];

int mod [MAX_N];
vector<int> sta [MAX_N];
vector<int> fin [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < MAX_A; i++) {
    mni[i] = n + 1;
    mxi[i] = -1;
    mnj[i] = n + 1;
    mxj[i] = -1;
  }

  set<int> seen;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      seen.insert(x);
      arr[i][j] = x;
      mni[x] = min(mni[x], i);
      mxi[x] = max(mxi[x], i);
      mnj[x] = min(mnj[x], j);
      mxj[x] = max(mxj[x], j);
    }
  }

  int tot = seen.size();
  if (tot <= K) {
    cout << K - tot << endl;
    return 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 0; i < n; i++) {
      sta[i].clear();
      fin[i].clear();
      mod[i] = 0;
    }
    
    for (int a = 0; a < MAX_A; a++) {
      if (mni[a] > mxi[a]) continue;
      if (mxi[a] - mni[a] >= k) continue;
      if (mxj[a] - mnj[a] >= k) continue;

      int l = max(0, mxi[a] - k + 1);
      int r = mni[a];
      sta[l].push_back(a);
      fin[r].push_back(a);
    }

    for (int i = 0; i < n - k + 1; i++) {
      for (int a : sta[i]) {
        int l = max(0, mxj[a] - k + 1);
        int r = mnj[a] + 1;
        mod[l]++;
        mod[r]--;
      }

      int cov = 0;
      for (int j = 0; j < n - k + 1; j++) {
        cov += mod[j];
        if (tot - cov == K || tot - cov == K - 1) {
          cout << 1 << endl;
          return 0;
        }
      }
      
      for (int a : fin[i]) {
        int l = max(0, mxj[a] - k + 1);
        int r = mnj[a] + 1;
        mod[l]--;
        mod[r]++;
      }
    }
  }

  cout << 2 << endl;
  return 0;
}