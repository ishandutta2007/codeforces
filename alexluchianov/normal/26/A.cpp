#include <iostream>

using namespace std;
int v[4000];

int main()
{
  int n;
  cin >> n;
  int result = 0;
  for(int i = 2 ; i <= n ;i++){
    if(v[i] == 0)
      for(int j = i ; j <= n ; j += i)
        v[j] ++;
    else if(v[i] == 2)
      result++;
  }
  cout << result;

  return 0;
}