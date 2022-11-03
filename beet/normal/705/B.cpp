#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  int i,j,k=0;
  for(i=0;i<n;i++){
    cin >> j;
    k=(k+((j-1)%2))%2;
    if(k) cout << 1;
    else cout << 2;
    cout << endl;
  }
  return 0;
}