#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  if(n==1) cout << -1 << endl;
  else cout << n << " " << n+1 << " " << n*(n+1) << endl;
  return 0;
}