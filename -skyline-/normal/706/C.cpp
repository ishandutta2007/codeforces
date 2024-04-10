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
#define orz  1000000000000007ll
//:
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
int n,s[100005],e[100005];
ll c[100005],dp[100005][2];
char t[100005];
string x[100005],y[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",c+i);
    for(int i=1;i<=n;i++){
            char cc=getchar();
            while(cc=='\n')cc=getchar();
            //s[i]=e[i-1]+1;
            //e[i]=e[i-1];
            while(cc!='\n'){
                            //e[i]++;
                            //t[e[i]]=cc;
                            x[i]+=cc;
                            cc=getchar();
            }
            int l=x[i].size();
            for(int j=1;j<=l;j++)y[i]+=x[i][l-j];
    }
    dp[1][1]=c[1];
    for(int i=2;i<=n;i++){
                 bool ok1=x[i]>=x[i-1],ok2=y[i]>=y[i-1],ok3=y[i]>=x[i-1],ok4=x[i]>=y[i-1];
                 dp[i][0]=dp[i][1]=orz;
                 if(ok1)dp[i][0]=min(dp[i][0],dp[i-1][0]);
                 if(ok2)dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
                 if(ok3)dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
                 if(ok4)dp[i][0]=min(dp[i][0],dp[i-1][1]);
    }
    ll ans=min(dp[n][0],dp[n][1]);
    if(ans>=orz)ans=-1;
    printf("%I64d\n",ans);
	//system("pause");
	return 0;
}