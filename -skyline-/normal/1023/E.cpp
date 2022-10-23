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
int n,x[1100],y[1100];
int main(){
    scanf("%d",&n);
    x[1]=y[1]=1;
    for(int i=1;i<n;++i){
        printf("? %d %d %d %d\n",x[i],y[i]+1,n,n);
        fflush(stdout);
        char c;
        scanf(" %c",&c);
        if(c=='Y')getchar(),getchar();
        else getchar();
        if(c=='Y') x[i+1]=x[i],y[i+1]=y[i]+1;
        else x[i+1]=x[i]+1,y[i+1]=y[i];
    }
    x[n*2-1]=y[n*2-1]=n;
    for(int i=n*2-1;i>n+1;--i){
        printf("? %d %d %d %d\n",x[i-n],y[i-n],x[i]-1,y[i]);
        fflush(stdout);
        char c;
        scanf(" %c",&c);
        if(c=='Y')getchar(),getchar();
        else getchar();
        if(c=='Y') x[i-1]=x[i]-1,y[i-1]=y[i];
        else x[i-1]=x[i],y[i-1]=y[i]-1;
    }
    printf("! ");
    for(int i=1;i<=n*2-2;++i){
        if(x[i+1]==x[i]+1)printf("D");
        else printf("R");
    }
    fflush(stdout);
//	system("pause");
	return 0;
}