#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int v[5 + nmax];

int main()
{
  int n, h;
  cin >> n >> h;
  for(int i = 1;i <= n;i++)
    cin >> v[i];
  for(int i = 1;i <= n;i++) {
    sort(v + 1, v + i + 1);
    int sum = 0;
    for(int j = i; 0 < j; j -= 2){
      sum += v[j];
    }
    if(h < sum){
      cout << i - 1;
      return 0;
    }
  }
  cout << n;
  return 0;
}