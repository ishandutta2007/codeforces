#include <iostream>

using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  if(a + 1 == b)
    cout << a << " " << b;
  else if(a == b)
    cout << a << "1" << " " << a << "2" << '\n';
  else if(a == 9 && b == 1)
    cout << a << " " << 10 << '\n';
  else
    cout << -1 << '\n';

  return 0;
}