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
int n,x,k,o;
bool b;
pair<pair<int,int>,int> p[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first.first,&p[i].first.second),p[i].second=i;
    sort(p+1,p+n+1);
    if(p[1].first.first==p[2].first.first)b=1,k=p[1].first.first;
    else k=p[1].first.first-p[2].first.first,o=p[1].first.second-p[2].first.second;
    for(x=3;x<=n;x++){
                      if(b&&p[x].first.first==k) continue;
                      if(!b&&(ll)o*1ll*(p[x].first.first-p[2].first.first)==(ll)k*1ll*(p[x].first.second-p[2].first.second)) continue;
                      break;
    }
    printf("%d %d %d\n",p[1].second,p[2].second,p[x].second);
	//system("pause");
	return 0;
}