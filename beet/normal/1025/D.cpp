#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
int n;
int dpL[707][707];
int dpR[707][707];
int ok[707][707];

int dfsL(int, int);
int dfsR(int, int);

int dfsL(int l,int r){
  int &res=dpL[l+1][r+1];
  if(~res) return res;
  if(l+1==r) return res=1;
  
  res=0;
  for(int i=l+1;i<r;i++)
    res|=ok[r][i]&&dfsL(l,i)&&dfsR(i,r);
  
  return res;
}
int dfsR(int l,int r){
  int &res=dpR[l+1][r+1];
  if(~res) return res;
  if(l+1==r) return res=1;
  
  res=0;
  for(int i=l+1;i<r;i++)
    res|=ok[l][i]&&dfsL(l,i)&&dfsR(i,r);
  
  return res;
}

signed main(){
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  memset(ok,0,sizeof(ok));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      ok[i][j]=__gcd(a[i],a[j])>1;
  
  memset(dpL,-1,sizeof(dpL));
  memset(dpR,-1,sizeof(dpR));

  //for(int i=0;i<n;i++) cout<<i<<":"<<dfsL(-1,i)<<" "<<dfsR(i,n)<<endl;
  
  for(int i=0;i<n;i++) if(dfsL(-1,i)&&dfsR(i,n)) return puts("Yes"),0;
  puts("No");
  return 0;
}