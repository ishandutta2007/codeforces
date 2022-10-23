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
using namespace std;
//
//
int n,l;
char c[2000005],in[1000005];
int f[2000005];
int cty(int x){return x==f[x]?x:f[x]=cty(f[x]);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2000000;i++)c[i]='a',f[i]=i;
    for(int i=1;i<=n;i++){
            char C;
            scanf(" %c",&C);
            int o=0;
            while(C!=' ')in[++o]=C,C=getchar();
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                    int x;
                    scanf("%d",&x);
                    l=max(l,x+o-1);
                    int p=cty(x);
                    while(p<=x+o-1){
                                    c[p]=in[p+1-x];
                                    p=f[p]=cty(p+1);
                    }
            }
    }
    for(int i=1;i<=l;i++)printf("%c",c[i]);
    printf("\n");
//	system("pause");
	return 0;
}