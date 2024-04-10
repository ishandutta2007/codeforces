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
using namespace std;
int yy,mm,dd,hh,mi,ss,x,y,n,m,mo[15]={0,31,29,31,30,31,30,31,31,30,31,30,31},f[300003];
char in[5000008];
int main()                                                                  
{
    
    for(int i=1;i<=12;i++)mo[i]+=mo[i-1];
    x=1,y=1;                   
    scanf("%d %d",&n,&m);
    while(scanf("%d-%d-%d %d:%d:%d:",&yy,&mm,&dd,&hh,&mi,&ss)!=EOF){
                          cin.getline(in,5000001);
                          f[x++]=ss+mi*60+hh*3600+dd*86400+mo[mm-1]*86400;
                          //if(n==1)cout<<y<<x;
                          while(f[x-1]-f[y]>=n&&x>y)y++;
                          //if(n==1)cout<<y<<x<<'?'<<f[x-1]<<endl;
                          if((x-y)>=m){
                                       printf("2012-%02d-%02d %02d:%02d:%02d\n",mm,dd,hh,mi,ss);
                                       //system("pause");
                                       return 0;
                          }
    }
    puts("-1");
    return 0;
}