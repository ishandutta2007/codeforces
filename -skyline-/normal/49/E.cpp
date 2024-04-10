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
int n,m,q,a[55][55],A[55][55][30],b[55][55],B[55][55][30],f[55][55],t[30][30];
int T[1000005];
string s;
inline void upd(int &x,register int y){if(y<x)x=y;}
inline int get(register int x){return x>32768?T[x>>13]+13:T[x];}
int main(){
    for(register int i=0;i<19;++i)T[1<<i]=i;
    cin>>s;
    n=s.size();
    for(register int i=0;i<n;++i)a[i][i]|=(1<<(s[i]-97));
    cin>>s;
    m=s.size();
    for(register int i=0;i<m;++i)b[i][i]|=(1<<(s[i]-97));
    cin>>q;
    while(q--){
        cin>>s;
        t[s[3]-97][s[4]-97]|=(1<<(s[0]-97));
    }
    for(register int l=0;l<n;++l){
        for(register int i=0;i+l<n;++i){
            register int I=i+l;
            for(register int j=0;j<l;++j){
                register int J=i+j,x=a[J+1][I],k;
                while(x){
                    k=(x&-x),x-=k;
                    a[i][I]|=A[i][J][get(k)];
                }
            }
            register int x=a[i][I],k;
            while(x){
                k=get(x&-x),x-=(1<<k);
                for(register int j=0;j<26;++j)A[i][I][j]|=t[k][j];
            }
        }
    }
    for(register int l=0;l<m;++l){
        for(register int i=0;i+l<m;++i){
            register int I=i+l;
            for(register int j=0;j<l;++j){
                register int J=i+j,x=b[J+1][I],k;
                while(x){
                    k=(x&-x),x-=k;
                    b[i][I]|=B[i][J][get(k)];
                }
            }
            register int x=b[i][I],k;
            while(x){
                k=get(x&-x),x-=(1<<k);
                for(register int j=0;j<26;++j)B[i][I][j]|=t[k][j];
            }
        }
    }
    for(register int i=0;i<=n;++i){
        for(register int j=0;j<=m;++j)f[i][j]=orz;
    }
    f[0][0]=0;
    for(register int i=0;i<n;++i){
        for(register int j=0;j<m;++j){
            for(register int k=0;k<=i;++k){
                for(register int l=0;l<=j;++l)if(a[k][i]&b[l][j])upd(f[i+1][j+1],f[k][l]+1);
            }
        }
    }
    if(f[n][m]==orz)puts("-1");
    else printf("%d\n",f[n][m]);
//	system("pause");
	return 0;
}