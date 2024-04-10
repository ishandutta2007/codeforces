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
//:
using namespace std;
int p[200005],p1[200005],n,q;
int ope(int x){return x==p[x]?x:p[x]=ope(p[x]);};
int ope1(int x){return x==p1[x]?x:p1[x]=ope1(p1[x]);};

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)p[i]=p1[i]=i;
    while(q--){
               int t,x,y;
               scanf("%d%d%d",&t,&x,&y);
               if(t==1){if(ope(x)!=ope(y))p[p[x]]=p[y];}
               else if(t==3) printf(ope(x)==ope(y)?"YES\n":"NO\n");
               else{
                    while((x=ope1(x))<y){
                                         p1[x]=x+1;
                                         if(ope(x)!=ope(y))p[p[x]]=p[y];
                    }
               }
    }                   
	//system("pause");
	return 0;
}