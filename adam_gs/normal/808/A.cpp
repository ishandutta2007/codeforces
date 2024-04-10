#include<bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, akt=1;
  cin >> n;
  int p=n;
  bool ok=true;
  while(p>=10) {
    if(p%10) ok=false;
    p/=10;
    akt*=10;
  }
  int ans=akt*(p+1);
  cout << ans-n << '\n';
}