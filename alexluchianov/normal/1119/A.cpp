#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ;i <= n;i++)
    cin >> v[i];
  int st = 1, dr = n;
  while(v[st] == v[1])
    st++;
  while(v[dr] == v[1])
    dr--;
  cout << MAX(dr - 1, n - st);

  return 0;
}