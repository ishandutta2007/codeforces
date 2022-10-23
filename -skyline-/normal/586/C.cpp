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
int n,v[4005],d[4005],p[4005],ans[4005],s,k;
void ope(int x){
     int q=d[x];
     for(int i=x+1;i<=n;i++){
             if(p[i]>=0){
                         p[i]-=q;
                         if(p[i]<0)q+=d[i],q=min(1000005,q);
             }
     }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",v+i,d+i,p+i);
    k=1;
    while(k<=n){
                while(k<=n&&p[k]<0)k++;
                if(k>n) break;
                ans[++s]=k;
                int l=k+1;
                vector<int> o;
                for(int i=v[k];i;i--){
                        while(p[l]<0&&l<=n)l++;
                        if(l>n) break;
                        p[l]-=i;
                        if(p[l]<0)o.push_back(l);
                        l++;
                }
                for(int i=0;i<o.size();i++)ope(o[i]);
                k++;
    }
    printf("%d\n",s);
    if(s==0){
             return 0;
    }
    for(int i=1;i<s;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[s]);
  //  system("pause");
    return 0;
}