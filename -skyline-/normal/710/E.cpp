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
ll x,y,n,ans[10000005],res;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&x,&y);  
    for(int i=1;i<=n;i++){
            ans[i]=ans[i-1];
            ll k=i>>1;
            if(i&1)ans[i]=min(ans[i],ans[i-k]+y+x-x*k);
            else ans[i]=min(min(ans[i],ans[k]+y-k*x),min(ans[k-1]+y-x*k,ans[k+1]+y-x*k+x*2ll));    
    }
    printf("%I64d\n",n*x+ans[n]); 
	//system("pause");
	return 0;
}