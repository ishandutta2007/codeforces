#include <iostream>
#include <cstring>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n , m;
  cin >> n >> m;
  int sum = 0;
  for(int i = 1 ; i <= n ;i++){
    int a;
    cin >> a;
    sum += a;
    cout << sum / m << " ";
    sum %= m;
  }
  return 0;
}