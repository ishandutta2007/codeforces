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
signed main(){
  int h,w;
  cin>>h>>w;
  vector<string> st(h);
  for(int i=0;i<h;i++) cin>>st[i];

  vector< vector<int> > sm(h+1,vector<int>(w+1,0));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      sm[i+1][j+1]=st[i][j]=='X';

  for(int i=0;i<=h;i++)
    for(int j=0;j<w;j++)
      sm[i][j+1]+=sm[i][j];

  for(int i=0;i<h;i++)
    for(int j=0;j<=w;j++)
      sm[i+1][j]+=sm[i][j];

  auto query=
    [&](int y,int x,int len)->int{
      // [y, y+len) * [x, x+len)
      return (sm[y][x]+sm[y+len][x+len])-(sm[y][x+len]+sm[y+len][x]);
    };

  vector<string> bs(h,string(w,'.'));
  auto construct=
    [&](int t){
      long long area=(long long)(t*2+1)*(t*2+1);
      for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
          bs[i][j]='.';

      for(int i=t;i+t<h;i++)
        for(int j=t;j+t<w;j++)
          if(query(i-t,j-t,t*2+1)==area)
            bs[i][j]='X';
    };

  vector<string> rs(h,string(w,'.'));
  auto expand=
    [&](int t){
      using T = tuple<int, int, int>;
      queue<T> que;
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          rs[i][j]='.';
          if(bs[i][j]=='X'){
            rs[i][j]='X';
            que.emplace(i,j,t);
          }
        }
      }

      while(!que.empty()){
        int y,x,d;
        tie(y,x,d)=que.front();que.pop();
        rs[y][x]='X';
        if(d==0) continue;
        for(int i=-1;i<=1;i++){
          for(int j=-1;j<=1;j++){
            int ny=y+i,nx=x+j,nd=d-1;
            if(rs[ny][nx]=='X') continue;
            rs[ny][nx]='X';
            que.emplace(ny,nx,nd);
          }
        }
      }
    };

  auto check=
    [&](int t)->int{
      construct(t);
      expand(t);
      return rs==st;
    };

  int l=0,r=min(h,w)+1;
  while(l+1<r){
    int m=(l+r)>>1;
    if(check(m)) l=m;
    else r=m;
  }

  construct(l);
  cout<<l<<endl;
  for(int i=0;i<h;i++) cout<<bs[i]<<"\n";
  cout<<flush;
  return 0;
}