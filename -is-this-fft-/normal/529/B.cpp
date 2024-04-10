#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Person;
#define w first
#define h second

const int INF = 1e9 + 5;
const int MAX_N = 1e3 + 5;

Person arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].w >> arr[i].h;
  }

  int ans = INF;

  // max height
  for (int H = 1; H <= MAX_N; H++) {
    bool fail = false;
    int W = 0;
    int flipped = 0;

    vector<int> gains;
    
    for (int i = 0; i < n; i++) {
      if (arr[i].h > H && arr[i].w > H) {
        fail = true;
      } else if (arr[i].h > H) {
        flipped++;
        W += arr[i].h;
      } else {
        W += arr[i].w;

        if (arr[i].w <= H && arr[i].h < arr[i].w) {
          gains.push_back(arr[i].h - arr[i].w);
        }
      }
    }

    if (flipped > n / 2) {
      fail = true;
    }

    sort(gains.begin(), gains.end());

    for (int i = 0; i < (int) gains.size() && flipped < n / 2; i++) {
      flipped++;
      W += gains[i];
    }

    if (!fail) {
      ans = min(ans, H * W);
    }
  }

  cout << ans << endl;
}