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
int n,q,ans[100005],res;
pair<int,int> p[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x),p[i]=mp(x,0);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
            int x;
            scanf("%d",&x),p[i+n]=mp(x,i);
    }
    sort(p+1,p+n+q+1);
    for(int i=1;i<=n+q;i++){
            if(p[i].second==0)res++;
            else ans[p[i].second]=res;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
//	system("pause");
	return 0;
}