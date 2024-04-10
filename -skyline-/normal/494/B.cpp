//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
using namespace std;
//
//
int a[100005],b[100005],n,m,p[100005],f[100005],o[100005],s[100005];
int main()
{
    char c=getchar();
    while(c!='\n')a[++n]=c,c=getchar();
    c=getchar();
    while(c!='\n')b[++m]=c,c=getchar();
    int k=0;
    for(int i=2;i<=m;i++){
            while(k&&b[k+1]!=b[i])k=p[k];
            if(b[k+1]==b[i])k++;
            p[i]=k;
    }
    k=0;
    for(int i=1;i<=n;i++){
            while(k&&b[k+1]!=a[i])k=p[k];
            if(b[k+1]==a[i])k++;
            if(k==m)o[i]=i;
            else o[i]=o[i-1];
            if(!o[i]) continue;
            f[i]=(f[i-1]+s[o[i]-m]+o[i]-m+1)%orz;
            s[i]=(s[i-1]+f[i])%orz;
    }
    printf("%d\n",f[n]);
//	system("pause");
	return 0;
}