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
int a[2005],n,s,ans,res,prt[2][2000005],b[2005];
bool v[2005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            b[x]=i;
    }
    for(int i=1;i<=n;i++)a[i]=b[a[i]];
    for(int i=1;i<=n;i++){
            int k;
            for(k=1;k<=n;k++)if(a[k]==i) break;
            for(int j=k-1;j>=i;j--){
                    if(a[j]>=k){
                                prt[0][++res]=j,prt[1][res]=k;
                                swap(a[j],a[k]);
                                k=j;
                    }
            }
    }
    for(int i=1;i<=res;i++){
            if(prt[0][i]>prt[1][i])ans+=prt[0][i]-prt[1][i];
            else ans+=prt[1][i]-prt[0][i];
    }
    printf("%d\n%d\n",ans,res);
    for(int i=1;i<=res;i++)printf("%d %d\n",prt[0][i],prt[1][i]);                  
  //  system("pause");
    return 0;
}