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
int n,ans[210000],x[210000],y[210000];
map<int,int> qh,hq;
int main()
{
    scanf("%d",&n);
    if(n%2){
            int o,p,q;
            for(int i=1;i<=n;i++){
                    scanf("%d %d",x+i,y+i);
                    qh[x[i]]=y[i];
                    hq[y[i]]=x[i];
                    if(y[i]==0) o=x[i];
            }
            for(int i=1;i<=n;i++){
                    if(!qh.count(y[i])&&y[i]!=o){
                                              p=y[i];
                                              break;
                    }
            }
            q=qh[0];
            for(int i=2;i<=n;i+=2){
                    ans[i]=q;
                    q=qh[q];
            }
            q=p;
            for(int i=n;i>0;i-=2){
                    ans[i]=q;
                    q=hq[q];
            }
    }
    else{
         int q;
         for(int i=1;i<=n;i++){
                 scanf("%d %d",x+i,y+i);
                 qh[x[i]]=y[i];
                 hq[y[i]]=x[i];
         }                  
         q=qh[0];
         for(int i=2;i<=n;i+=2){
                 ans[i]=q;
                 q=qh[q];
         }
         q=hq[0];
         for(int i=n-1;i>0;i-=2){
                 ans[i]=q;
                 q=hq[q];
         }
    }
    for(int i=1;i<n;i++){
            printf("%d ",ans[i]);
    }
    printf("%d\n",ans[n]);                                                          
   // system("pause");
    return 0;
}