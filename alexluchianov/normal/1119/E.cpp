#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n;
  cin >> n;
  ll result = 0, sum = 0;
  for(int i = 1;i <= n;i++){
    int a;
    cin >> a;
    int val = MIN(a / 2, sum);
    result += val;
    a -= val * 2;
    sum -= val;
    result += a / 3;
    sum += a % 3;
  }
  cout << result;
  return 0;
}