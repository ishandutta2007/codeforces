#include<bits/stdc++.h>
using namespace std;
using Int = signed;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}



struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
const int MAX = 2020;
int dpl[MAX][MAX];
int dpr[MAX][MAX];

signed main(){
  int n,m,r,c,x,y;
  cin>>n>>m>>r>>c>>x>>y;
  r--;c--;
  
  vector<string> vs(n);
  for(int i=0;i<n;i++) cin>>vs[i];


  int dy[]={1,-1,0,0};
  int dx[]={0,0,-1,1};

  using P = pair<int, int>;
  auto in=[&](int s,int t){return 0<=s&&s<n&&0<=t&&t<m;};

  const int INF = 1e9+10;
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      dpl[i][j]=dpr[i][j]=INF;
  
  //left
  {
    int dc[]={0,0,1,0};
    deque<P> q;
    dpl[r][c]=0;
    q.emplace_back(r,c);
    while(!q.empty()){
      int s,t;
      tie(s,t)=q.front();q.pop_front();
      for(int k=0;k<4;k++){
	int ns=s+dy[k],nt=t+dx[k],nc=dpl[s][t]+dc[k];
	if(!in(ns,nt)||vs[ns][nt]=='*'||dpl[ns][nt]<=nc) continue;
	dpl[ns][nt]=nc;
	if(dc[k]) q.emplace_back(ns,nt);
	else q.emplace_front(ns,nt);
      }
    }
  }
  
  //right
  {
    int dc[]={0,0,0,1};
    deque<P> q;
    dpr[r][c]=0;
    q.emplace_back(r,c);
    while(!q.empty()){
      int s,t;
      tie(s,t)=q.front();q.pop_front();
      for(int k=0;k<4;k++){
	int ns=s+dy[k],nt=t+dx[k],nc=dpr[s][t]+dc[k];
	if(!in(ns,nt)||vs[ns][nt]=='*'||dpr[ns][nt]<=nc) continue;
	dpr[ns][nt]=nc;
	if(dc[k]) q.emplace_back(ns,nt);
	else q.emplace_front(ns,nt);
      }
    }
  }
  
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){  
      if(dpl[i][j]>x||dpr[i][j]>y) continue;
      ans++;
    }
  }

  const int DBG = 0;
  if(DBG){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
	cout<<(dpl[i][j]<=x&&dpr[i][j]<=y);
      cout<<endl;
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
	cout<<setw(2)<<dpl[i][j];
      cout<<endl;
    }
    
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
	cout<<setw(2)<<dpr[i][j];
      cout<<endl;
    }
  }
  
  cout<<ans<<endl;  
  return 0;
}