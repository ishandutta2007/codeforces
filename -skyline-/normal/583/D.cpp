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
int a[50005],f[50005],s=1,n,t,c[400];
int ope(int x){
    int l=0,r=s;
    while(r>=l){
                int m=(l+r)>>1;
                if(f[m]>=x)r=m-1;
                else{
                     l=m;
                     if(f[l+1]>=x) return l+1;
                     else l++;
                }
    }
}
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    if(t<=500){
                for(int i=1;i<t;i++){
                        for(int j=1;j<=n;j++)a[i*n+j]=a[j];
                }
                for(int i=1;i<=t*n;i++){
                        f[i]=0;
                        for(int j=max(1,i-n);j<i;j++)if(a[j]<=a[i])f[i]=max(f[i],f[j]);
                        f[i]++;
                }
                for(int i=1;i<=n*t;i++)s=max(s,f[i]);
    }
    else{
         for(int i=1;i<500;i++){
                        for(int j=1;j<=n;j++)a[i*n+j]=a[j];
                }
       
                for(int i=1;i<=n*500;i++){
                        f[i]=0;
                        for(int j=max(1,i-n);j<i;j++)if(a[i]>=a[j])f[i]=max(f[i],f[j]);
                        f[i]++;
                }
        for(int i=1;i<=500*n;i++)s=max(s,f[i]);
        for(int i=1;i<=n;i++)c[a[i]]++;
        int mm=a[1];
        for(int i=2;i<=n;i++)if(c[a[i]]>c[mm])mm=a[i];
        s+=(t-500)*c[mm];
    }
    printf("%d\n",s);
  //  system("pause");
    return 0;
}