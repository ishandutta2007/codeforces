#include <iostream>
#include <cstring>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
ll const inf = 1LL * nmax * nmax * nmax;

ll v[3][5 + nmax];
ll sum[3][5 + nmax];
ll sum2[2][5 + nmax];
ll sum3[2][5 + nmax];

int main()
{
  int n ;
  cin >> n;
  for(int i = 1 ; i <= 2 ; i++)
    for(int j = 1 ; j <= n ;j++)
      cin >> v[i][j];

  for(int i = 1 ; i <= 2 ; i++){
    for(int j = n ; 1 <= j ; j--){
      sum[i][j] += sum[i][j + 1] + v[i][j];
    }
  }
  for(int j = 1 ; j <= 2 ; j++){
    for(int i = n ; 1 <= i ;i--){
      sum2[j][i] = sum2[j][i + 1] + sum[j][i];
    }
    for(int i = n ; 1 <= i ; i--){
      sum3[j][i] = sum3[j][i + 1] + v[j][i] * (n - i + 1);
    }
  }


  ll result = 0 , acc = -2;
  ll smax = 0;

  for(int i = 0 ; i <= n;i++){
    if(i % 2 == 0){
      result += v[2][i] * acc;
      acc++;
      result += v[1][i] * acc;
      acc++;
      ll result2 = result + sum2[1][i + 1] + sum[1][i + 1] * (acc - 1) + sum3[2][i + 1] + sum[2][i + 1] * (acc - 1 + n - i);
      smax = MAX(smax , result2);

    } else{
      result += v[1][i] * acc;
      acc++;
      result += v[2][i] * acc;
      acc++;
      ll result2 = result + sum2[2][i + 1] + sum[2][i + 1] * (acc - 1) + sum3[1][i + 1] + sum[1][i + 1] * (acc - 1 + n - i);

      smax = MAX(smax , result2);
      //cout << ":" << result << ": ";
    }
  }
  cout << smax;
  return 0;
}
/*
3
1 6 5
2 3 4
*/