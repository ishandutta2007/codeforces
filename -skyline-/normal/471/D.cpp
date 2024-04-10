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
int n,m,a[200005],b[200005],p[200005],ans;
int main()
{
    scanf("%d%d",&n,&m);
    if(n<m){
            puts("0\n");
            return 0;
    }
    if(m==1){
             printf("%d\n",n);
             return 0;
    }
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++)scanf("%d",b+i);
    for(int i=1;i<n;i++)a[i]=a[i]-a[i+1];
    for(int i=1;i<m;i++)b[i]=b[i]-b[i+1];
    n--;
    m--;
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
            if(k==m)ans++;
    }
    printf("%d\n",ans);
	//system("pause");
	return 0;
}