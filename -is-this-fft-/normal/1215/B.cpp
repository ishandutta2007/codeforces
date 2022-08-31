#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);

  vector<int> cnt = {1, 0};
  vector<ll> ans = {0, 0};
  
  int N;
  cin >> N;
  int sgn = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x < 0) sgn = !sgn;
    for (int k = 0; k < 2; k++) {
      ans[k] += cnt[sgn ^ k];
    }
    cnt[sgn]++;
  }

  cout << ans[1] << " " << ans[0] << endl;
}