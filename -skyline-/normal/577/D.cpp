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
//I prefer being hacked than being FST
using namespace std;
int n,a[100005],f[100005],c[100005],o;
vector<int> ans1,ans2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),f[i]=i,a[i]==i?o=i:o=o;
    if(o){
          puts("YES");
          for(int i=1;i<=n;i++)if(i!=o)printf("%d %d\n",o,i);
          return 0;
    }
    for(int i=1;i<=n;i++){
            if(f[i]!=i) continue;
            int t=1,l=a[i];
            ans1.pb(i);
            while(l!=i)t++,f[l]=i,t&1?ans1.pb(l):ans2.pb(l),l=a[l];
            if(t&1){
                    puts("NO");
                    return 0;
            }
            if(t==2)o=i;
    }
    if(!o){
           puts("NO");
           return 0;
    }
    puts("YES");
    printf("%d %d\n",o,a[o]);
    for(int i=0;i<ans1.size();i++)if(ans1[i]!=o)printf("%d %d\n",o,ans1[i]);
    for(int i=0;i<ans2.size();i++)if(ans2[i]!=a[o])printf("%d %d\n",a[o],ans2[i]);
//	system("pause");
	return 0;
}