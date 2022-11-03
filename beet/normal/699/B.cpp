#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  int i,j,k;
  cin >> n >> m;
  string st[n];
  string co[n];
  int cox=1,coy=1;
  string ro[n];
  int rox=1,roy=1;
  bool b=true;
  for(i=0;i<n;i++) {
    cin >> st[i];
    co[i]=st[i];
    ro[i]=st[i];
  }
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(st[i][j]=='*'){
	if(b){
	  cox=j+1;b=false;
	  for(k=0;k<n;k++){
	    co[k][j]='.';
	  }
	  roy=i+1;
	  for(k=0;k<m;k++){
	    ro[i][k]='.';
	  }
	}
      }
    }
  }
  bool bc=true,br=true;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(co[i][j]=='*'){
	if(bc){
	  coy=i+1;bc=false;
	  for(k=0;k<m;k++){
	    co[i][k]='.';
	  }
	}
      }
      if(ro[i][j]=='*'){
	if(br){
	  rox=j+1;br=false;
	  for(k=0;k<n;k++){
	    ro[k][j]='.';
	  }
	}
      }
    }
  }
  bool f=true;
  
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(co[i][j]=='*') f=false;
    }
  }
  if(f){
    cout << "YES" << endl << coy<< " " << cox << endl;
    return 0;
  }

  f=true;
  
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      if(ro[i][j]=='*') f=false;
    }
  }
  
  if(f){
    cout << "YES" << endl << roy << " " << rox << endl;
    return 0;
  }
  
  cout << "NO" << endl;
  return 0;
}