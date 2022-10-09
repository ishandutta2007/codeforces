#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int sum = 0, a;
  int check = 0;
  for(int i = 1;i <= n; i++) {
    cin >> a;
    if(a % 2 == 0)
      cout << a / 2 << '\n';
    else {
      check ^= 1;
      if(check == 1)
        cout << (a + 1) / 2  << '\n';
      else
        cout << (a - 1) / 2 << '\n';
    }
  }
  return 0;
}