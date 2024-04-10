#include <bits/stdc++.h>

using namespace std;

int main(){
  long long x, s;
  cin >> x >> s;
  if(x == 0 && s == 0){
    cout << 0 << "\n";
    return 0;
  }
  if(x > s || (s-x)%2){
    cout << -1 << "\n";
    return 0;
  }
  else if(x == s){
    cout << 1 << "\n" << x << "\n";
    return 0;
  }
  long long d = (s-x)/2;
  if((d&x) == 0){
    cout << 2 << "\n" << (d|x) << " " << d << "\n";
  }
  else{
    cout << 3 << "\n" << x << " " << d << " " << d << "\n";
  }
}