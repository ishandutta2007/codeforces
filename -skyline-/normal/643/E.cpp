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
int q,n,f[500005],p[500005];
double dp[500005][72];
int main()
{
    scanf("%d",&q);
    n=1;
    for(int i=1;i<=70;i++)dp[1][i]=1.0;
    while(q--){
               int t,x;
               scanf("%d%d",&t,&x);
               if(t==1){
                        p[++n]=x;
                        f[x]++; 
                        x=n;
                        for(int i=1;i<=70;i++)dp[x][i]=1.0;
                        double o=1.0;
                        for(int i=1;i<=70;i++){
                                double oo=0.5+0.5*dp[p[x]][i];
                                dp[p[x]][i]*=(0.5+0.5*dp[x][i-1])/o;
                                o=oo;
                                x=p[x];
                        }
               }
               else{
                    double out=0;
                    for(int i=1;i<=70;i++)out+=1.0-dp[x][i];
                    printf("%.10lf\n",out);
               }
    }
//	system("pause");
	return 0;
}