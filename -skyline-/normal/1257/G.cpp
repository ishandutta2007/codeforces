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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define P  998244353
using namespace std;
ll fp(ll x,int k=P-2){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%P;
        x=x*x%P,k>>=1;
    }
    return ans;
}
ll a[262222],b[262222],w[262222],w2[262222],A[262222];
int n,c[3000006],m;
struct S{
    int n;
    vector<int> v;
}s[400005];
priority_queue<pair<int,int> >q;
void gen(){
    w[0]=w2[0]=1,w[1]=w2[n-1]=fp(3,(P-1)/n);
    for(int i=2;i<n;++i)w[i]=w2[n-i]=w[i-1]*w[1]%P;
}
void ntt(ll *a,ll *w){
    for(int i=0,j=0;i<n;++i){
        if(i<j)swap(a[i],a[j]);
        for(int k=n>>1;(j^=k)<k;k>>=1);
    }
    for(int i=2;i<=n;i<<=1){
        for(int j=0;j<n;j+=i){
            for(int k=0;k<(i>>1);++k){
                int l=j+k,r=l+(i>>1);
                ll o=a[r]*w[n/i*k]%P;
                a[r]=(a[l]+P-o)%P,a[l]=(a[l]+o)%P;
            }
        }
    }
}
void mul(){
    ntt(a,w),ntt(b,w);
    ll r=fp(n);
    for(int i=0;i<n;++i)a[i]=a[i]*b[i]%P*r%P;
    ntt(a,w2);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int p;
        scanf("%d",&p);
        ++c[p];
    }
    for(int i=1;i<=3000000;++i){
        if(!c[i]) continue;
        ++m;
        s[m].n=c[i];
        for(int j=0;j<=c[i];++j)s[m].v.pb(1);
        q.push(mp(-c[i],m));
    }
    int N=n;
    for(int _=m;_>1;--_){
        int x=q.top().second;
        q.pop();
        int y=q.top().second;
        q.pop();
        int z=s[x].n+s[y].n;
        for(int i=0;i<=s[x].n;++i)a[i]=s[x].v[i];
        for(int i=0;i<=s[y].n;++i)b[i]=s[y].v[i];
        if(s[x].n<=15||s[y].n<=15){
            int X=s[x].n,Y=s[y].n;
            for(int i=0;i<=z;++i)A[i]=0;
            for(int i=0;i<=X;++i){
                for(int j=0;j<=Y;++j)(A[i+j]+=a[i]*b[j])%=P;
            }
            ++m;
            s[m].n=z;
            for(int i=0;i<=z;++i)s[m].v.pb(A[i]);
            q.push(mp(-z,m));
            continue;
        }
        n=1;
        while(n<=z)n<<=1;
        for(int i=s[x].n+1;i<n;++i)a[i]=0;
        for(int i=s[y].n+1;i<n;++i)b[i]=0;
        gen();
        mul();
        ++m;
        s[m].n=z;
        for(int i=0;i<=z;++i)s[m].v.pb(a[i]);
        q.push(mp(-z,m));
    }
    printf("%d\n",s[m].v[(N+1)/2]);
    //system("pause");
    return 0;
}