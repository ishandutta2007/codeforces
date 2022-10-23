//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
using namespace std;
int n,k,m=1,x,y,_,_x;
int main(){
    scanf("%d%d",&n,&k);
    printf("?");
    for(int i=1;i<=k;++i)printf(" %d",i);
    printf("\n");
    fflush(stdout);
    scanf("%d%d",&x,&_x);
    printf("?");
    for(int i=1;i<=k+1;++i)if(i!=x)printf(" %d",i);
    printf("\n");
    fflush(stdout);
    scanf("%d%d",&y,&_);
    if(_<_x)y=x;
    for(int i=1;i<=k;++i){
        if(i==x) continue;
        printf("?");
        int o=0;
        for(int j=1;j<=k+1;++j)if(j!=i)printf(" %d",j);
        printf("\n");
        fflush(stdout);
        scanf("%d%d",&o,&_);
        if(o==y)++m;
    }
    printf("! %d\n",m);
    fflush(stdout);
    //system("pause");
    return 0;
}