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
int k,n,m;
double f[1050576],a[25],ans[25];
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++)scanf("%lf",a+i);
    m=1<<k;
    f[0]=1.0;
    for(int j=0;j<m;j++){
            int o=0;
            for(int l=0;l<k;l++)if((1<<l)&j)o++;
            if(o>n) continue;
            if(o==n){
                     for(int l=0;l<k;l++)if((1<<l)&j)ans[l]+=f[j];
                     continue;
            }
            double dd=0;
            for(int l=0;l<k;l++){
                    if((1<<l)&j) continue;
                    dd+=a[l];
            }                         
            if(dd<0.0000001) continue;
            for(int l=0;l<k;l++){
                    if((1<<l)&j) continue;
                    f[(1<<l)|j]+=a[l]*f[j]/dd;
            }
    }
    int cnt=0;
    for(int i=0;i<k;i++)if(a[i]>=0.0000001)cnt++;
    if(cnt<=n) for(int i=0;i<k;i++)ans[i]=1.0*(a[i]>=0.0000001);
    for(int i=0;i<k;i++)printf("%.10lf ",ans[i]);
    printf("\n");                       
	//system("pause");
	return 0;
}