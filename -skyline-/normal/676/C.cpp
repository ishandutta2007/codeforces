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
int n,k,a[100005],ans;
void cty(){
     int o=0,l=0;
     for(int i=1;i<=n;i++){
             if(a[i-1])o--;
             while(l<n&&o+a[l+1]<=k)o+=a[++l];
             ans=max(ans,l-i+1);
     }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
            char c;
            scanf(" %c",&c);
            a[i]=c-'a';
    }
    cty();
    for(int i=1;i<=n;i++)a[i]^=1;
    cty();
    printf("%d\n",ans);
	//system("pause");
	return 0;
}