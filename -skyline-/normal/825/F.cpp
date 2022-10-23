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
#define orz  1000000007ll
#define otz  998244353ll
//:
using namespace std;
//
//
int a[8005],n,cnt[8005],o[8005],dp[8005][8005];
ll e[8005],f[8005],g[8005],h[8005];
int main()
{
    char in=getchar();
    while(in!='\n')a[++n]=in-96,in=getchar();
    for(int i=1;i<=n;i++){
            int end=n+1-i;  
            if(i==1){
                     for(int j=1;j<=n;j++)e[j]=f[j]=g[j]=h[j]=a[j]*1ll;
            }
            else{
                 for(int j=1;j<=end;j++){
                         e[j]=e[j]*otz+a[j+i-1]*1ll;
                         f[j]=(f[j]*31ll+a[j+i-1]*1ll)%orz;
                         g[j]=g[j]*23333ll+a[j+i-1]*1ll;
                         h[j]=h[j]*orz+a[j+i-1]*1ll;
                 }
            }
            for(int j=1;j<=end;j++){
                    int k=i+j-1;
                    if(dp[j][k]) continue;
                    dp[j][k]=1;
                    int s=1;
                    for(int l=k+1;l<=end;l+=i){
                            if(e[l]!=e[j]||f[l]!=f[j]||g[l]!=g[j]||h[l]!=h[j]) break;
                            dp[l][l+i-1]=++s;
                    }
            }
    }
    for(int i=1;i<=9;i++)cnt[i]=1;
    for(int i=10;i<=99;i++)cnt[i]=2;
    for(int i=100;i<=999;i++)cnt[i]=3;
    for(int i=1000;i<=8000;i++)cnt[i]=4;
    for(int i=1;i<=n;i++){
            o[i]=o[i-1]+2;
            int s=0;
            for(int j=i;j;j--){
                    s++;
                    for(int k=1;k<=dp[j][i];k++)o[i]=min(o[i],o[i-k*s]+cnt[k]+s);
            }
    }
    printf("%d\n",o[n]);
	//system("pause");
	return 0;
}