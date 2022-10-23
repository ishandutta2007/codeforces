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
int n,x[5005],y[5005],m,d[5005][5005],a[5005];
bool dfs(int k,int t){
     if(a[k]!=-1) return a[k]-t;
     a[k]=t;
     for(int i=1;i<=n;i++) if(d[k][i]>m&&dfs(i,t^1)) return 1;
     return 0;
}
     
int ope(){
    int ans=1;
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++){
            if(a[i]==-1){
                         if(dfs(i,0)) return 0;
                         else{
                              ans<<=1;
                              if(ans>=1000000007)ans-=1000000007;
                         }
            }
    }
    return ans;
}
                 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
    for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++)d[i][j]=d[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
    }
    int l=0,r=10002;
    while(r-l>1){
                 m=(l+r)>>1;
                 if(ope())r=m;
                 else l=m;
    }
    m=l;
    if(!ope()) m=r;
    printf("%d\n%d\n",m,ope());        
	//system("pause");
	return 0;
}