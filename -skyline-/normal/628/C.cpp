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
int n,x,a[130];
char c[130],in[530000];
int main()
{
    scanf("%d%d",&n,&x);
    scanf("%s",in+1);
    for(int i='a';i<='z';i++){
            c[i]='a',a[i]=i-'a';
            if('z'-i>a[i])a[i]='z'-i,c[i]='z';
    }
    for(int i=1;i<=n;i++){
            if(a[in[i]]<=x)x-=a[in[i]],in[i]=c[in[i]];
            else if(x){
                 if(c[in[i]]=='z')in[i]=in[i]+x;
                 else in[i]=in[i]-x;
                 x=0;
            }
    }
    if(x)printf("-1\n");
    else{
         for(int i=1;i<=n;i++)printf("%c",in[i]);
         printf("\n");
    }
//	system("pause");
	return 0;
}