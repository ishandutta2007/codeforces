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
int q;
int v[6000005][2],o[6000005],s,p[6000005];
int main()
{
    scanf("%d",&q);
    int t=0;
    p[0]=1;
    for(int i=1;i<=30;i++)v[t][0]=i,p[i]=1,t=i;
    s=30;
    o[t]=1;
    for(int i=1;i<=q;i++){
            char c;
            int x;
            scanf(" %c%d",&c,&x);
            if(c=='?'){
                       t=0;
                       int ans=0;
                       for(int i=29;i>=0;i--){
                               int u=(x>>i)&1;
                               u^=1;
                               if(!v[t][u]||!p[v[t][u]]){
                                                         ans=ans*2+(u^1);
                                                         t=v[t][u^1];
                               }
                               else ans=ans*2+u,t=v[t][u];
                       }
                       printf("%d\n",ans^x);
                       continue;
            }
            if(c=='+'){
                       t=0;
                       for(int i=29;i>=0;i--){
                               int u=(x>>i)&1;
                               p[t]++;
                               if(!v[t][u])v[t][u]=++s;
                               t=v[t][u];
                       }
                       p[t]++,o[t]++;
                       continue;
            }
            if(c=='-'){
                       t=0;
                       for(int i=29;i>=0;i--){
                               int u=(x>>i)&1;
                               p[t]--;
                               t=v[t][u];
                       }
                       p[t]--,o[t]--;
            }
    }
//	system("pause");
	return 0;
}