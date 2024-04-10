#include <iostream>

using namespace std;

int const nmax = 1000;
char v[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++){
    cin >> v[i];
    v[i] -= '0';
  }
  for(int i = 2 ; i <= n ;i++){
    if(v[i - 1] == 1 && v[i] == 1){
      cout << "No";
      return 0;
    }
  }
  for(int i = 1 ; i <= n ;i++)
    if(v[i - 1] == 0 && v[i] == 0 && v[i + 1] == 0){
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}