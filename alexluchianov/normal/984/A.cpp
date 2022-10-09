#include <iostream>
#include <algorithm>

using namespace std;
int const nmax =  1000;
int v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i];
  sort(v + 1 , v + n + 1);

  int st = 1;
  int dr = n;
  bool ok = 1;
  while(st < dr){
    if(ok == 1){
      dr--;
    } else
      st++;
    ok = !ok;
  }
  cout << v[st];
  return 0;
}