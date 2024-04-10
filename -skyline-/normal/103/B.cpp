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
//:
using namespace std;  
int n,m,f[2015],ans;
int ope(int x){return x==f[x]?x:f[x]=ope(f[x]);};
int main()
{
    int x,y;
 	scanf("%d%d",&n,&m);
 	if(n==m){
 	for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
            scanf("%d%d",&x,&y);
            if(ope(x)!=ope(y))f[f[x]]=f[y];                   
    }
    for(int i=1;i<=n;i++)if(ope(i)==f[1])ans++;
    }
    if(ans==n)printf("FHTAGN!\n");
    else printf("NO\n");
	//system("pause");
	return 0;
}