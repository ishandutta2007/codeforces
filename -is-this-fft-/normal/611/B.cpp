#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<long long> goodnums;

  goodnums.push_back(2LL);
  for (long long i = 3; i < 64; i++) {
    long long ones = (1LL << i) - 1LL;
    for (long long j = 0; j < i - 1; j++) {
      goodnums.push_back(ones ^ 1LL << j);
    }
  }


  long long left, right, ans = 0;
  cin >> left >> right;
  for (int i = 0; i < goodnums.size(); i++) {
    if (goodnums[i] >= left && goodnums[i] <= right) {
      ans++;
    }
  }
  
  cout << ans << endl;
}