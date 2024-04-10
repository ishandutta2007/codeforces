#include <iostream>


using namespace std;

int const nmax = 1000;
int v[5 + nmax];

int main()
{
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ;i++){
    int a;
    cin>>a;
    v[a]++;
  }
  int result = 0;
  for(int i = 1 ; i <= nmax ;i++){
    if(0 < v[i])
      result++;
  }
  cout<<result;
  return 0;
}