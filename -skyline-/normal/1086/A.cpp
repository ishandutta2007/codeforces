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
int x[4],y[4],f[1005][1005],ans=orz;
int main(){
    for(int i=1;i<=3;++i)scanf("%d%d",x+i,y+i);
    for(int i=0;i<=1000;++i){
        for(int j=0;j<=1000;++j){
            int o=1;
            for(int k=1;k<=3;++k)o+=abs(x[k]-i)+abs(y[k]-j);
            if(o<ans)ans=o,x[0]=i,y[0]=j;
        }
    }
    printf("%d\n",ans);
    printf("%d %d\n",x[0],y[0]);
    for(int k=1;k<=3;++k){
        int X=x[k],Y=y[k];
        while(X!=x[0]||Y!=y[0]){
            printf("%d %d\n",X,Y);
            if(X<x[0])++X;
            else if(X>x[0])--X;
            else if(Y<y[0])++Y;
            else --Y;
        }
    }
//	system("pause");
	return 0;
}