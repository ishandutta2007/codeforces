#include <iostream>
#include <fstream>

using namespace std;
int const nmax = 100;
int v[5 + nmax];
int n;
bool valid(int x){
  return 1 <= x && x<= n;
}
int main()
{
  int m, k;
  cin>>n>>m>>k;
  int m1 = m - 1, m2 = m + 1;
  for(int i = 1 ; i <= n ;i++){
    cin>>v[i];
  }
  while(true){
    if(valid(m1)){
      if(v[m1] <= k && v[m1] != 0){
        cout<<(m - m1) * 10;
        return 0;
      }
    }
    if(valid(m2)){
      if(v[m2] <= k && v[m2] != 0){
        cout<<(m2 - m) * 10;
        return 0;
      }
    }
    m1--;
    m2++;
  }
  return 0;
}