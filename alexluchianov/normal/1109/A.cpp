#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;

map<pair<int, int>, int> frec;
int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  ll result = 0;
  frec[{0, 0}]++;

  for(int i = 1 ; i <= n ; i++){
    cin >> v[i];
    v[i] ^= v[i - 1];
    frec[{v[i], i % 2}]++;
    result += frec[{v[i], i % 2}] - 1;
  }
  cout << result;

  return 0;
}