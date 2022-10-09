#include <iostream>

using namespace std;

void solve(int start , int n){
  if(n == 1)
    cout << start * n;
  else if(n == 3){
    cout << start << " " << start << " " << start * 3 ;
  } else {
    for(int i = 1 ; i <= n ; i += 2){
      cout << start << " ";
    }
    solve(start * 2 , n / 2);
  }
}
int main()
{
  int n;
  cin >> n;

  solve(1 , n);

  return 0;
}