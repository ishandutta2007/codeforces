#include<bits/stdc++.h>

using namespace std;

typedef long long int uli;
const int mxn=1e5+10;
const int mxk=12;
int a[mxk][mxn];
bitset<(1<<mxk)>b[mxn];
int pos[mxn][mxk];

int main(){
  int n,k,q;
  cin>>n>>k>>q;
  for(int i=0;i<k;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  for(int j=0;j<n;j++){
    vector<pair<int,int> >col;
    for(int i=0;i<k;i++)
      col.push_back({a[i][j],i});    
    sort(col.begin(),col.end());
    for(int i=0;i<k;i++)
      pos[j][i]=col[i].second;
  }
  for(int m=0;m<(1<<k);m++)
    for(int i=0;i<k;i++)
      if(m&(1<<i))
        b[i][m]=1;
  int it=k;
  while(q--){
    int op,x,y;
    cin>>op>>x>>y;
    --x,--y;
    if(op==1)b[it++]=(b[x]|b[y]);
    else if(op==2)b[it++]=(b[x]&b[y]);
    else{
      int m=(1<<k)-1;
      for(int i=0;i<k;i++){
        m^=(1<<pos[y][i]);
        if(b[x][m]==0){
          cout<<a[pos[y][i]][y]<<'\n';
          break;
        }
      }
    }
  }
}