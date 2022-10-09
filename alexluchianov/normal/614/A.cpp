#include <iostream>

using namespace std;

using ll = long long;

int main()
{
  ll a, b, k, start;
  cin >> a >> b >> k;
  start = 1;
  bool printed = 0;
  while(true){
    if(a <= start && start <= b) {
      cout << start << " ";
      printed = 1;
    }
    if(k <= b / start)
      start = start * k;
    else
      break;
  }
  if(printed == 0)
    cout << -1;
  return 0;
}