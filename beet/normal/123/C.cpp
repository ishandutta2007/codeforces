#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n,m,k;
  cin>>n>>m>>k;
  assert((n+m)&1);
  vector<vector< Int > > a(n,vector<Int>(m));
  for(Int i=0;i<n;i++)
    for(Int j=0;j<m;j++)
      cin>>a[i][j];

  vector<Int> ry(n*m+1),rx(n*m+1),rd(n*m+1);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<m;j++)
      ry[a[i][j]]=i,rx[a[i][j]]=j,rd[a[i][j]]=i+j;
  
  Int s=n+m-3;
  vector<Int> v(s+1,n*m+1);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<m;j++)
      if(i+j) v[i+j-1]=min(v[i+j-1],a[i][j]);
  v.pop_back();
  
  //for(Int i=0;i<s;i++) cout<<i<<":"<<v[i]<<endl;

  vector<vector< char > > c(n,vector<char>(m,'('));
  c[0][0]='(';
  c[n-1][m-1]=')';
  
  auto add=[&](Int& a,Int b){
    a=min(k,a+b);
  };
  
  vector<Int> d(s,-1);
  
  auto check=[&](){
    vector<vector<Int> > dp(s+1,vector<Int>(s+2,0));
    dp[0][1]=1;
    for(Int i=0;i<s;i++){
      for(Int j=0;j<s+2;j++){
	if(dp[i][j]<=0) continue;
	// open
	if(d[i]!=1)
	  add(dp[i+1][j+1],dp[i][j]);
	// close
	if(d[i]!=0)
	  if(j) add(dp[i+1][j-1],dp[i][j]);
      }
    }
    //cout<<dp[s][1]<<endl;
    return dp[s][1];
  };

  using P = pair<Int,int>;

  priority_queue<P> q;
  for(Int i=0;i<s;i++) q.push(P(-v[i],i));
  while(!q.empty()){
    P p=q.top();q.pop();
    Int x=p.second;
    //cout<<"x:"<<x<<" k:"<<k<<endl;
    assert(d[x]<0);
    d[x]=0;
    Int y=check();
    if(y<k){
      d[x]=1;
      k-=y;
      Int z=rd[-p.first];
      //cout<<-p.first<<" "<<z<<endl;
      for(Int i=0;i<=z;i++)
	if(0<=i&&i<n&&0<=z-i&&z-i<m) c[i][z-i]=')';
    }
    assert(check()>=k);
  }
  
  for(Int i=0;i<n;i++){
    for(Int j=0;j<m;j++)
      cout<<c[i][j];
    cout<<endl;
  }
  return 0;
}