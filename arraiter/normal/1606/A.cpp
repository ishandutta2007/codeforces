#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

#define nc getchar

int main(){
  int T;cin>>T;while(T--){
    char str[105];
    scanf("%s",str+1);
    int n=strlen(str+1);
    int ct=0;
    rep(i,1,n){
      int j=i;
      while(j<n&&str[j+1]==str[i])j++;
      ct++;
      i=j;
    }
    str[n+1]=0;
    if(ct%2==1){
      printf("%s\n",str+1);
    }else{
      str[n]=str[n]=='a'?'b':'a';
      printf("%s\n",str+1);
    }
  }
  return 0;
}