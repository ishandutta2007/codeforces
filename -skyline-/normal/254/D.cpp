#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define mpp(a,b,c)   make_pair(make_pair(a,b),c)      
#define mp(a,b)      make_pair(a,b)
//Author: 

using namespace std;
int n,m,d,s,a[1005][1005],st,ca;
pair<int,int> r[1000005],step[8000],can[8000];
bool l[1000005],f[100010];
char c[1005][1005];
inline int hash(int x,int y){
       return (x*m-m+y)%100001;
}
       
inline void ope(int xx,int yy){
     queue<pair<pair<int,int>,int> > q;
     q.push(mpp(xx,yy,d));
     while(!q.empty()){
                       pair<pair<int,int>,int> qf=q.front();
                       q.pop();
                       int x=qf.first.first,y=qf.first.second;
                       if(c[x][y]=='X'||a[x][y]!=-1) continue;
                       if(a[x][y]=qf.second){
                                   q.push(mpp(x-1,y,a[x][y]-1));
                                   q.push(mpp(x,y-1,a[x][y]-1));
                                   q.push(mpp(x+1,y,a[x][y]-1));
                                   q.push(mpp(x,y+1,a[x][y]-1));
                       }
     }
}

inline void bfs2(int xx,int yy){
     memset(f,0,sizeof(f));
     queue<pair<pair<int,int>,int> > q;
     q.push(mpp(xx,yy,0));
     while(!q.empty()){
                       pair<pair<int,int>,int> qf=q.front();
                       q.pop();
                       int x=qf.first.first,y=qf.first.second,z;
                       if(c[x][y]=='X'||f[hash(x,y)]) continue;
                       f[hash(x,y)]=1;
                       if((z=qf.second)<d){
                                           z++;
                                           q.push(mpp(x-1,y,z));
                                           q.push(mpp(x,y-1,z));
                                           q.push(mpp(x+1,y,z));
                                           q.push(mpp(x,y+1,z));
                       }            
     }
}

inline void bfs(int xx,int yy){
     ca=0;
     memset(f,0,sizeof(f));
     queue<pair<pair<int,int>,int> > q;
     q.push(mpp(xx,yy,0));
     while(!q.empty()){
                       pair<pair<int,int>,int> qf=q.front();
                       q.pop();
                       int x=qf.first.first,y=qf.first.second,z;
                       if(c[x][y]=='X'||f[hash(x,y)]) continue;
                       f[hash(x,y)]=1;
                       can[++ca]=mp(x,y);
                       if((z=qf.second)<d){
                                           z++;
                                           q.push(mpp(x-1,y,z));
                                           q.push(mpp(x,y-1,z));
                                           q.push(mpp(x+1,y,z));
                                           q.push(mpp(x,y+1,z));
                       }
     }
}
                                                  
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d %d",&n,&m,&d);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    char cc=getchar();
                    while(cc<20) cc=getchar();
                    c[i][j]=cc;
                    if(c[i][j]=='R') r[++s]=make_pair(i,j);
            }
    }
    if(s>290){
              printf("-1\n");
              return 0;
    }
              
    memset(a,-1,sizeof(a));
    ope(r[1].first,r[1].second);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    if(a[i][j]!=-1) step[++st]=mp(i,j);
            }
    }               
    for(int i=1;i<=st;i++){
            if(c[step[i].first][step[i].second]=='X') continue;
            memset(a,-1,sizeof(a));
            memset(l,0,sizeof(l));
            ope(step[i].first,step[i].second);
            bool live=0;
            for(int j=1;j<=s;j++) if(a[r[j].first][r[j].second]==-1)l[j]=1,live=1;
            if(!live){
                      for(int x=1;x<=n;x++){
                              for(int y=1;y<=m;y++){
                                      if(c[x][y]!='X'&&(x!=step[i].first||y!=step[i].second)){
                                                                                              printf("%d %d %d %d\n",x,y,step[i].first,step[i].second);                                         
                                                                                              return 0;
                                      }
                              }
                      }
            }
            else{
                 int u,v;
                 for(int j=1;j<=s;j++){
                         if(l[j]){
                                  u=r[j].first;
                                  v=r[j].second;
                                  j=s+1;
                         }
                 }               
                 bfs(u,v);
                 for(int j=1;j<=ca;j++){
                         if(c[can[j].first][can[j].second]=='X') continue;
                         bfs2(can[j].first,can[j].second);
                         bool ok=1;
                         for(int k=1;k<=s;k++){
                                 if(l[k]&&!f[hash(r[k].first,r[k].second)])ok=0,k=s+1;
                         }
                         if(ok){
                                printf("%d %d %d %d\n",can[j].first,can[j].second,step[i].first,step[i].second);                                         
                                return 0;
                         }
                 }   
            }                                                                          
    }
    printf("-1\n");
    return 0;
}