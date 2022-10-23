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
#define orz  998244353ll
using namespace std;
ll l,r,f[20][1100][2],g[20][1100][2];
int k,cnt[1100],a[20];
ll get(ll o){
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    for(int i=18;i>=0;--i)a[i]=o%10,o/=10;
    int q=0;
    while(!a[q]&&q<=18)++q;
    for(int i=0;i<19;++i){
        for(int _=0;_<1024;++_){
            if(cnt[_]>k) continue;
            for(int j=0;j<a[i];++j)f[i+1][_|(1<<j)][0]+=f[i][_][1]*10+g[i][_][1]*j,g[i+1][_|(1<<j)][0]+=g[i][_][1];
            f[i+1][_|(1<<a[i])][1]+=f[i][_][1]*10+g[i][_][1]*a[i],g[i+1][_|(1<<a[i])][1]+=g[i][_][1];
            for(int j=0;j<10;++j)f[i+1][_|(1<<j)][0]+=f[i][_][0]*10+g[i][_][0]*j,g[i+1][_|(1<<j)][0]+=g[i][_][0];
        }
        if(i==q){
            f[i+1][1<<a[i]][1]+=a[i],++g[i+1][1<<a[i]][1];
            for(int j=1;j<a[i];++j)f[i+1][1<<j][0]+=j,++g[i+1][1<<j][0];
        }
        else if(i>q){
            for(int j=1;j<10;++j)f[i+1][1<<j][0]+=j,++g[i+1][1<<j][0];
        }
        for(int _=0;_<1024;++_)f[i+1][_][0]%=orz,g[i+1][_][0]%=orz,f[i+1][_][1]%=orz,g[i+1][_][1]%=orz;
    }
    ll ans=0;
    for(int _=0;_<1024;++_)if(cnt[_]<=k)(ans+=f[19][_][0]+f[19][_][1])%=orz;
    ans=(ans%orz+orz)%orz;
    return ans;
}
int main(){
    for(int i=0;i<1024;++i){
        for(int j=0;j<10;++j)if(i&(1<<j))++cnt[i];
    }
    scanf("%I64d%I64d%d",&l,&r,&k);
    printf("%I64d\n",(get(r)-get(l-1)+orz)%orz);
//	system("pause");
	return 0;
}