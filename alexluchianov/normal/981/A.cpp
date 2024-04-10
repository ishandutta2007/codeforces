#include <iostream>
#include <cstring>

using namespace std;

int const nmax = 50;

char v[5 + nmax];
bool checkpal(int from , int to){
  if(from <= to){
    return (v[from] == v[to]) & checkpal(from + 1 , to - 1);
  } else
    return 1;
}

int main()
{
  cin >> (v + 1);
  int n = strlen(v + 1);
  for(int h = n; 0 <= h ;h--){
    for(int i = 1 ; i <= n - h + 1 ; i++){
      int j = i + h - 1;
      if(checkpal(i , j) == 0){
        cout << h << '\n';
        return 0;
      }
    }
  }
  cout << 0;
  return 0;
}