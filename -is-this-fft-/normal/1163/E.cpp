#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> basis (vector<int> syst, int n) {
  // assume that all vectors in syst are < 1 << (n + 1)
  vector<int> curd (n, 0);
  vector<int> ans;
  for (int vec : syst) {
    int cpy = vec;

    for (int i = 0; i < n; i++) {
      if (vec & 1 << i) {
        vec ^= curd[i];
      }
    }

    if (vec != 0) {
      for (int i = 0; i < n; i++) {
        if (curd[i] == 0 && (vec & 1 << i)) {
          curd[i] = vec;
          break;
        }
      }

      ans.push_back(cpy);
    }
  }

  if ((int) ans.size() == n) {
    return ans;
  } else {
    return vector<int> (0);
  }
}

vector<int> gray (vector<int> vlist) {
  vector<int> ans (1, 0);
  for (int v : vlist) {
    vector<int> dub = ans;
    reverse(dub.begin(), dub.end());
    for (int i = 0; i < (int) dub.size(); i++) {
      ans.push_back(dub[i] ^ v);
    }
  }
  return ans;
}

void solve (vector<int> arr, int n) {
  vector<int> syst;
  for (int u : arr) {
    if (u < (1 << n)) {
      syst.push_back(u);
    }
  }

  vector<int> bsis = basis(syst, n);
  if (bsis.empty()) {
    return;
  }
  
  vector<int> ans = gray(bsis);
  cout << n << endl;
  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> vec (N);
  for (int i = 0; i < N; i++) {
    cin >> vec[i];
  }

  for (int i = 20; i >= 1; i--) {
    solve(vec, i);
  }

  cout << 0 << endl << 0 << endl;
}