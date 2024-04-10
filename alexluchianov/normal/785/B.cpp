#include <iostream>

using namespace std;

int main()
{
  int n ,m;
  cin>>n;
  int a ,b;
  int maxa = 0,minb = 1000000000;
  int maxa2 = 0,minb2 = 1000000000;
  for(int i = 0 ;i < n ;i++){
    cin>>a>>b;
    maxa = max(maxa, a);
    minb = min(minb, b);
  }
  cin>>m;
  for(int i = 0 ;i < m ;i++){
    cin>>a>>b;
    maxa2 = max(maxa2, a);
    minb2 = min(minb2, b);
  }
  cout<<max(0 , max(maxa2 -  minb ,maxa - minb2));

  return 0;
}