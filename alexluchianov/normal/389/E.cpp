#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int main()
{
  int n;
  cin >> n;
  ll sum1 = 0, sum2 = 0;
  vector<int> v;

  for(int i = 1 ; i <= n ; i++){
    int m;
    cin >> m;
    for(int i = 1 ; i <= m / 2; i++){
      int a;
      cin >> a;
      sum1 += a;
    }

    if(m % 2 == 1){
      int a;
      cin >> a;
      v.push_back(a);
    }
    for(int i = 1 ; i <= m / 2; i++){
      int a;
      cin >> a;
      sum2 += a;
    }
  }

  sort(v.begin() , v.end());

  for(int i = v.size() - 1 ; 0 <= i ; i--){
    if((v.size() - 1 - i) % 2 == 0)
      sum1 += v[i];
    else
      sum2 += v[i];
  }
  cout << sum1 << " " << sum2;

  return 0;
}