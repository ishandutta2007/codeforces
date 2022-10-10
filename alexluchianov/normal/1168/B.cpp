#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define ll long long

int const nmax = 300000;
char v[1 + nmax];

int main()
{
  int n;
  cin >> (v + 1);
  n = strlen(v + 1);

  ll result = 0;
  for(int i = 1;i <= n;i++){
    for(int j = i + 2;j <= n; j++){
      bool ok = 0;
      for(int d = 1; i <= j - d * 2; d++)
        if(v[j] == v[j - d] && v[j] == v[j - d * 2])
          ok = 1;
      if(ok == 1) {
        result += (n - j + 1);
        break;
      }
    }
  }
  cout << result;
  return 0;
}