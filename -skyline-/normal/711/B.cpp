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
//
ll res=-1,ans,a[505][505],cntt;
int n,x,y,hhh;
int main()
{
    scanf("%d",&n);
    if(n==1){
             printf("48\n");
             return 0;
    }
    for(int i=1;i<=n;i++){
            ll cnt=0,o=0;
            for(int j=1;j<=n;j++){
                    scanf("%I64d",a[i]+j);
                    if(a[i][j]==0)x=i,y=j,o=1;
                    cnt+=a[i][j];
            }
            if(o==1)cntt=cnt;
            else{
                 if(res==-1)res=cnt;
                 else if(cnt!=res)hhh=1;
            }
    }
    a[x][y]=ans=res-cntt;
    if(ans<=0)hhh=1;
    for(int i=1;i<=n;i++){
            ll cnt=0;
            for(int j=1;j<=n;j++)cnt+=a[j][i];
            if(cnt!=res)hhh=1;
    }
    ll cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)cnt1+=a[i][i],cnt2+=a[i][n+1-i];
    if(cnt1!=res||cnt2!=res)hhh=1;
    if(hhh==1)printf("-1\n");
    else printf("%I64d\n",ans);
//	system("pause");
	return 0;
}