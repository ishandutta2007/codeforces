#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


//INSERT ABOVE HERE

const Int MAX = 55;
Int cl[MAX][MAX]={};
Int dl[MAX][MAX]={};

// (a,b) to (c,d)
Int ask(Int a,Int b,Int c,Int d){
  assert(a<=c);
  assert(b<=d);
  assert(a+b+2<=c+d);
  cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
  Int x;
  cin>>x;
  return x;
}

void helpC(int a,int b,int c,int d){
  int na=a,nb=b,nc=c,nd=d;
  if(na>nc) swap(na,nc),swap(nb,nd);
  if(nb>nd) swap(na,nc),swap(nb,nd);
  cl[a][b]=cl[c][d]^!ask(na,nb,nc,nd);
}

void helpD(int a,int b,int c,int d){
  int na=a,nb=b,nc=c,nd=d;
  if(na>nc) swap(na,nc),swap(nb,nd);
  if(nb>nd) swap(na,nc),swap(nb,nd);
  dl[a][b]=dl[c][d]^!ask(na,nb,nc,nd);
}

signed main(){
  Int n;
  cin>>n;

  for(Int i=0;i<n;i++)
    for(Int j=0;j<n;j++)
      cl[i][j]=dl[i][j]=2;

  cl[0][0]=1;
  cl[n-1][n-1]=0;
  for(Int i=0;i<n;i++){
    for(Int j=0;j<n;j++){
      if((i+j)&1) continue;
      if(cl[i][j]!=2) continue;

      if(j==0){
        helpC(i,j,i-2,j);
      }else if(i==0){
        helpC(i,j,i,j-2);
      }else{
        helpC(i,j,i-1,j-1);
      }
    }
  }

  // base := dl[2][0]
  dl[2][1]=0;
  dl[0][1]=!ask(0,1,2,1);
  dl[1][0]=!ask(1,0,2,1);
  for(Int i=0;i<n;i++){
    for(Int j=0;j<n;j++){
      if(~(i+j)&1) continue;
      if(dl[i][j]!=2) continue;
      if(j==0){
        helpD(i,j,i-2,j);
      }else if(i==0){
        helpD(i,j,i,j-2);
      }else{
        helpD(i,j,i-1,j-1);
      }
    }
  }

  Int flip=0;
  for(Int i=1;i<n;i++){
    for(Int j=0;j+1<n;j++){
      if((i+j)&1) continue;
      if(cl[i][j]==cl[i-1][j+1]) continue;
      if(j>0){
        helpC(i,j+1,i-1,j-1);
        flip=cl[i][j+1]!=dl[i][j+1];
      }else{
        assert(j+2<n);
        helpC(i-1,j,i,j+2);
        flip=cl[i-1][j]!=dl[i-1][j];
      }
      goto END;
    }
  }

  for(Int i=1;i<n;i++){
    for(Int j=0;j+1<n;j++){
      if(~(i+j)&1) continue;
      if(dl[i][j]==dl[i-1][j+1]) continue;
      if(j>0){
        helpD(i,j+1,i-1,j-1);
        flip=cl[i][j+1]!=dl[i][j+1];
      }else{
        assert(j+2<n);
        helpD(i-1,j,i,j+2);
        flip=cl[i-1][j]!=dl[i-1][j];
      }
      goto END;
    }
  }

  for(Int k=0;k+2<n;k++){
    if((cl[k+0][k+0]==cl[k+1][k+1])&&
       (cl[k+1][k+1]!=cl[k+2][k+2])){

      if(dl[k+1][k+0]==dl[k+2][k+1]){
        helpC(k+2,k+1,k+0,k+0);
        flip=cl[k+2][k+1]!=dl[k+2][k+1];
      }else{
        helpC(k+0,k+1,k+2,k+2);
        flip=cl[k+0][k+1]!=dl[k+0][k+1];
      }
      goto END;
    }

    if((cl[k+0][k+0]!=cl[k+1][k+1])&&
       (cl[k+1][k+1]==cl[k+2][k+2])){

      if(dl[k+0][k+1]==dl[k+1][k+2]){
        helpC(k+0,k+1,k+2,k+2);
        flip=cl[k+0][k+1]!=dl[k+0][k+1];
      }else{
        helpC(k+2,k+1,k+0,k+0);
        flip=cl[k+2][k+1]!=dl[k+2][k+1];
      }
      goto END;
    }
  }
  assert(0);

 END:
  cout<<"!"<<endl;
  for(Int i=0;i<n;i++){
    for(Int j=0;j<n;j++)
      if(~(i+j)&1) cout<<cl[i][j];
      else cout<<(flip^dl[i][j]);
    cout<<endl;
  }
  return 0;
}