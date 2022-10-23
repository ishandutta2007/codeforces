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
using namespace std;
int n,k,a[100005],s,l0,r0,l1,r1,la0[100005],la1[100005],nx0[100005],nx1[100005];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%1d",a+i),s+=a[i];
    if(s==0||s==n){
        puts("tokitsukaze");
        return 0;
    }
    while(a[l0+1]==0)++l0;
    while(a[l1+1]==1)++l1;
    r0=r1=n+1;
    while(a[r0-1]==0)--r0;
    while(a[r1-1]==1)--r1;
    if(r1-l1<=k+1||r0-l0<=k+1){
        puts("tokitsukaze");
        return 0;
    }
    la0[1]=la1[1]=1;
    for(int i=2;i<=n;++i){
        if(a[i-1])la1[i]=la1[i-1],la0[i]=i;
        else la0[i]=la0[i-1],la1[i]=i;
    }
    nx0[n]=nx1[n]=n;
    for(int i=n-1;i>0;--i){
        if(a[i+1])nx1[i]=nx1[i+1],nx0[i]=i;
        else nx0[i]=nx0[i+1],nx1[i]=i;
    }
    bool ok=1;
    for(int r=k;r<=n;++r){
        int l=r-k+1;
        int L=la0[l],R=nx0[r];
        int cnt=0;
        if(L-l0>1){
            if(L-l0<=k+1)++cnt;
            else ok=0;
        }
        if(r0-R>1){
            if(r0-R<=k+1)++cnt;
            else ok=0;
        }
        if(cnt>1)ok=0;
        cnt=0;
        L=la1[l],R=nx1[r];
        if(L-l1>1){
            if(L-l1<=k+1)++cnt;
            else ok=0;
        }
        if(r1-R>1){
            if(r1-R<=k+1)++cnt;
            else ok=0;
        }
        if(cnt>1)ok=0;
    }
    if(ok)puts("quailty");
    else puts("once again");
    //system("pause");
    return 0;
}