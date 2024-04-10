#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;
  string home;
  cin>>n>>home;
  string s[n];
  for(int i=0;i<n;i++) cin>>s[i];
  cout<<(n%2?"contest":"home")<<endl;
  return 0;
}