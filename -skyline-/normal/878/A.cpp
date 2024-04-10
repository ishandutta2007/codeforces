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
//:
using namespace std;
//
//
int n,f[10];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<10;i++)f[i]=2;
    for(int i=1;i<=n;i++){
            char c;
            scanf(" %c",&c);
            int o;
            scanf("%d",&o);
            if(c=='&'){
                       for(int i=0;i<10;i++)if((o&(1<<i))==0)f[i]=0;
            }
            if(c=='|'){
                       for(int i=0;i<10;i++)if(o&(1<<i))f[i]=1;
            }
            if(c=='^'){
                       for(int i=0;i<10;i++)if(o&(1<<i))f[i]^=1;
            }
    }
    int s=0;
    printf("2\n");
    for(int i=0;i<10;i++)if(f[i]<=1)s+=(1<<i);       
    printf("| %d\n",s);
    s=0; 
    for(int i=0;i<10;i++)if(f[i]==0||f[i]==3)s+=(1<<i);  
    printf("^ %d\n",s);
	//system("pause");
	return 0;
}