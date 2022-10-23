//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,m,a[1005][1005],id[1005][1005],fa[1000005],cnt,vis[1005][1005],ans;
int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
vector<int> vx,vy;
int qx[1000005],qy[1000005],qr;
void add(int x,int y){
    if(vis[x][y]==cnt) return;
    if(a[x][y])vx.pb(x),vy.pb(y);
    else ++qr,qx[qr]=x,qy[qr]=y;
    vis[x][y]=cnt;
}
int c(int x,int y){
    if(a[x][y]==1&&vis[x][y]==cnt) return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%1d",a[i]+j);
            id[i][j]=(i-1)*n+j;
            fa[id[i][j]]=id[i][j];
        }
    }
    for(int i=1;i<=n;++i)a[i][0]=a[i][m+1]=1;
    for(int j=0;j<=m+1;++j)a[0][j]=a[n+1][j]=1;
    for(int i=1;i<=n;++i){
        for(int j=2;j<=m;++j){
            if(a[i][j]&&a[i][j-1])if(get(id[i][j])!=get(id[i][j-1]))fa[fa[id[i][j]]]=fa[id[i][j-1]];
        }
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]&&a[i-1][j])if(get(id[i][j])!=get(id[i-1][j]))fa[fa[id[i][j]]]=fa[id[i-1][j]];
        }
    }
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j)if(a[i][j]&&a[i-1][j]&&a[i][j-1]&&a[i-1][j-1])ans=4;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j]||vis[i][j]) continue;
            vx.clear(),vy.clear(),++cnt;
            qr=1,qx[1]=i,qy[1]=j,vis[i][j]=cnt;
            for(int ql=1;ql<=qr;++ql){
                int x=qx[ql],y=qy[ql];
                add(x-1,y-1),add(x-1,y),add(x-1,y+1),add(x,y-1),add(x,y+1),add(x+1,y-1),add(x+1,y),add(x+1,y+1);
            }
            if(vx.size()<=ans) continue;
            bool ok=1;
            int _=get(id[vx[0]][vy[0]]);
            if(!_) continue;
            for(int k=1;k<vx.size();++k){
                if(get(id[vx[k]][vy[k]])!=_){
                    ok=0;
                    break;
                }
            }
            if(!ok) continue;
            for(int k=0;k<vx.size();++k){
                if(c(vx[k]-1,vy[k])+c(vx[k]+1,vy[k])+c(vx[k],vy[k]-1)+c(vx[k],vy[k]+1)!=2){
                    ok=0;
                    break;
                }
            }
            if(ok)ans=vx.size();
        }
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}