#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int frec[1 + nmax], _lower[1 + nmax];

bool test(int target, int val2){
  int val1 = target;
  while(0 < val1 || 0 < val2){
    if(target < val1)
      val1 = _lower[target];
    else if(target < val2)
      val2 = 0;
    else if(val1 < val2){
      target -= val2;
      val2 = 0;
    } else {
      target -= min(target / val1, frec[val1]) * val1;
      val1 = _lower[val1 - 1];
    }
  }
  return (target == 0);
}

int main()
{
  int sum, n;
  cin >> sum >> n;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    frec[val]++;
  }

  frec[0] = 1;
  for(int i = 1;i <= sum; i++) {
    if(frec[i] == 0)
      _lower[i] = _lower[i - 1];
    else
      _lower[i] = i;
  }

  for(int i = 0;i <= sum; i++)
    if(test(sum, i) == 0){
      cout << i;
      return 0;
    }
  cout << "Greed is good";
  return 0;
}