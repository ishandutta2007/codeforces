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
int n,m[100005][50],f[100005][50];
ll k,s[100005][50];
int main()
{
    scanf("%d%I64d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",f[i]),f[i][0]++;
    for(int i=1;i<=n;i++)scanf("%d",m[i]),s[i][0]=m[i][0];
    for(int i=1;i<=48;i++){
            for(int j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1],s[j][i]=s[j][i-1]+s[f[j][i-1]][i-1],m[j][i]=min(m[j][i-1],m[f[j][i-1]][i-1]);
    }
    for(int i=1;i<=n;i++){
        ll o=k,sum=0;
        int mn=orz,q=i;
        for(int j=0;j<=48;j++)if(k&(1ll<<j))sum+=s[q][j],mn=min(mn,m[q][j]),q=f[q][j];
        printf("%I64d %d\n",sum,mn);
    }
//	system("pause");
	return 0;
}