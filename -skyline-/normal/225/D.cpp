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
using namespace std;
int n,m,fxx[10]={1,0,-1,0},fxy[10]={0,1,0,-1},ans=-1,v,di,dj;
struct sbt{
       char c[30][30];
       int s,x[12],y[12];
       int hash(){
           int js=0;
           for(int i=1;i<=v;i++){
                   js=js*23+x[i];
                   js=js*23+y[i];
           }
           return js;
       }
       void clr(char q){
            for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++)if(c[i][j]==q)c[i][j]='.';
            }
       }
       void add(){
            c[x[v]][y[v]]='.';
            for(int i=v;i>1;i--){
                    x[i]=x[i-1];
                    y[i]=y[i-1];
                    c[x[i]][y[i]]++;
            }
       }
};
            
bool ok(int x,int y){
     return (x>0&&x<=n&&y>0&&y<=m);
}
                        
queue<sbt> q;
set<int> u;
void ope(sbt &sb){
     sb.s++;
                                 int i=sb.x[2],j=sb.y[2];
                                                   for(int fx=0;fx<=3;fx++){
                                                           int x=i+fxx[fx],y=j+fxy[fx];
                                                           if(x==di&&y==dj){
                                                                            cout<<sb.s<<endl;
                                                                            //system("pause"); 
                                                                            exit(0);
                                                           }
                                                           if(ok(x,y)){
                                                                       if(sb.c[x][y]=='.'){
                                                                                           int has=sb.hash();
                                                                                           if(!u.count(has)){
                                                                                                             sb.c[x][y]='1';
                                                                                                             sb.x[1]=x;
                                                                                                             sb.y[1]=y;
                                                                                                             q.push(sb);
                                                                                                             u.insert(has);
                                                                                                             sb.c[x][y]='.';
                                                                                           }
                                                                       }                     
                                                           }
                                                   }
                                                   return;
}
                         
int main()
{
    cin>>n>>m;
    sbt a;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                              cin>>a.c[i][j];                 
                              if(a.c[i][j]>47&&a.c[i][j]<='9'){
                                                               v=max(v,a.c[i][j]-48);
                                                               a.x[a.c[i][j]-48]=i;
                                                               a.y[a.c[i][j]-48]=j;
                              }                         
                              if(a.c[i][j]=='@'){
                                                 di=i,dj=j;
                                                 int ddd=0;
                                                 if(!ok(i-1,j)||a.c[i-1][j]=='#') ddd++;
                                                 if(!ok(i,j-1)||a.c[i][j-1]=='#') ddd++;
                                                 if(!ok(i+1,j)||a.c[i+1][j]=='#') ddd++;
                                                 if(!ok(i,j+1)||a.c[i][j+1]=='#') ddd++;
                                                 if(ddd==4){
                                                            puts("-1");
                                                            return 0;
                                                 }
                              }             
            }
    }       
    a.s=0;
    u.insert(a.hash());
    q.push(a);
    while(!q.empty()){
                      q.front().clr(v+48);
                      q.front().add();
                      ope(q.front());
                      q.pop();
    }
    puts("-1");                                            
   // system("pause");
    return 0;
}