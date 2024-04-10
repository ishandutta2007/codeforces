#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
char v[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  ll result = 0;
  int a = 0, b = 0;
  for(int i = 1;i <= n; i++){
    if(v[i] == 'A'){
      if(v[i - 1] == 'A')
        result += i - 1 - (0 < b);
      else
        result += a;
    } else if(v[i] == 'B') {
      if(v[i - 1] == 'B')
        result += i - 1 - (0 < a);
      else
        result += b;
    }

    if(v[i] == 'A')
      a = i;
    else
      b = i;
  }
  cout << result;
  return 0;
}