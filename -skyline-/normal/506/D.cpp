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
#include<unordered_map>
#define M(a,b)  make_pair(a,b)
#define ll    long long
using namespace std;
int q,p[200005],n,m,x[100005],y[100005],c[100005],po,gr,o[100005],ans;
unordered_map<ll,int> name;
unordered_map<int,bitset<256> > mb[100005];
set<pair<int,int> > names;
set<int> s[100005];
inline int ope(int x){return x==p[x]?x:p[x]=ope(p[x]);}
ll MM(int x,int y){return x*1000000ll+y;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            scanf("%d%d%d",x+i,y+i,c+i);
            names.insert(M(x[i],c[i]));
            names.insert(M(y[i],c[i]));
    }
    for(set<pair<int,int> >::iterator it=names.begin();it!=names.end();it++){
                          name[(it->first)*1000000ll+it->second]=++po;
    }
    for(int i=1;i<=po;i++)p[i]=i;
    for(int i=1;i<=m;i++)p[ope(name[MM(x[i],c[i])])]=ope(name[MM(y[i],c[i])]);
    for(int i=1;i<=po;i++)if(p[i]==i)o[i]=gr++;
    for(set<pair<int,int> >::iterator it=names.begin();it!=names.end();it++){
                                    s[it->first].insert(o[ope(name[MM(it->first,it->second)])]);
    }
    for(int i=1;i<=n;i++){
            for(set<int>::iterator it=s[i].begin();it!=s[i].end();it++){
                                   mb[i][(*it)>>8].set((*it)&255);
            }
    }
    scanf("%d",&q);
    while(q--){
               int u,v;
               ans=0;
               scanf("%d%d",&u,&v);
               if(mb[u].size()>mb[v].size())swap(u,v);
               for(unordered_map<int,bitset<256> >::iterator it=mb[u].begin();it!=mb[u].end();it++){
                                       int num=it->first;
                                       if(mb[v].find(num)!=mb[v].end())ans+=(mb[u][num]&mb[v][num]).count();
               }
               printf("%d\n",ans);
    }                                                                  
	//system("pause");
	return 0;
}