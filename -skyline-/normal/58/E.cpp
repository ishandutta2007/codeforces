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
//:
using namespace std;
int a[10],b[10],c[10],n,m,k,f[10][10][10][2],g[10][10][10][2];
int x[20],y[20],z[20],l;
int X[20],Y[20],Z[20],L,res=100;
void dfs(int n,int m,int k,int o){
    if(n<0)n=0;
    if(m<0)m=0;
    if(k<0)k=0;
    if(n==0&&m==0&&k==0){
        if(o==1){
            ++l;
            x[l]=y[l]=0,z[l]=1;
            dfs(0,0,0,0);
            --l;
        }
        else{
            int N=l,M=l,K=l;
            while(!x[N]&&N>1)--N;
            while(!y[M]&&M>1)--M;
            while(!z[K]&&K>1)--K;
            if(N+M+K<res){
                res=N+M+K,L=l;
                for(int i=1;i<=l;++i)X[i]=x[i],Y[i]=y[i],Z[i]=z[i];
            }
        }
        return;
    }
    if(n==0&&m==0){
        ++l;
        x[l]=c[k]-o;
        y[l]=0;
        z[l]=c[k];
        if(x[l]<0)x[l]+=10,dfs(0,0,k-1,1);
        else dfs(0,0,k-1,0);
        if(c[k]-o<=18){
            x[l]=9;
            y[l]=c[k]-o+1;
            z[l]=c[k];
            dfs(0,0,k-1,1);
        }
        --l;
        return;
    }
    if(k==0){
        if(n==0){
            ++l;
            x[l]=0;
            y[l]=b[m];
            z[l]=(b[m]+o)%10;
            dfs(0,m-1,0,(b[m]+o)/10);
            --l;
            return;
        }
        if(m==0){
            ++l;
            x[l]=a[n];
            y[l]=0;
            z[l]=(a[n]+o)%10;
            dfs(n-1,0,0,(a[n]+o)/10);
            --l;
            return;
        }
        ++l;
        x[l]=a[n];
        y[l]=b[m];
        z[l]=(a[n]+b[m]+o)%10;
        dfs(n-1,m-1,0,(a[n]+b[m]+o)/10);
        --l;
        return;
    }
    ++l;
    x[l]=a[n];
    y[l]=b[m];
    z[l]=o+a[n]+b[m];
    if(z[l]==c[k]){
        dfs(n-1,m-1,k-1,0);
        --l;
        return;
    }
    if(z[l]==10+c[k]){
        z[l]-=10;
        dfs(n-1,m-1,k-1,1);
        --l;
        return;
    }
    if(z[l]>9)z[l]-=10,dfs(n-1,m-1,k,1);
    else dfs(n-1,m-1,k,0);
    x[l]=a[n];
    y[l]=c[k]-o-a[n];
    z[l]=c[k];
    if(y[l]<0)y[l]+=10,dfs(n-1,m,k-1,1);
    else dfs(n-1,m,k-1,0);  
    x[l]=c[k]-o-b[m];
    y[l]=b[m];
    z[l]=c[k];
    if(x[l]<0)x[l]+=10,dfs(n,m-1,k-1,1);
    else dfs(n,m-1,k-1,0);
    --l;
}
int main(){
    char in=getchar();
    while(in!='+')a[++n]=in-48,in=getchar();
    in=getchar();
    while(in!='=')b[++m]=in-48,in=getchar();
    in=getchar();
    while(in!='\n')c[++k]=in-48,in=getchar();
    dfs(n,m,k,0);
    n=m=k=L;
    while(!X[n]&&n>1)--n;
    while(!Y[m]&&m>1)--m;
    while(!Z[k]&&k>1)--k;
    for(int i=n;i;--i)putchar(X[i]+48);
    putchar('+');
    for(int i=m;i;--i)putchar(Y[i]+48);
    putchar('=');
    for(int i=k;i;--i)putchar(Z[i]+48);
    putchar('\n');
	//system("pause");
	return 0;
}