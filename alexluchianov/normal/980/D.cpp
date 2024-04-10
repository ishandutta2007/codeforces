#include <iostream>
#include <unordered_set>

using namespace std;

#define ll long long
int const nmax = 5000;

int v[5 + nmax];

int transformnumber(int n){
  if(n == 0)
    return 0;

  int result = 1;
  if(n < 0) {
    result *= -1;
    n *= -1;
  }
  int exp = 0;
  while(n % 2 == 0){
    n /= 2;
    exp++;
  }
  if(exp % 2 == 1)
    result *= 2;

  for(int i = 3 ; i * i <= n ;i += 2){
    if(n % i == 0){
      int exp = 0;
      while(n % i == 0){
        n /= i;
        exp++;
      }
      if(exp % 2 == 1)
        result *= i;
    }
  }
  if(1 < n)
    result *= n;
  return result;
}
int st[5 + nmax];
ll sol[5 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n ;i++){
    int a;
    cin >> a;
    v[i] = transformnumber(a);
    for(int j = i - 1 ; 1 <= j ; j--){
      if(v[j] == v[i]){
        st[i] = j;
        break;
      }
    }
  }
  int groups = 0;
  for(int i = 1 ; i <= n ;i++){
    groups = 1;
    sol[1]++;
    if(v[i] == 0)
      groups = -1;

    for(int j = i + 1 ; j <= n ;j++){
      if(st[j] < i && v[j] != 0){
        if(groups == -1)
          groups = 1;
        else
          groups++;
      }

      if(groups == -1)
        sol[1]++;
      else
        sol[groups]++;
    }
  }
  for(int i = 1 ;i <= n ;i++)
    cout << sol[i] << " ";
  return 0;
}