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
//:
#define ll     long long 
using namespace std;
map<int,int> m[2];
set<int> s[2];
int r,c,n;
int main()
{
    scanf("%d%d%d",&r,&c,&n);
    s[0].insert(0);
    s[0].insert(r);
    s[1].insert(0);
    s[1].insert(c);
    m[0][r]=m[1][c]=1;
    for(int i=1;i<=n;i++){
            char cc;
            int x;
            scanf("%s %d",&cc,&x);
            int t=(cc=='H');
            set<int>::iterator it=s[t].lower_bound(x);
            int r=*(it--),l=*it;
            m[t][r-l]--;
            if(!m[t][r-l])m[t].erase(r-l);
            m[t][r-x]++;
            m[t][x-l]++;
            s[t].insert(x);
            long long ans=1ll*(m[0].rbegin()->first)*(m[1].rbegin()->first);
            printf("%I64d\n",ans);
    } 
	//system("pause");
	return 0;
}