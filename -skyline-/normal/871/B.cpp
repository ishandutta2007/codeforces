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
int n,a[5005],b[5005],ans[5005],s,q[10005],x[10005];
map<int,int> m;
void ask(int x,int y){
     printf("? %d %d\n",x,y);
     fflush(stdout);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)ask(i,0),scanf("%d",a+i),x[a[i]]=i;
    for(int i=0;i<n;i++)ask(x[0],i),scanf("%d",b+i);
    for(int i=0;i<n;i++){
            memset(q,-1,sizeof(q));
            for(int j=0;j<n;j++)q[a[j]^i]=j;
            bool ok=1;
            for(int j=0;j<n;j++)if(q[j]!=(b[j]^i))ok=0,j=n;
            if(ok)ans[++s]=i;
    }
    printf("!\n");
    printf("%d\n",s);
    s=ans[1];
    for(int i=0;i<n-1;i++)printf("%d ",a[i]^s);
    printf("%d\n",a[n-1]^s);
    fflush(stdout);
	//system("pause");
	return 0;
}