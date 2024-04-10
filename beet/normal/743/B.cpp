#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k,j=0;
  cin>>n>>k;
  while(!(k&1LL)) k>>=1LL,j++;
  cout << j+1 << endl;
  return 0;
}