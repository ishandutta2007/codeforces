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
int n,m,k,a[105][105],s1,ans,p[20];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)scanf("%d",a[i]+j),s1+=a[i][j];
    }
    ans=min(s1,n*m-s1);
    if(max(n,m)>k){
                   for(int i=1;i<=n;i++){
                           int s=0;
                           for(int j=1;j<=n;j++){
                                   int s0=0;
                                   for(int l=1;l<=m;l++)if(a[i][l]==a[j][l])s0++;
                                   s+=min(s0,m-s0);
                           }
                           ans=min(ans,s);
                   }
                   for(int i=1;i<=m;i++){
                           int s=0;
                           for(int j=1;j<=m;j++){
                                   int s0=0;
                                   for(int l=1;l<=n;l++)if(a[l][i]==a[l][j])s0++;
                                   s+=min(s0,n-s0);
                           }
                           ans=min(ans,s);
                   }
    }
    else{
         while(!p[0]){                                   
                      int s=0;
                      for(int i=1;i<=m;i++)a[1][i]^=p[i],s+=p[i];
                      for(int i=2;i<=n;i++){
                              int s0=0;
                              for(int l=1;l<=m;l++)if(a[1][l]!=a[i][l])s0++;
                              s+=min(s0,m-s0);
                      }
                      ans=min(ans,s);
                      for(int i=1;i<=m;i++)a[1][i]^=p[0];
                      int l=m;
                      while(p[l])p[l--]=0;
                      p[l]=1;
         }
    }
    if(ans>k)ans=-1;
    printf("%d\n",ans);                  
	//system("pause");
	return 0;
}