#include <iostream>
#include <algorithm>

using namespace std;

int const nmax = 100000;
int v[5 + nmax];

int main() {
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  sort(v + 1, v + n + 1);
  int sum = 0;
  int result = 0;
  for(int i = 1 ; i <= n ; i++) {
    if(sum <= v[i]) {
      sum += v[i];
      result++;
    }
  }
  cout << result;
  return 0;
}