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
int ay,by,cy,am,bm,cm,h,a,d,ans;
int main()
{
	scanf("%d%d%d%d%d%d%d%d%d",&ay,&by,&cy,&am,&bm,&cm,&h,&a,&d);
	ans=d*max(bm-cy,0)+a*max(0,cm-by+1);
	for(int dd=cy;dd<bm;dd++){
		int res=2147483640;
		for(int hh=ay;hh<10005;hh++){
			int res2=(hh-1)/(bm-dd);
			if(!res2) continue;
			if(am%res2==0)res2=am/res2;
			else res2=(am/res2)+1;
			res2=max(0,res2-by+cm)*a+(hh-ay)*h;
			res=min(res2,res);
		}
		ans=min(res+(dd-cy)*d,ans);
	}
	printf("%d\n",ans);
	return 0;
}