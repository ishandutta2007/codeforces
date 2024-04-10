#include <iostream>

using namespace std;
int const nmax = 1000;
char v[5 + nmax][5 + nmax];

int main()
{
  int n , a , b;
  cin >> n >> a >> b;
  if((n == 3 || n == 2)  && a == 1 && b == 1){
    cout << "NO";
    return 0;
  }
  if(1 < a && 1 < b)
    cout << "NO";
  else{
    cout << "YES\n";
    if(1 < a)
      for(int i = 1; i <= n - a; i++)
        v[i][i + 1] = v[i + 1][i] = 1;
    else
      for(int i = 1 ; i <= n - b ; i++)
        v[i][i + 1] = v[i + 1][i] = 1;

    if(a == 1){
      for(int i = 1 ; i <= n ;i++)
        for(int j = 1 ; j <= n ; j++)
          if(i != j)
            v[i][j] = !v[i][j];
    }

    for(int i = 1 ; i <= n ;i++){
      for(int j = 1 ; j <= n ; j++)
        cout << (int)v[i][j];
      cout << '\n';
    }
  }
  return 0;
}