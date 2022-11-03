#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
struct UnionFind{
  vector<int> r,p;
  UnionFind(){}
  UnionFind(int size){init(size);}
  void init(int size){
    r.clear();
    p.clear();
    r.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) r[i]=1,p[i]=i;
  }
  int find(int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    r[x]+=r[y];
    p[y]=x;
  }
};

int a[1111][1111];
int s[4][1111][1111];
int n,m,q;
void calc(int c){
  int tmp=0;
  for(int i=0;i<=n;i++){
    tmp++;
    if(!a[i][c]){
      for(int j=0;j<tmp;j++) s[0][i-j][c]=j;
      tmp=0;
    }
  }
  tmp=0;
  for(int i=n-1;i>=0;i--){
    tmp++;
    if(!a[i][c]){
      for(int j=0;j<tmp;j++) s[1][i+j][c]=j;
      tmp=0;
      continue;
    }
    if(!i)
      for(int j=0;j<tmp;j++) s[1][i+j][c]=j+1;
  }
}
void calc2(int r){
  int tmp=0;
  for(int i=0;i<=m;i++){
    tmp++;
    if(!a[r][i]){
      for(int j=0;j<tmp;j++) s[2][r][i-j]=j;
      tmp=0;
    }
  }
  tmp=0;
  for(int i=m-1;i>=0;i--){
    tmp++;
    if(!a[r][i]){
      for(int j=0;j<tmp;j++) s[3][r][i+j]=j;
      tmp=0;
      continue;
    }
    if(!i)
      for(int j=0;j<tmp;j++) s[3][r][i+j]=j+1;
  }
}

void pr(){
  cout<<"a:"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int k=0;k<4;k++){
    cout<<"s"<<k<<":"<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	cout<<s[k][i][j]<<" ";
      }
      cout<<endl;
    }
  }
}

signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>q;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];
  int op[q],x[q],y[q];
  for(int i=0;i<q;i++) cin>>op[i]>>x[i]>>y[i];
  for(int i=0;i<m;i++) calc(i);
  for(int i=0;i<n;i++) calc2(i);
  for(int i=0;i<q;i++){
    x[i]--;y[i]--;
    if(op[i]==1){
      a[x[i]][y[i]]=!a[x[i]][y[i]];
      calc(y[i]);
      calc2(x[i]);
      //pr();
      continue;
    }
    int ans=0;
    for(int k=0;k<2;k++){
      UnionFind L(m),R(m);
      priority_queue<P> que;
      for(int j=0;j<m;j++)
	if(y[i]!=j) que.push(P(s[k][x[i]][j],j));
      int hg=s[k][x[i]][y[i]];
      ans=max(ans,hg);
      while(!que.empty()){
	P p=que.top();que.pop();
	if(p.first<=0) break;
	if(p.second>0) R.unite(p.second,p.second-1);
	if(p.second<m-1) L.unite(p.second,p.second+1);
	hg=min(hg,p.first);
	ans=max(ans,hg*(R.find(y[i])-L.find(y[i])+1));
      }
    }
    for(int k=2;k<4;k++){
      UnionFind U(n),D(n);
      priority_queue<P> que;
      for(int j=0;j<n;j++)
	if(x[i]!=j) que.push(P(s[k][j][y[i]],j));
      int hg=s[k][x[i]][y[i]];
      ans=max(ans,hg);
      while(!que.empty()){
	P p=que.top();que.pop();
	if(p.first<=0) break;
	if(p.second>0) D.unite(p.second,p.second-1);
	if(p.second<n-1) U.unite(p.second,p.second+1);
	hg=min(hg,p.first);
	ans=max(ans,hg*(D.find(x[i])-U.find(x[i])+1));
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}