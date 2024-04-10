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
int n,t[5005],o[5005],m[5005],x[5005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",t+i);
    for(int i=1;i<=n;i++){
            if(!m[t[i]])m[t[i]]=i,o[i]=1;
            else o[i]=o[m[t[i]]]+1,m[t[i]]=i;
    }
    for(int i=1;i<=n;i++){
            memset(m,0,sizeof(m));
            for(int j=1;j<i;j++)m[t[j]]=j;
            int k=t[i],p=1;
            x[t[i]]++;
            for(int j=i+1;j<=n;j++){
                    if(t[j]==k)p++,x[k]++;
                    else{
                         int y=o[j]-o[m[t[j]]];
                         if(y>p||(y==p&&t[j]<k))k=t[j],p=y,x[k]++;
                         else x[k]++;
                    }
            }
    }
    for(int i=1;i<n;i++)printf("%d ",x[i]);
    printf("%d\n",x[n]);
//	system("pause");
	return 0;
}