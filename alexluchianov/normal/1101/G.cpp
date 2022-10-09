#include <iostream>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];
int rep[31];

int leastsignificant(int number){
  for(int i = 0; i < 30; i++)
    if(0 < (number & (1 << i)))
      return i;
  return -1;
}

int gauss(int number){
  for(int i = 0; i < 30; i++)
    if(0 < (number & (1 << i))){
      number ^= rep[i];
    }
  if(number == 0)
    return 0;
  else {
    rep[leastsignificant(number)] = number;
    return 1;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    cin >> v[i];
    v[i] ^= v[i - 1];
  }
  if(v[n] == 0)
    cout << -1;
  else {
    gauss(v[n]);
    int result = 1;
    for(int i = 1;i < n; i++)
      result += gauss(v[i]);
    cout << result;
  }
  return 0;
}