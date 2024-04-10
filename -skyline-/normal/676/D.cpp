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
//:
//from CrAzYUnIoN
//I prefer being hacked than being FST
using namespace std;
int ps,n,m,a[4000005],nm,nm2,nm3,s,xt,yt,xm,ym,q[4000005],ans=orz;
vector<int> v[4000005];
void addup(int x,int y,int s){
     if(x>1)v[s].pb(s-m);
     if(y<m)v[s+nm].pb(s+nm+1);
     if(x<n)v[s+nm2].pb(s+nm2+m);
     if(y>1)v[s+nm3].pb(s+nm3-1);
}
void addright(int x,int y,int s){
     if(x>1)v[s+nm3].pb(s+nm3-m);
     if(y<m)v[s].pb(s+1);
     if(x<n)v[s+nm].pb(s+nm+m);
     if(y>1)v[s+nm2].pb(s+nm2-1);
}
void adddown(int x,int y,int s){
     if(x>1)v[s+nm2].pb(s+nm2-m);
     if(y<m)v[s+nm3].pb(s+nm3+1);
     if(x<n)v[s].pb(s+m);
     if(y>1)v[s+nm].pb(s+nm-1);
}
void addleft(int x,int y,int s){
     if(x>1)v[s+nm].pb(s+nm-m);
     if(y<m)v[s+nm2].pb(s+nm2+1);
     if(x<n)v[s+nm3].pb(s+nm3+m);
     if(y>1)v[s].pb(s-1);
}
int main()
{
    scanf("%d%d",&n,&m);
    nm=n*m,nm2=nm<<1,nm3=nm2+nm;
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                    s++;
                    char c;
                    scanf(" %c",&c);
                    v[s].pb(s+nm);
                    v[s+nm].pb(s+nm2);
                    v[s+nm2].pb(s+nm3);
                    v[s+nm3].pb(s);
                    if(c=='*') continue;
                    if(c=='+'||c=='|'||c=='^'||c=='L'||c=='R'||c=='D')addup(i,j,s);
                    if(c=='+'||c=='-'||c=='>'||c=='L'||c=='U'||c=='D')addright(i,j,s);
                    if(c=='+'||c=='|'||c=='v'||c=='L'||c=='R'||c=='U')adddown(i,j,s);
                    if(c=='+'||c=='-'||c=='<'||c=='U'||c=='R'||c=='D')addleft(i,j,s);
            }
    }
    scanf("%d%d%d%d",&xt,&yt,&xm,&ym);
    int start=(xt-1)*m+yt,end=(xm-1)*m+ym,qs=1,qe=0;
    a[start]=1,q[1]=start;
    while(qs!=qe){
                  int o=q[++qe],z=a[o]+1;
                  if(o%nm==end) break;
                  for(int i=0;i<v[o].size();i++){
                          if(!a[v[o][i]]){
                                          bool b=(v[o][i]==o+nm)||(v[o][i]+nm3==o);
                                          for(int j=0;j<v[v[o][i]].size();j++)if(v[v[o][i]][j]==o)b=1;
                                          if(b)a[v[o][i]]=z,q[++qs]=v[o][i];
                          }
                  }   
    }        
    if(a[end])ans=min(ans,a[end]);
    if(a[end+nm])ans=min(ans,a[end+nm]);
    if(a[end+nm2])ans=min(ans,a[end+nm2]);
    if(a[end+nm3])ans=min(ans,a[end+nm3]);
    if(ans==orz)ans=0;
    ans--;
    printf("%d\n",ans);                
//	system("pause");
	return 0;
}