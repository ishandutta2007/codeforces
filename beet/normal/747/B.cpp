#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  string s;
  cin>>n>>s;
  ll g[5]={};
  map<char,ll> m;
  m['A']=0;m['C']=1;m['G']=2;m['T']=3;m['?']=4;
  char c[]={'A','C','G','T'};
  for(ll i=0;i<n;i++){
    g[m[s[i]]]++;
  }
  bool f=n%4;
  for(ll i=0;i<4;i++) f|=g[i]*4>n;

  for(ll j=0;j<4;j++){
    for(ll i=0;i<n;i++){
      if(g[j]*4==n) break;
      if(s[i]=='?'){
	s[i]=c[j];
	g[j]++;
      }
    }
  }
  
  if(f) cout<<"==="<<endl;
  else cout<<s<<endl;
  return 0;
}