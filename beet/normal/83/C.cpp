#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){

  auto start=clock();
  
  Int n,m,k;
  cin>>n>>m>>k;
  vector<string> s(n);
  for(Int i=0;i<n;i++) cin>>s[i];
  using P = pair<Int, Int>;
  P S,T;
  int c[26]={};
  for(Int i=0;i<n;i++){
    for(Int j=0;j<m;j++){
      if(s[i][j]=='S') S=P(i,j);
      if(s[i][j]=='T') T=P(i,j);
      if(islower(s[i][j])) c[s[i][j]-'a']++;
    }
  }

  auto in=[&](Int y,Int x){
    return 0<=y&&y<n&&0<=x&&x<m;
  };
  Int dy[]={0,1,0,-1};
  Int dx[]={1,0,-1,0};

  const string INF(n*m,'{');
  string ans=INF;
  vector<Int> vb;
  for(Int b=0;b<(1LL<<26);b++){
    if(__builtin_popcountll(b)>k) continue;
    bool f=1;
    for(int i=0;i<26;i++)
      if((b>>i)&1) f&=!!c[i];
    if(f) vb.push_back(b);
  }
  //*//
  random_device rd;
  mt19937 mt(rd());
  shuffle(vb.begin(),vb.end(),mt);
  //*/
  for(Int b:vb){
    if(((double)clock()-start)/CLOCKS_PER_SEC>2.48) break;
    vector<vector<string> > dp(n,vector<string>(m,INF));
    queue<P> q;
    dp[S.first][S.second]="";
    q.push(S);
    while(!q.empty()){
      P p=q.front();q.pop();
      Int y=p.first,x=p.second;
      if(T==P(y,x)) break;
      if(dp[y][x].size()>ans.size()) break;
      for(Int i=0;i<4;i++){
	Int ny=y+dy[i],nx=x+dx[i];
	if(!in(ny,nx)) continue;
	string nc=dp[y][x];
	if(islower(s[ny][nx])){
	  if(!((b>>(s[ny][nx]-'a'))&1)) continue;
	  nc+=s[ny][nx];
	}
	if(dp[ny][nx].size()<nc.size()) continue;
	if(dp[ny][nx]<=nc) continue; 
	dp[ny][nx]=nc;
	q.emplace(ny,nx);
      }
    }
    if(ans.size()<dp[T.first][T.second].size()) continue;
    if(ans.size()>dp[T.first][T.second].size())
      ans=dp[T.first][T.second];
    ans=min(ans,dp[T.first][T.second]);
  }
  if(ans==INF) ans="-1";
  cout<<ans<<endl;
  return 0;
}