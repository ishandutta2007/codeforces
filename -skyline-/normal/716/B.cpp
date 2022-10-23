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
//I prefer being hacked to being FST
using namespace std;
//
int n,f[200],o;
bool ok;
char c[50005];
int main()
{
    char cc=getchar();
    while(cc=='\n')cc=getchar();
    while(cc!='\n'){
                    c[++n]=cc;
                    cc=getchar();
    }
    if(n<26){
             printf("-1\n");
             return 0;
    }
    for(int i=1;i<=25;i++){
            if(c[i]!='?'){
                          f[c[i]]++;
                          if(f[c[i]]==2)o++;
            }
    }
    c[0]='?';
    for(int i=26;i<=n;i++){
            if(c[i-26]=='?')c[i-26]='A';
            else{
                 f[c[i-26]]--;
                 if(f[c[i-26]]==1)o--;
            }
            if(c[i]!='?'){
                          f[c[i]]++;
                          if(f[c[i]]==2)o++;
            }
            if(!o&&!ok){
                   ok=1;
                   char k='A';
                   for(int j=i-25;j<=i;j++){
                           if(c[j]=='?'){
                                         while(f[k])k++;
                                         c[j]=k;
                                         k++;
                           }
                   }
            }
    }
    for(int i=1;i<=n;i++)if(c[i]=='?')c[i]='A';
    if(ok){
           for(int i=1;i<=n;i++)printf("%c",c[i]);
           printf("\n");
    }
    else printf("-1\n");
//	system("pause");
	return 0;
}