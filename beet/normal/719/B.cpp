#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k,l;
  string s,b;
  cin >> n >> b;
  int ans=n;
  for(j=0;j<2;j++){
    k=0;s=b;
    queue<int> q;
    for(i=0;i<n;i++){
      if((i+j)%2){
	if(s[i]=='b') continue;
	q.push(i);
      }
    }
    for(i=0;i<n;i++){
      if((i+j)%2==0){
	if(s[i]=='r') continue;
	if(!q.empty()){
	  k++;
	  l=q.front();q.pop();
	  swap(s[i],s[l]);
	}else break;
      }
    }
    
    for(i=0;i<n;i++){
      if((i+j)%2){
	if(s[i]=='b') continue;
	k++;
      }else{
	if(s[i]=='r') continue;
	k++;
      }
    }
    //cout << k << endl;
    ans=min(ans,k);
  }
  cout << ans << endl;
  return 0;
}