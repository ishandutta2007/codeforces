#include <iostream>

using namespace std;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 140582;
int v[5 + nmax];
long long v2[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ;i <= n ;i++)
    cin >> v[i];
  int smax = 0;
  for(int i = 1 ; i <= n ; i++)
    smax = MAX(smax , v[i]);
  if(smax == 0){
    cout << "YES\n";
    for(int i = 1;  i <= n ; i++)
      cout << 1 << " ";
    return 0;
  } else{
    int sum = 0;
    for(int i = 1 ; i <= n ; i++)
      sum += (0 < v[i]);
    if(sum == 1){
      cout << "YES\n";
      for(int i = 1 ; i <= n ; i++){
        if(v[i] == 0)
          cout << smax + smax << " " ;
        else
          cout << smax << " " ;
      }
      return 0;
    } else {
      for(int i = 1 ; i <= n ; i++){
        if(v[i] == smax && v[(i - 2 + n) % n + 1] != smax){
          cout << "YES\n";
          v2[i] = v[i];

          for(int j = i - 1 ; 1 <= j ; j--){
            if(v[(j - 2 + n) % n + 1] == v2[j + 1] && v[j] == 0)
              v2[j] = v2[j + 1] * 2 + v[j];
            else
              v2[j] = v2[j + 1] + v[j];
          }

          for(int j = n ; i < j ; j--){
            if(v[(j - 2 + n) % n + 1] == v2[j % n + 1] && v[j] == 0)
              v2[j] = v2[j % n + 1] * 2 + v[j];
            else
              v2[j] = v2[j % n + 1] + v[j];
          }

          for(int i = 1 ; i <= n ; i++)
            cout << v2[i] << " " ;
          return 0;
        }
      }
      cout << "NO";
    }
  }
  return 0;
}