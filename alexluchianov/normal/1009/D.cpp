#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n , m;
  cin >> n >> m;
  int n2 = n;
  if(m < n - 1) {
    cout << "Impossible";
    return 0;
  }

  int result = 0;
  n = min(n , 1000);
  for(int i = 1 ; i <= n ;i++){
    for(int j = i + 1 ; j <= n ;j++){
      if(__gcd(i , j) == 1){
        result++;
      }
    }
  }
  if(m <= result) {
    cout << "Possible\n";
    int result = 0;

    for(int i = 2 ; i <= n2 ;i++){
      cout << 1 << " " << i << '\n';
      result++;
    }
    for(int i = 2 ; i <= n ;i++){
      for(int j = i + 1 ; j <= n ;j++){
        if(result < m && __gcd(i , j) == 1){
          cout << i << " " << j << '\n';
          result++;
        }
      }
    }
  } else
    cout << "Impossible";

  return 0;
}