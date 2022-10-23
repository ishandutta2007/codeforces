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
struct task{
       long long t,s,p,x;
       bool operator <(task ano) const{
            if(t!=ano.t) return t<ano.t;
            return p>ano.p;
       }
};
task a[100005];       
long long n,p[100040],f[100005],v[100005],ps,spe;
long long T;
set<long long> s;
bool ok(long long k){
     priority_queue<pair<long long,long long> > q;
     for(int i=1;i<=n;i++)v[i]=a[i].s;
     a[spe].p=k;
     long long lt=0;
     for(int i=1;i<=n;i++){
             while(!q.empty()&&lt<a[i].t){
                                          long long p=q.top().second,o=min(a[i].t-lt,v[p]);
                                          v[p]-=o;
                                          lt+=o;
                                          if(!v[p]){
                                                    f[a[p].x]=lt;
                                                    q.pop();
                                          }
             }
             q.push(make_pair(a[i].p,i));
             lt=a[i].t;
     }
     while(!q.empty()){
                       long long p=q.top().second;
                       q.pop();
                       lt+=v[p];
                       f[a[p].x]=lt;
     }
     return f[a[spe].x]==T;
}
                                          
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++){
                          scanf("%I64d%I64d%I64d",&a[i].t,&a[i].s,&a[i].p);
                          a[i].x=i;
                          s.insert(a[i].p);
    }
    scanf("%I64d",&T);
    sort(a+1,a+n+1);
    long long mmaaxx=0;
    for(int i=1;i<=n;i++){
            mmaaxx=max(mmaaxx,a[i].p);
            if(a[i].p==-1)spe=i;
            else if((a[i].p>1)&&!s.count(a[i].p-1))p[++ps]=a[i].p-1;
    }
    p[++ps]=mmaaxx+1;
    sort(p+1,p+ps+1);
    long long l=1,r=ps,m;
    while(l<=r){
                m=(l+r)/2;
                if(ok(p[m])) break;
                if(f[a[spe].x]>T)l=m+1;
                else r=m-1;
    }
    printf("%I64d\n",p[m]);
    for(int i=1;i<n;i++){
            printf("%I64d ",f[i]);
    }
    printf("%I64d\n",f[n]);
	//system("pause");
	return 0;
}