#include <iostream>
#include <cstring>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

ll const nmax = 100;
ll col[5 + nmax];
ll lin[5 + nmax];
ll v[5 + nmax][5 + nmax];

int main()
{
  ll n , m;
  cin >> n >> m;
  for(int i = 1 ; i <= n ;i++)
    cin >> lin[i];
  for(int i = 1 ; i <= m ;i++){
    cin >> col[i];
  }
  for(ll pow2 = 0 ; pow2 <= 31 ; pow2++){
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
      sum ^= (0 < (lin[i] & (1 << pow2)));
    }
    for(int i = 1 ; i <= m ; i++){
      sum ^= (0 < (col[i] & (1 << pow2)));
    }
    if(0 < sum){
      cout << "NO";
      return 0;
    } else{
      for(int i = 1 ; i <= n ; i++){
        if(0 < (lin[i] & (1 << pow2))){
          for(int j = 1 ; j <= m ; j++){
            if(0 < (col[j] & (1 << pow2))){
              lin[i] ^= (1 << pow2);
              col[j] ^= (1 << pow2);
              v[i][j] ^= (1 << pow2);
              break;
            }
          }
        }
      }
      for(int j = 1 ; j <= m ; j++)
        if(0 < (col[j] & (1 << pow2))){
          lin[1] ^= (1 << pow2);
          col[j] ^= (1 << pow2);
          v[1][j] ^= (1 << pow2);
        }
      //*
      for(int i = 1 ; i <= n ;i++){
        if(0 < (lin[i] & (1 << pow2))){
          lin[i] ^= (1 << pow2);
          col[1] ^= (1 << pow2);
          v[i][1] ^= (1 << pow2);
        }
      }
      //*/
    }
  }
  cout << "YES\n";
  for(int i = 1 ; i <= n ;i++){
    for(int j = 1 ; j <= m ; j++){
      cout << v[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
/*
3
1 6 5
2 3 4
*/