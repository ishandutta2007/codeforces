#include <iostream>

using namespace std;

int const nmax = 100;
int v[5 + nmax * 2];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n * 2;i++)
    cin >> v[i];
  int sum = 0;
  for(int i = 1 ; i <= n * 2 ; i++){
    for(int j = i + 1 ; j <= n * 2 ; j++){
      if(v[i] == v[j]){
        for(int h = j - 1 ; i + 1 <= h ; h--) {
          swap(v[h] , v[h + 1]);
          sum++;
        }
        break;
      }
    }
  }
  cout << sum;
  return 0;
}