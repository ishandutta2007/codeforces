#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;

int main(){
 int n;
 cin >> n;
 map<int,pii> kr;
 for(int i = 2; i <= 2*n; ++i){
  for(int j = 1; j < i; ++j){
   int s;
   cin >> s;
   kr[s] = pii(i,j);
  }
 }
 int ans[1000] = {};
 while(!kr.empty()){
  auto par = kr.end();
  --par;
  if(ans[par->second.first] == 0 && ans[par->second.second] == 0){
   ans[par->second.first] = par->second.second;
   ans[par->second.second] = par->second.first;
  }
  kr.erase(par,kr.end());
 }
 for(int i = 1; i <= 2*n; ++i)
  cout << ans[i] << ' ';
 cout << endl;
}