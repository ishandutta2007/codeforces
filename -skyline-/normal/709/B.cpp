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
int n,a,l=orz,l2=orz,r=-orz,r2=-orz,ans;
int main()
{
    scanf("%d%d",&n,&a);
    if(n==1){
             printf("0\n");
             return 0;
    }
    for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x<l)l2=l,l=x;
            else if(x<l2)l2=x;
            if(x>r)r2=r,r=x;
            else if(x>r2)r2=x;
    }
    if(n==2)ans=min(abs(a-l),abs(r-a));
    else{
     if(a<=l)ans=r2-a;
     else if(a>=r)ans=a-l2;
     else if(a<=l2)ans=min(min(a-l,r2-a)+r2-l,r-a);
     else if(a>=r2)ans=min(min(r-a,a-l2)+r-l2,a-l);
     else ans=min(min(a-l2,r-a)+r-l2,min(r2-a,a-l)+r2-l);
    }
    printf("%d\n",ans);
//	system("pause");
	return 0;
}