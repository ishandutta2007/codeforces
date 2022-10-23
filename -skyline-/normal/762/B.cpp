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
//
int a,b,c,m,p,q,res;
ll x[300005],y[300005],ans;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
            ll s;
            scanf("%I64d",&s);
            getchar();
            char c=getchar();
            if(c=='U')x[++p]=s,getchar(),getchar();
            else y[++q]=s,getchar(),getchar(),getchar();
    }
    int o=0,t=0;
    sort(x+1,x+p+1);
    sort(y+1,y+q+1);
    x[p+1]=orz;
    y[q+1]=orz;
    o=min(p,a);
    t=min(q,b);
    for(int i=1;i<=o;i++)ans+=x[i],res++;
    for(int i=1;i<=t;i++)ans+=y[i],res++;
    o++,t++;
    for(int i=1;i<=c;i++){
            ll r=min(x[o],y[t]);
            if(r>=orz*1ll) break;
            if(x[o]>y[t])ans+=y[t],res++,t++;
            else ans+=x[o],res++,o++;
    }
    printf("%d %I64d\n",res,ans);
//	system("pause");
	return 0;
}