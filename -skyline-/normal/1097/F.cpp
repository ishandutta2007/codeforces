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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n,q,mu[7002];
bitset<7002> b[100005],ins[7002],qry[7002];
int get(){
    int x=0;
    char c=getchar();
    while(c<48)c=getchar();
    while(c>47)x=x*10+c-48,c=getchar();
    return x;
}
int main(){
    n=get();q=get();
    mu[1]=1;
    for(int i=1;i<=7000;++i){
        ins[i][i]=1;
        for(int j=i*2;j<=7000;j+=i){
            ins[j][i]=1;
            mu[j]-=mu[i];
        }
    }
    for(int i=1;i<=7000;++i){
        mu[i]=(mu[i]%2+2)%2;
    }
    for(int i=1;i<=7000;++i){
        for(int j=i;j<=7000;j+=i){
            if(mu[j/i]&1)qry[i][j]=1;
        }
    }
    for(int i=1;i<=q;++i){
        int t,x,y,z;
        t=get();
        if(t==1){
            x=get();y=get();
            b[x]=ins[y];
        }
        if(t==2){
            x=get();y=get();z=get();
            b[x]=b[y]^b[z];
        }
        if(t==3){
            x=get();y=get();z=get();
            b[x]=b[y]&b[z];
        }
        if(t==4){
            x=get();y=get();
            int k=(b[x]&qry[y]).count();
            if(k&1)putchar('1');
            else putchar('0');
        }
    }
	//system("pause");
	return 0;
}