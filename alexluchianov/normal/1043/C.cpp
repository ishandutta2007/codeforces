#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) :(b))
#define MAX(a , b) (((a) < (b)) ? (b) :(a))

int const nmax = 1000;

char v[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> (v + 1);

  n = strlen(v + 1);

  for(int i = 1 ; i <= n ; i++){
    bool ok = 0;

    if(v[i] == 'b' && v[i + 1] == 'a')
      ok |= 1;
    else if(v[i] == 'a' && (v[i + 1] == 'b' || i == n))
      ok |= 1;

    cout << ok << " ";
  }
  return 0;
}