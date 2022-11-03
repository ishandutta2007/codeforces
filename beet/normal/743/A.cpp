#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,a,b;
  string s;
  cin>>n>>a>>b>>s;
  cout << (s[a-1]!=s[b-1]) << endl;
  return 0;
}