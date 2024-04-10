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
#define ld   long double
//:
using namespace std;
//524288
ld jd[1100000],x[1100000],y[1100000];
ld pi=3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647;
int n,m;
bool b;
ld qq;
void cty(int k,int l,int r,int o){
     if(l>o||r<o) return;
     if(l==r){
              if(b)jd[k]+=qq;
              else x[k]+=qq;
              return;
     }
     int m=(l+r)>>1,e=k<<1;
     cty(e,l,m,o),cty(e^1,m+1,r,o);
     jd[k]=jd[e]+jd[e^1];
     x[k]=x[e]+x[e^1]*cos(jd[e])-y[e^1]*sin(jd[e]);
     y[k]=y[e]+x[e^1]*sin(jd[e])+y[e^1]*cos(jd[e]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)x[i+524288]=1.0;       
    for(int i=524287;i;i--){
            int e=i<<1;
            jd[i]=jd[e]+jd[e^1];
            x[i]=x[e]+x[e^1]*cos(jd[e])-y[e^1]*sin(jd[e]);
            y[i]=y[e]+x[e^1]*sin(jd[e])+y[e^1]*cos(jd[e]);
    }
    while(m--){
               int q,w,Z;
               ld z;
               scanf("%d%d%d",&q,&w,&Z);
               z=Z;
               //if(q==1)x[w+524287]+=z;
               //else jd[--w+524287]-=z*pi/180.0;
               qq=(q==1)?z:-z/180.0*pi;
               b=q-1;
               if(b)w--;
               cty(1,0,524287,w);
               printf("%.20lf %.20lf\n",(double)x[1],(double)y[1]);
    }            
  //	system("pause");
	return 0;
}