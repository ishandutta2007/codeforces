#include <iostream>

using namespace std;

int main()
{
  long long l , r;
  cin >> l >> r;
  cout << "YES\n";
  long long pairs = (r - l + 1) / 2;
  for(int i = 1 ; i <= pairs ; i++){
    cout << l << " " << l + 1 << '\n';
    l += 2;
  }
  return 0;
}