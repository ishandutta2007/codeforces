#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  if(n == 2)
    cout << -1;
  else if(3 <= n){
    cout << 6 << '\n' << 10 << '\n' << 15 << '\n';
    for(int i = 1 ; i <= n - 3; i++)
      cout << 2 * 3 * 5 * i << '\n';
  }
  return 0;
}