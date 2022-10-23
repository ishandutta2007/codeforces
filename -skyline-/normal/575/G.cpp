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
//I prefer being hacked to being FST
using namespace std;
//
int n,m,d[100005],r[100005],w[100005],e[100005],c[100005],hh[100005];
vector<pair<int,int> > v[100005];
pair<int,int> p[100005];
vector<int> q[100005];
bool b[100005];
void cty(int x){
     if(!x)printf("0");
     else{
          cty(w[x]);
          printf(" %d",x);
     }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int x,y,l;
            scanf("%d%d%d",&x,&y,&l);
            v[x].pb(mp(y,l));
            v[y].pb(mp(x,l));
    }
    memset(d,-1,sizeof(d));
    d[0]=0;
    q[1].pb(0);
    e[0]=-1;
    queue<int> qu;
    qu.push(n-1);
    c[n-1]=1;
    while(!qu.empty()){
                      int k=qu.front();
                      qu.pop();
                      for(int i=0;i<v[k].size();i++)if(!c[v[k][i].first]&&!v[k][i].second)c[v[k][i].first]=c[k]+1,qu.push(v[k][i].first),hh[v[k][i].first]=k;
    }
    int qwer=0;
    for(int _=1;_<=n;_++){
            int l=q[_].size();
            for(int i=0;i<l;i++)p[i]=mp(d[q[_][i]],q[_][i]),b[q[_][i]]=1;
            
            sort(p,p+l);
            int k=0;
            for(int i=0;i<l;i++){
                    if(p[k].first!=p[i].first)k=i;
                    r[p[i].second]=k;
            }
            for(int i=0;i<l;i++)if(c[q[_][i]])qwer=_;
            if(qwer) break;
            for(int i=0;i<l;i++){
                    for(int j=0;j<v[q[_][i]].size();j++){
                            int x=v[q[_][i]][j].first,y=v[q[_][i]][j].second;
                            if(b[x]) continue;
                            if(d[x]==-1)q[_+1].pb(x);
                            if(d[x]==-1||d[x]>y*100000+r[q[_][i]]){
                                                                   d[x]=y*100000+r[q[_][i]];
                                                                   e[x]=y;
                                                                   w[x]=q[_][i];
                            }
                    }
            }
    }
    int o=n;
    r[n]=123456;
    c[n]=123456;
    for(int i=0;i<q[qwer].size();i++){
            if(!c[q[qwer][i]]) continue;
            if(r[q[qwer][i]]<r[o]||(r[q[qwer][i]]==r[o]&&c[q[qwer][i]]<c[o]))o=q[qwer][i];
    }
    
    while(o!=n-1){
                  w[hh[o]]=o;
                  o=hh[o];
                  e[o]=0;
    }
    int s=1,k=n-1;
    bool ok=0;
    while(k!=0){
                s++;
                if(e[k])ok=1;
                if(ok||e[k])printf("%d",e[k]);
                k=w[k];
    }
    if(!ok)printf("0");
    printf("\n");
    printf("%d\n",s);
    cty(n-1);       
    printf("\n");
//	system("pause");
	return 0;
}