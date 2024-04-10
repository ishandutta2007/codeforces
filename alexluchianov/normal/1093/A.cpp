#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))


int main()
{
  int t;
  cin >> t;
  for(int i = 1 ; i <= t ; i++){
    int x;
    cin >> x;
    cout << x / 2 << '\n';
  }
  return 0;
}