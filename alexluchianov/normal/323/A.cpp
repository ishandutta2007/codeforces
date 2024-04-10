#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  if(n == 1)
    cout << -1;
  else if (n % 2 == 0){
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        if(j % 2 == 1){
          for(int h = 1 ; h <= n ; h++){
            if(((h - 1) / 2 + (i - 1) / 2 ) % 2 == 0){
              cout << "w";
            } else
              cout << "b";
          }
        } else {
          for(int h = 1 ; h <= n ; h++){
            if(((h - 1) / 2 + (i - 1) / 2 ) % 2 == 0){
              cout << "b";
            } else
              cout << "w";
          }
        }
        cout << '\n';
      }
      cout << '\n';
    }
  }else
    cout << -1;
  return 0;
}