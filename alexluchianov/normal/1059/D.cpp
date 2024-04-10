#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ld const inf = 10000000000;

ld const eps = 0.00000000001;

ll v[5 + nmax][2];

int n;

bool test(ld dist){
  ld x = -inf , x2 = inf;


  //cout << setprecision(20) << fixed << dist << " " << dist * dist << '\n';


  for(int i = 1; i <= n ; i++){

    ld odl = abs((v[i][1] - dist));
    ld bok = sqrt(dist - odl ) * sqrt(dist + odl);

    x = max(x , v[i][0] - bok );
    x2 = min(x2 , v[i][0] + bok);

  }
  return x <= x2;
}


ld binarysearch(){
  ld x = eps;

  for(int i = 1 ; i <= n ; i++)
    x = max(x , ( (ld)v[i][1] / 2) ) ;

  for(ld i = (1LL << 55) ; eps < i ; i /= 2){
    if(test(x + i) == 0)
      x += i;
  }
  return x + eps;

}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i][0] >> v[i][1];

    if(v[i - 1][1] < 0 && 0 < v[i][1]) {
      cout << -1;
      return 0;
    } else if(v[i][1] < 0 && 0 < v[i - 1][1]){
      cout << -1;
      return 0;
    }
  }


  for(int i = 1 ; i <= n ;i++)
    v[i][1] = fabs(v[i][1]);

  ///From here on ,we always have a solution
  cout << setprecision(8) << fixed << binarysearch();
  return 0;
}