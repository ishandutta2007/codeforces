#include <iostream>

using namespace std;

#define ll long long

int const nmax = 300000;
int v[5 + nmax];
int v2[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n ,m;
  ll sum = 0;
  cin >> n;
  for(int i = 1 ; i <= n ; i++) {
    cin >> v[i];
    sum += v[i];
  }

  cin >> m;
  for(int i = 1 ; i <= m ; i++) {
    cin >> v2[i];
    sum -= v2[i];
  }
  if(0 != sum)
    cout << -1;
  else{
    int result = 0;
    sum = 0;
    int dr1 = 1, dr2 = 1;
    while(dr1 <= n || dr2 <= m){
      if(0 <= sum){
        sum -= v[dr1++];
      } else
        sum += v2[dr2++];


      if(sum == 0)
        result++;
    }
    cout << result;
  }
  return 0;
}