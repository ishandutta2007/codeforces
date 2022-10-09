#include <iostream>

using namespace std;

#define ll long long
int const nmax = 1000000;

int v[5 + nmax];
int aib[5 + nmax];
int n;

void updateaib(int x , int val){
  while(x <= n){
    aib[x] += val;
    x += x ^ (x & (x - 1));
  }
}

int queryaib(int x){
  int result = 0;
  while(0 < x){
    result += aib[x];
    x = x & (x - 1);
  }
  return result;
}

int main()
{
  cin >> n;
  for(int i = 1 ; i <= n ;i++)
    cin >> v[i];
  ll result = 0;
  for(int i = 1 ; i <= n ;i++){
    result += i - 1 - queryaib(v[i] - 1);
    updateaib(v[i] , 1);
  }
  if(n % 2 == result % 2)
    cout << "Petr\n";
  else
    cout << "Um_nik\n";
  return 0;
}