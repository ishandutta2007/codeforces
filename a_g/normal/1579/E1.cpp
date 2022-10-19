#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> indices;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      indices[a[i]] = i;
    }
    vector<int> anchors;
    int index = n;
    for (int i = 1; i <= n; i++) {
      if (indices[i] < index) {
        anchors.push_back(i);
        index = indices[i];
      }
    }

    int stop = n;
    vector<int> tails;
    for (int i: anchors) {
      int index = indices[i];
      cout << i << " ";
      vector<int> part;
      for (int j = index+1; j < stop; j++) {
        part.push_back(a[j]);
      }
      tails.insert(tails.begin(), part.begin(), part.end());
      stop = index;
    }
    for (int i: tails) {
      cout << i << " ";
    }
    cout << endl;
  }
}