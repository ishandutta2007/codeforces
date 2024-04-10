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
//:
using namespace std;
int n,m,q,p[300005],d[300005],b[300005],c[300005];
vector<int> e[300005];
inline int ope(int x){return x==p[x]?x:p[x]=ope(p[x]);}
int fnd(int x){
    queue<int> q;
    int u=x,v;
    q.push(x);
    b[x]=0; 
    while(!q.empty()){
                      int o=q.front();
                      q.pop();         
                      if(b[o]>b[u])u=o;
                      for(int i=0;i<e[o].size();i++){
                              if(b[e[o][i]]==-1)b[e[o][i]]=b[o]+1,q.push(e[o][i]);
                      }
    }
    v=u;
    q.push(u);
    c[u]=0;
    while(!q.empty()){
                      int o=q.front();
                      q.pop();
                      if(c[o]>c[v])v=o;
                       
                      for(int i=0;i<e[o].size();i++){
                              if(c[e[o][i]]==-1)c[e[o][i]]=c[o]+1,q.push(e[o][i]);
                      }
    }
    return c[v];
}
inline int gs(int x){return (x+1)/2;}                  
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    memset(b,-1,sizeof(b));  
    memset(c,-1,sizeof(c));  
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            p[ope(y)]=ope(x);
            e[x].push_back(y);
            e[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(p[i]==i)d[i]=fnd(i);
    while(q--){
               int k;
               scanf("%d",&k);
               if(k==1){
                        int x;
                        scanf("%d",&x);
                        printf("%d\n",d[ope(x)]);
               }
               else{
                    int x,y;
                    scanf("%d%d",&x,&y);
                    if(ope(x)==ope(y)) continue;
                    d[p[x]]=max(max(d[p[x]],d[p[y]]),gs(d[p[x]])+gs(d[p[y]])+1);
                    p[p[y]]=p[x];
               }
    }
	//system("pause");
	return 0;
}