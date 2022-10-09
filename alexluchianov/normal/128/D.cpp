#include <iostream>
#include <map>

using namespace std;

int const nmax = 100000;
int const inf = 1000000000;

map<int,int> frec;

int main()
{
  int n, smin = inf, smax = 0;
  cin >> n;

  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    frec[a] += 2;
    smin = min(smin, a);
    smax = max(smax, a);
  }

  smin++;
  while(0 < frec[smin]){
    if(frec[smin - 1] == 0) {
      cout << "NO";
      return 0;
    }

    if(frec[smin - 1] <= frec[smin])
      frec[smin] -= frec[smin - 1];
    else {
      cout << "NO";
      return 0;
    }
    smin++;
  }
  if(0 < frec[smin - 1]){
    cout << "NO";
    return 0;
  }

  if(smin < smax)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
//8
//3 5 8 4 7 6 4 7
//3 4 4 5 6 7 7 8