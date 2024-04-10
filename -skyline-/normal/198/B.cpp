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
int n,k;
bool b[2][200005],ok;
int a[2][200005];                      
queue<pair<bool,int> >x;    
void cty(bool o,int p,int q){
     if(b[o][p]||a[o][p]||p<q) return;
     x.push(make_pair(o,p));
     a[o][p]=q;
}
int main()
{
    scanf("%d%d",&n,&k);
    char in=getchar();
    int q=0;
    while(in=='\n')in=getchar();
    while(in!='\n')b[0][++q]=(in=='X'),in=getchar();
    in=getchar();
    q=0;
    while(in!='\n')b[1][++q]=(in=='X'),in=getchar();
    x.push(make_pair(0,1));
    a[0][1]=1;
    while(!x.empty()){
                      bool o=x.front().first;
                      int p=x.front().second;
                      x.pop();
                      if(p>n){
                              ok=1;
                              break;
                      }                          
                      cty(o,p-1,a[o][p]+1);
                      cty(o,p+1,a[o][p]+1);
                      cty(!o,p+k,a[o][p]+1);
    }
    printf(ok?"YES\n":"NO\n");
//	system("pause");
	return 0;
}