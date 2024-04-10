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
int n,m,k,b[100005],p[100005],res;
inline bool ok(int x){
       int s=k;
       for(int i=1;i<=x;i++){
               if(b[i]<p[x+1-i])s-=(p[x+1-i]-b[i]);
               if(s<0) return 0;
       }
       return 1;
}

int ope(int x){
       int s=k;
       for(int i=1;i<=x;i++){
               if(b[i]<p[x+1-i])s-=(p[x+1-i]-b[i]);
       }
       return s;
}               
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)scanf("%d",b+i);
    for(int i=1;i<=m;i++)scanf("%d",p+i);
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1);
    sort(p+1,p+m+1);
    int s=0,l=min(n,m),o;
    while(l-s>1){
                 o=(s+l)/2;
                 if(ok(o))s=o;
                 else l=o;
    }
    if(ok(l))s=l;
    if(s==0)puts("0 0");
    else{
         res=-ope(s);
         for(int i=1;i<=s;i++)res+=min(p[i],b[s+1-i]);
         if(res<0)res=0;
         printf("%d %d\n",s,res);
    }
         
   // system("pause");
    return 0;
}