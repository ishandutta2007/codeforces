#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 5;

int arr [MAX_N];
vector<int> apps [MAX_N];

int cumc [MAX_N];

int main () {
  int n, c;
  cin >> n >> c;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    apps[arr[i]].push_back(i);

    if (c == arr[i]) {
      cumc[i]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cumc[i] += cumc[i - 1];
  }
  
  int ans = cumc[n];
  for (int i = 1; i < MAX_N; i++) {
    if (i != c) {
      int diff = 0;
      int minseen = MAX_N;
      int cumi = 0;
      
      for (int u : apps[i]) {
        // consider u - 1
        if (1) {
          int cur = cumi - cumc[u - 1];
          diff = max(diff, cur - minseen);
          minseen = min(minseen, cur);
        }

        // consider u
        if (1) {
          cumi++;
          int cur = cumi - cumc[u];
          diff = max(diff, cur - minseen);
          minseen = min(minseen, cur);
        }
      }

      ans = max(ans, cumc[n] + diff);
    }
  }

  cout << ans << endl;
}