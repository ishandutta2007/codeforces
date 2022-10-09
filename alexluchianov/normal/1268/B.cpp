#include <iostream>

using namespace std;
using ll = long long;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  ll white = 0, black = 0;

  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    if(i % 2 == 1){
      white += a / 2;
      black += a - a / 2;
    } else {
      white += a - a / 2;
      black += a / 2;
    }
  }
  cout << min(white, black);
  return 0;
}