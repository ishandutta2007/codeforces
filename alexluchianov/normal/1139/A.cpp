#include <iostream>

using namespace std;
#define ll long long

int main()
{
  int n;
  cin >> n;
  char c;
  ll result = 0;

  for(int i = 1;i <= n;i++){
    cin >> c;
    if((c - '0') % 2 == 0)
      result += i;
  }
  cout << result;

  return 0;
}