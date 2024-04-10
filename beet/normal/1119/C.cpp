#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
const int MAX = 555;
int a[MAX][MAX];
int b[MAX][MAX];
int c[MAX][MAX];
signed main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>b[i][j];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      c[i][j]=a[i][j]^b[i][j];

  auto print=[&](){
               for(int i=0;i<n;i++){
                 for(int j=0;j<m;j++)
                   cout<<c[i][j]<<" ";
                 cout<<endl;
               }
             };
  if(0) print();
  
  auto NG=[](){cout<<"No"<<endl;exit(0);};
  for(int i=0;i+1<n;i++){
    for(int j=0;j<m;j++){
      if(c[i][j]==0) continue;
      int k=j+1;
      while(k<m&&c[i][k]==0) k++;
      if(k==m) NG();
      c[i][j]^=1;
      c[i][k]^=1;
      c[i+1][j]^=1;
      c[i+1][k]^=1;                        
    }    
  }  
  //print();
  for(int j=0;j<m;j++) if(c[n-1][j]) NG();  
  cout<<"Yes"<<endl;
  return 0;
}