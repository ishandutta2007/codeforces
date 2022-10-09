#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
  int n;
  cin >> n;
  vector<int> v(5 + n);

  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  v[n + 1] = 1000000001;

  int st = 0;
  int dr = n + 1;
  while(st < n && v[st] < v[st + 1])
    st++;
  while(1 < dr && v[dr - 1] < v[dr])
    dr--;

  int initst = st, initdr = dr;

  if(dr < st)
    initst = initdr = 1;

  if(st < dr){
    while(st < dr){
      swap(v[st] , v[dr]);
      st++;
      dr--;
    }
  }

  for(int i = 1 ; i <= n ; i++) {
    if(v[i] < v[i - 1]) {
      cout << "no";
      return 0;
    }
  }
  cout << "yes\n";
  cout << initst << " " << initdr;

  return 0;
}