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
#define orz  95542721ll
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//:
using namespace std;
int get(){
    register char c=getchar();
    register int o=0;
    while(c<48)c=getchar();
    while(c>47)o=o*10+c-48,c=getchar();
    return o;
}
int O[20],B;
void out(ll x){
     if(!x){
            puts("0");
            return;
     }
     while(x)O[++B]=x%10,x/=10;
     while(B)putchar(O[B--]+48);
     putchar('\n');
}
ll a[100002];
ll f[100002][100];
ll s[100002][100];
int ran[10002],L[10002],R[10002],bu[100002];
int add[100002];
int T[50];
void sum(register int k){
    for(register int i=0;i<48;++i){
        s[k][i]=0;
        for(register int j=L[k];j<=R[k];++j)s[k][i]+=f[j][i+add[j]];
        s[k][i]%=orz;
    }
}
int main(){
    register int n,q,k=0;
    n=get();
    for(register int i=0;i<47;++i)T[i]=i+1;
    for(register int i=1;i<=n;++i)a[i]=get();
    for(register int i=1;i<=n;++i){
        f[i][0]=a[i],bu[i]=(i-1)/20+1;
        for(register int j=1;j<98;j++)f[i][j]=f[i][j-1]*f[i][j-1]%orz*f[i][j-1]%orz;
    }
    for(register int i=1;i<=n;i+=20)R[k]=i-1,L[++k]=i;
    R[k]=n;
    for(register int i=1;i<=k;++i)sum(i);
    q=get();
    while(q--){
        register int t,l,r;
        t=get(),l=get(),r=get();
        if(t==2){
            if(bu[l]==bu[r]){
                for(register int i=l;i<=r;++i)add[i]=T[add[i]];
                sum(bu[l]);
            }
            else{
                register int Q=R[bu[l]];
                for(register int i=l;i<=Q;++i)add[i]=T[add[i]];
                sum(bu[l]);
                l=Q+1;
                for(register int i=L[bu[r]];i<=r;++i)add[i]=T[add[i]];
                sum(bu[r]);
                r=L[bu[r]]-1,Q=bu[r];
                for(register int i=bu[l];i<=Q;++i)ran[i]=T[ran[i]];
            }
        }
        else{
            if(bu[l]==bu[r]){
                register ll ans=0;
                register int A=ran[bu[l]];
                for(register int i=l;i<=r;++i)ans+=f[i][A+add[i]];
                out(ans%orz);
            }
            else{
                register ll ans=0;
                register int Q=R[bu[l]];
                register int A=ran[bu[l]];
                for(register int i=l;i<=Q;++i)ans+=f[i][A+add[i]];
                l=Q+1,A=ran[bu[r]];
                for(register int i=L[bu[r]];i<=r;++i)ans+=f[i][A+add[i]];
                r=L[bu[r]]-1,Q=bu[r];
                for(register int i=bu[l];i<=Q;++i)ans+=s[i][ran[i]];
                out(ans%orz);
            }
        }
    } 
	//system("pause");
	return 0;
}