#include<bits/stdc++.h>
using namespace std;
int main(){
  int m=0,c=0,n;
  cin >> n;
  int i,j,k;
  for(i=0;i<n;i++){
    cin >> j >> k;
    if(j<k) c++;
    if(j>k) m++;
  }
  if(m>c)  cout << "Mishka" << endl;
  if(m<c)  cout << "Chris" << endl;
  if(m==c) cout << "Friendship is magic!^^" << endl;
  return 0;
}