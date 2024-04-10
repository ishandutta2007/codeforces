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
int n,m,k,x[10005],y[10005],p[505],o[20005],ans[505][20005];
bool b[505];
int ope(int q){return q==p[q]?q:p[q]=ope(p[q]);};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d",x+i,y+i);
    for(int i=1;i<=n;i++)p[i]=i;
    o[0]=n;
    for(int i=1;i<=m;i++){
            if(ope(x[i])==ope(y[i]))o[i]=o[i-1];
            else p[p[x[i]]]=p[y[i]],o[i]=o[i-1]-1;
    }
    for(int i=0;i<=m;i++){
            if(b[o[i]]) continue;
            b[o[i]]=1;
            for(int j=1;j<=n;j++)p[j]=j;
            for(int j=1;j<=i;j++)if(ope(x[j])!=ope(y[j]))p[p[x[j]]]=p[y[j]];
            ans[o[i]][m]=o[i];
            for(int j=m;j>=1;j--){
                    if(ope(x[j])==ope(y[j]))ans[o[i]][j-1]=ans[o[i]][j];
                    else p[p[x[j]]]=p[y[j]],ans[o[i]][j-1]=ans[o[i]][j]-1;
            }
    }          
    scanf("%d",&k);
    while(k--){
               int l,r;
               scanf("%d%d",&l,&r);
               printf("%d\n",ans[o[l-1]][r]);
    }
	//system("pause");
	return 0;
}