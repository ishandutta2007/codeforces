#include <iostream>
#include <fstream>

using namespace std;

int const nmax = 1000000;
void fillp(int start , int endp , int l){
  int lp = 1;
  while(start <= endp){
    if(lp < l){
      cout<<start + 1<<" ";
      lp++;
    } else{
      cout<<start - l + 1<<" ";
      lp = 1;
    }
    start++;
  }
}
int main()
{
  int n , a , b;
  cin>>n>>a>>b;
  for(int i = 0 ; i * a <= n ;i++){
    if((n - i * a) % b == 0){
      fillp(1 , i * a , a);
      fillp(i * a + 1, n , b);
      return 0;
    }
  }
  cout<<-1;
  return 0;
}