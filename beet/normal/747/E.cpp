#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<vector<string> > vs;
vector<string> v;
ll x=0;
void rec(ll d){
  string tmp;
  while(s[x]!=',') tmp+=s[x],x++;
  if(d==(ll)vs.size()){
    v.clear();
    vs.push_back(v);
  }
  vs[d].push_back(tmp);
  ll k=0;
  x++;
  while(x<(ll)s.size()&&s[x]!=',') k=k*10+s[x]-'0',x++;
  //cout<<d<<":"<<tmp<<","<<k<<endl;
  if(x<(ll)s.size()&&s[x]==',') x++;
  for(ll j=0;j<k;j++) rec(d+1);
}
ll solve(){
  while(x<(ll)s.size()){
    rec(0);
  }
  return (ll)vs.size();
}
int main(){
  cin>>s;
  cout<<solve()<<endl;
  for(ll i=0;i<(ll)vs.size();i++){
    for(ll j=0;j<(ll)vs[i].size();j++){
      cout<<vs[i][j]<<" \n"[j==(ll)vs[i].size()-1];
    }
  }
  return 0;
}