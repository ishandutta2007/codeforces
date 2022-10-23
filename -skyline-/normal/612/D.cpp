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
int n,k,ans,s;
pair<int,int> p[2000005],res[1000005];
int main()
{
    scanf("%d%d",&n,&k);
    n<<=1;
    for(int i=1;i<=n;i+=2)scanf("%d%d",&p[i].first,&p[i+1].first),p[i].second=-1;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++){
            if(p[i].second){
                            if(++s==k)res[++ans].first=p[i].first;
            }else if(k==s--)res[ans].second=p[i].first;
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)printf("%d %d\n",res[i].first,res[i].second);                             
   // system("pause");
    return 0;
}