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
int n,m,k,p[5005],ans[5005];
pair<pair<double,int>,pair<int,int> > q[100005],e[100005];
double d[5002][5002];
inline int rt(int x){return(x==p[x]?x:p[x]=rt(p[x]));}
int prm(){
    int res=0;
    sort(q,q+m+1);
    for(int i=1;i<=n;i++)p[i]=i;
    int t=0;
    for(int i=1;i<n;i++,t++){
            int x=q[t].second.first,y=q[t].second.second;
            while(rt(x)==rt(y)){
                                t++;
                                x=q[t].second.first,y=q[t].second.second;
            } 
            p[p[y]]=p[x];
            ans[i]=q[t].first.second;
            if(x==1)res++;
    }
    return res;
}        
                          
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
            int t;
            scanf("%d%d%d",&e[i].second.first,&e[i].second.second,&t);
            e[i].first=make_pair((double)t,i);
            if(e[i].second.first>e[i].second.second)swap(e[i].second.first,e[i].second.second);
    }
    double l=-2000000,r=2000000,mid,ok=-188;
    for(int i=1;i<=80;i++){
            mid=(l+r)/2;
            for(int j=1;j<=m;j++){
                    q[j]=e[j];
                    if(e[j].second.first==1)q[j].first.first+=mid;
            }
            int t=prm();
            if(t==k){
                     ok=999;
                     break;
            }
            if(t<k) r=mid;
            else l=mid;
    }
    if(ok<0)printf("-1\n");
    else{
         printf("%d\n",n-1);
         for(int i=1;i<n-1;i++)printf("%d ",ans[i]);
         if(n>1)printf("%d\n",ans[n-1]);
    }
	//system("pause");
	return 0;
}