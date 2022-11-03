#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,x,y;
  cin>>n;
  ll i,j,k,s;
  ll m[n][n];
  memset(m,0,sizeof(m));
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin >> m[i][j];
      if(m[i][j]==0) {
	x=i;y=j;
      }
    }
  }
  if(n==1){
    cout << 1 << endl;
    return 0;
  }
  s=0;k=0;
  if(x!=0) for(j=0;j<n;j++) s+=m[0][j];
  else for(j=0;j<n;j++) s+=m[1][j];
  for(j=0;j<n;j++) k+=m[x][j];
  m[x][y]=s-k;
  if(m[x][y]<1){
    cout << -1 << endl;
    return 0;
  }
  bool f=true;
  for(i=0;i<n;i++){
    k=0;
    for(j=0;j<n;j++) k+=m[i][j];
    if(k!=s) f=false;
  }
  for(j=0;j<n;j++){
    k=0;
    for(i=0;i<n;i++) k+=m[i][j];
    if(k!=s) f=false;
  }
  k=0;
  for(i=0;i<n;i++) k+=m[i][i];
  if(k!=s) f=false;
  k=0;
  for(i=0;i<n;i++) k+=m[i][n-1-i];
  if(k!=s) f=false;
  cout << (f?m[x][y]:-1) << endl;
  return 0;
}