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
int n,ans[500005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int x,y,xx,yy;
            scanf("%d%d%d%d",&x,&y,&xx,&yy);
            if(x>xx)swap(x,xx);
            if(y>yy)swap(y,yy);
            if((x+orz)%2==1&&(y+orz)%2==1)ans[i]=1;
            if((x+orz)%2==0&&(y+orz)%2==1)ans[i]=2;
            if((x+orz)%2==1&&(y+orz)%2==0)ans[i]=3;
            if((x+orz)%2==0&&(y+orz)%2==0)ans[i]=4;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);        
//	system("pause");
	return 0;
}