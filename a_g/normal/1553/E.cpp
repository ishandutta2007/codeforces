#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+7;
int p[N];
int z[N];
bool visited[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
      z[(i+n-p[i])%n]++;
    }

    vector<int> answers;
    for (int k = 0; k < n; k++) {
      if (z[k] >= n-2*m) {
        int cycles = 0;
        for (int i = 0; i < n; i++) {
          if (!visited[i]) {
            int v = i;
            cycles++;
            while (!visited[v]) {
              visited[v] = 1;
              v = p[(v+k)%n];
            }
          }
        }
        fill(visited, visited+n, 0);
        if (n-cycles <= m) answers.push_back(k);
      }
    }
    cout << answers.size() << ' ';
    for (int k: answers) cout << k << ' ';
    cout << '\n';

    fill(z, z+n, 0);
  }
}