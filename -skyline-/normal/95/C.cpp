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
int n,m,s,e;
long long w[1002],c[1002],d[1002];
vector<pair<int,long long> > v[1002],v1[1002];
void ope(int x){
     set<pair<long long,int> >q;
     memset(d,-1,sizeof(d));
     d[x]=0;
     q.insert(make_pair(0,x));
     while(!q.empty()){
                       int k=q.begin()->second;
                       long long l=q.begin()->first;
                       q.erase(q.begin());
                       if(d[k]!=l) continue;                       
                       for(int i=0;i<v[k].size();i++){
                               if(d[v[k][i].first]==-1||d[v[k][i].first]>l+v[k][i].second){
                                                                                           d[v[k][i].first]=l+v[k][i].second;
                                                                                           q.insert(make_pair(d[v[k][i].first],v[k][i].first));
                               }
                       }
     }                   
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i=1;i<=m;i++){
            int x,y;
            long long z;
            scanf("%d%d%I64d",&x,&y,&z);
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=n;i++)scanf("%I64d%I64d",w+i,c+i);
    for(int i=1;i<=n;i++){
            ope(i);
            for(int j=1;j<=n;j++)if(d[j]<=w[i]&&d[j]>0)v1[i].push_back(make_pair(j,c[i]));
    }
    for(int i=1;i<=n;i++)v[i]=v1[i];
    ope(s);
    printf("%I64d\n",d[e]);                
	//system("pause");
	return 0;
}