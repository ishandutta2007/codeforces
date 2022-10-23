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
using namespace std;
int n,q[100005],s[100005],m=2147483640;
bool u[100005];
void ope(int k,int x){
     if(k>100000||k<1) return;
     if(u[k]) return;
     u[k]=1;
     q[k]++;
     s[k]+=x;
     ope(k/2,x+1);
     ope(k*2,x+1);
}
     
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            int c;
            scanf("%d",&c);
            memset(u,0,sizeof(u));
            ope(c,0);
    }
    for(int i=1;i<=100001;i++){
            if(q[i]==n) m=min(m,s[i]);
    }
    printf("%d\n",m);              
	//system("pause");
	return 0;
}