#include <iostream>

using namespace std;

int p , n;

bool valid(int k){
  for(int i = 2 ; i  * i <= k ;i++){
    if(k % i == 0){
      if(i <= p)
        return 0;
      k /= i;
    }
  }
  if(1 < k){
    if(k <= p)
      return 0;
    else
      return 1;
  }
  return 1;
}
int main()
{
  cin>>p>>n;
  for(int i = n ; p < i ;i--){
    if(valid(i) == 1){
      cout<<i;
      return 0;
    }
  }
  cout<<-1;
  return 0;
}