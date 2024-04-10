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
int n,a[100005],b[100005],k,ans=2;
int main()
{
    scanf("%d",&n);
    a[0]=-5,b[0]=1;
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x==a[k])b[k]++;
            else a[++k]=x,b[k]=1;
    }
    if(k==1){
             printf("%d\n",b[1]);
             return 0;
    }
    a[k+1]=-15,b[k+1]=0;          
    int x=1,y=2,res=b[1]+b[2];
    for(int i=3;i<=k+1;i++){
            if(a[i]==a[x]||a[i]==a[y]){res+=b[i]; continue;}
            ans=max(ans,res);
            x=i-1;
            y=i;
            res=b[x]+b[y];
    }
    printf("%d\n",ans);
   // system("pause");
    return 0;
}