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
//I prefer being hacked than being FST
using namespace std;
int a,b,c,d,e,f;
int x,y,z,o,p,q;
int dtx(int a,int b,int c){
    a=a+b-c;
    if(a<0||a&1) return -1;
    return a>>1;
}
void outa(int t){
     for(int i=1;i<=t;i++)putchar('a');
}
void outb(int t){
     for(int i=1;i<=t;i++)putchar('b');
}
bool cty(){
     x=dtx(a,b,d);
     if(x==-1) return 1;
     y=b-x;
     z=a-x;
     o=dtx(a,c,e);
     p=dtx(b,c,f);
     if(o==-1||p==-1) return 1;
     for(int i=0;i<=x;i++){
             if(i+z<o||i+y<p||i>o||i>p) continue;
             o=o-i;
             p=p-i;
             q=c-o-p-i;
             if(q<0){
                     o+=i;
                     p+=i;
                     continue;
             }
             printf("%d\n",q+x+y+z);
             outa(q+x+y+z);
             putchar('\n');
             outb(x+z);
             outa(y+q);
             putchar('\n');
             outb(x);
             outa(z);
             outb(y);
             outa(q);
             putchar('\n');
             outb(i);
             outa(x-i);
             outb(o);
             outa(z-o);
             outb(p);
             outa(y-p);
             outb(q);
             putchar('\n');
             return 0;
     }
     return 1;
}        
int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(cty())printf("-1\n");
	//system("pause");
	return 0;
}