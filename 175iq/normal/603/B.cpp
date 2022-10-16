#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
int P, K;
 
int modpow(int a, int p){
  if(p == 0) return 1;
  return (long long) a * modpow(a, p - 1) % MOD;
}
 
int main(){
  cin >> P >> K;
  if(K == 0){
    cout << modpow(P, P - 1) << '\n';
  } else if(K == 1){
    cout << modpow(P, P) << '\n';
  } else {
    int ord = 1, cur = K;
    for( ; cur != 1; ord += 1){
      cur = (long long) cur * K % P;
    }
    cout << modpow(P, (P - 1) / ord) << '\n';
  }
}