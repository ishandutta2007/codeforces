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
ll n,c,s[100005],b[100005],cccc;
int main()
{
    scanf("%I64d%I64d",&n,&c);cccc=c;
    for(ll i=1;i<=n;i++){
            char cc;
            ll p,q;
            scanf(" %c%I64d%I64d",&cc,&p,&q);
            if(cc=='B')b[p]+=q;
            else s[p]+=q;
    }
    ll o=0;
    for(ll k=0;o<=100000;o++){
           if(s[o])k++;
           if(k==c) break;
    }
    for(ll i=o;i>=0;i--){                              
            if(!c) break;
            if(s[i]&&c--)printf("S %I64d %I64d\n",i,s[i]);
    }
    for(ll i=100000;i>=0;i--){                               
            if(!cccc) break;
            if(b[i]&&cccc--)printf("B %I64d %I64d\n",i,b[i]);
    }
 //   system("pause");
    return 0;
}