//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
    template<class T>
    inline void read(T &x) {
        x=0;
        bool fu=0;
        char ch=0;
        while(ch>'9'||ch<'0') {
            ch=getchar();
            if(ch=='-')fu=1;
        }
        while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
        if(fu)x=-x;
    }
    inline int read() {
        int x=0;
        bool fu=0;
        char ch=0;
        while(ch>'9'||ch<'0') {
            ch=getchar();
            if(ch=='-')fu=1;
        }
        while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
        return fu?-x:x;
    }
    template<class T,class... Args>
    inline void read(T& t,Args&... args) {
        read(t);
        read(args...);
    }
    char _n_u_m_[40];
    template<class T>
    inline void write(T x) {
        if(x==0){
            putchar('0');
            return;
        }
        T tmp = x > 0 ? x : -x ;
        if( x < 0 ) putchar('-') ;
        register int cnt = 0 ;
        while( tmp > 0 ) {
            _n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
            tmp /= 10 ;
        }
        while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
    }
    template<class T>
    inline void write(T x ,char ch) {
        write(x);
        putchar(ch);
    }
}
using namespace fastIO;
//998244353,1004535809
namespace Poly1 {
#define mod 998244353
#define MOD mod
#define P mod
//
inline long long pw(long long x,long long p) {
    long long res=1;
    for(; p; p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
//
inline int getm(long long top,long long bot) {
    return (top*pw(bot,mod-2))%mod;
}
namespace getinv {
    int *inv,*fac,*ifac;// 
    ///ln/exp/main
    void init_inv(int n) {
        inv=new int[n+1];
        inv[0]=1;
        inv[1]=1;
        for(register int i=2; i<=n; ++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    //main
    void init_inv_with_fac(int n) {
        inv=new int[n+1];
        fac=new int[n+1];
        ifac=new int[n+1];
        inv[0]=fac[0]=ifac[0]=1;
        inv[1]=1;
        for(register int i=2; i<=n; ++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        for(register int i=1; i<=n; ++i) fac[i]=1ll*fac[i-1]*i%mod;
        for(register int i=1; i<=n; ++i) ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
    }
}
using namespace getinv;
    int *w[30];//
//main
    void NTT_set(int MAXN) {
        for(int i=2,t=0; i<2*MAXN; i<<=1,t++) {
            w[t]=new int[i>>1];
            ll wn=pw(3,(MOD-1)/i);
            w[t][0]=1;
            for(int j=1; j<(i>>1); j++) w[t][j]=w[t][j-1]*wn%MOD;
        }
    }
    struct poly {
        vector<int>a;//f=a[0]+a[1]*x+a[2]*x^2+...+a[n]*x^n
        //nsizena.size()=n+1
        /*----------------------------------------*/
        poly() {
        }
        poly(int sz) {
            a.resize(sz+1);
        }
#if __cplusplus >= 201103L
        poly(initializer_list<int>x) {
            a=x;
        }
#endif
        poly(vector<int>vec) {
            a=vec;
        }
        template<class T>
        poly(T s,T t) {
            //
            a=vector<int>(s,t);
        }
        poly(const poly &x) {
            a=x.a;
        }
        /*----------------------------------------*/
        inline int size() {
            return a.size()-1;
        }
        inline void resize(int x) {
            a.resize(x+1);
        }
        inline int& operator[](int pos) {
            return a[pos];
        }
        inline poly subpoly(int l,int r) {
            //
            return poly(&a[l],&a[r]);
        }
        /*----------------------------------------*/
        //NTT
        inline void NTT() {
            int N=a.size(),len=1;//N=+1
            while(len<N)len<<=1;
            if(N<len) {
                resize(len-1);
            }
            unsigned ll A[len];
            F(i,0,len-1)A[i]=a[i];
            register int j=len>>1;
            for(register int i=1; i<len-1; i++) {
                if (i<j) swap(A[i],A[j]);
                int k=len>>1;
                while (j>=k) {
                    j-=k;
                    k>>=1;
                }
                j+=k;
            }
            for(register int i=2,t=0; i<=len; i<<=1,t++) {
                if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
                for(register int j=0; j<len; j+=i)
                    for(register int k=j; k<j+(i>>1); k++) {
                        unsigned ll u=A[k];
                        unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
                        A[k]=u+v;
                        A[k+(i>>1)]=u-v+mod;
                    }
            }
            F(i,0,len-1)a[i]=A[i]%mod;
        }
        //NTT
        inline void UNTT() {
            int N=a.size(),len=1;//N=+1
            while(len<N)len<<=1;
            if(N<len) {
                resize(len-1);
            }
            unsigned ll A[len];
            F(i,0,len-1)A[i]=a[i];
            register int j=len>>1;
            for(register int i=1; i<len-1; i++) {
                if (i<j) swap(A[i],A[j]);
                int k=len>>1;
                while (j>=k) {
                    j-=k;
                    k>>=1;
                }
                j+=k;
            }
            for(register int i=2,t=0; i<=len; i<<=1,t++) {
                if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
                for(register int j=0; j<len; j+=i)
                    for(register int k=j; k<j+(i>>1); k++) {
                        unsigned ll u=A[k];
                        unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
                        A[k]=u+v;
                        A[k+(i>>1)]=u-v+mod;
                    }
            }
            reverse(A+1,A+len);
            ll nev=pw(len,MOD-2);
            for(int i=0; i<len; i++) a[i]=(A[i]%MOD)*nev%MOD;
        }
        /*----------------------------------------*/
        //
        inline poly operator+(poly b) {
            register int n=size(),bn=b.size();
            if(n>=bn) {
                poly rt(a);
                for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
                return rt;
            }
            poly rt(b);
            for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
            return rt;
        }
        //
        inline poly operator-(poly b) {
            register int n=size(),bn=b.size();
            if(n>=bn) {
                poly rt(a);
                for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
                return rt;
            }
            poly rt(bn);
            for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
            for(register int i=n+1; i<=bn; ++i)rt.a[i]=(mod-b.a[i])%mod;
            return rt;
        }
        //
        inline poly operator-() {
            register int n=size();
            poly rt(n);
            for(register int i=0; i<=n; ++i)rt.a[i]=(mod-a[i])%mod;
            return rt;
        }
        //
        inline poly operator*(poly b) {
            int n=size(),bn=b.size();
            int len=n+bn;
            if(1ll*n*bn<=10000) {
                poly rt(len);
                for(register int i=0; i<=n; ++i) {
                    for(register int j=0; j<=bn; ++j) {
                        rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
                    }
                }
                return rt;
            }
            poly A(a),B(b.a);
            A.resize(len);
            B.resize(len);
            A.NTT();
            B.NTT();
            poly rt(A.size());
            for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
            rt.UNTT();
            rt.resize(len);
            return rt;
        }
        //
        inline poly operator&(poly b) {
            int n=size(),bn=b.size();
            int len=n+bn;
            if(1ll*n*bn<=10000) {
                poly rt(n);
                for(register int i=0; i<=n; ++i) {
                    for(register int j=0; j<=min(bn,n-i); ++j) {
                        rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
                    }
                }
                return rt;
            }
            poly A(a),B(b.a);
            A.resize(len);
            B.resize(len);
            A.NTT();
            B.NTT();
            poly rt(A.size());
            for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
            rt.UNTT();
            rt.resize(n);
            return rt;
        }
        inline poly rev() {
            poly rt(a);
            reverse(rt.a.begin(),rt.a.end());
            return rt;
        }
        //res[i-j]+=f[i]*g[j]
        inline poly operator^(poly b) {
            poly temp=b.rev();
            temp=(*this)*temp;
            temp.a.erase(temp.a.begin(),temp.a.begin()+b.size());
            return temp;
        }
    } A,B;
}
#undef mod
#undef MOD
#undef P
namespace Poly2 {
#define mod 1004535809
#define MOD mod
#define P mod
//
inline long long pw(long long x,long long p) {
    long long res=1;
    for(; p; p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
//
inline int getm(long long top,long long bot) {
    return (top*pw(bot,mod-2))%mod;
}
namespace getinv {
    int *inv,*fac,*ifac;// 
    ///ln/exp/main
    void init_inv(int n) {
        inv=new int[n+1];
        inv[0]=1;
        inv[1]=1;
        for(register int i=2; i<=n; ++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    //main
    void init_inv_with_fac(int n) {
        inv=new int[n+1];
        fac=new int[n+1];
        ifac=new int[n+1];
        inv[0]=fac[0]=ifac[0]=1;
        inv[1]=1;
        for(register int i=2; i<=n; ++i) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
        for(register int i=1; i<=n; ++i) fac[i]=1ll*fac[i-1]*i%mod;
        for(register int i=1; i<=n; ++i) ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
    }
}
using namespace getinv;
    int *w[30];//
//main
    void NTT_set(int MAXN) {
        for(int i=2,t=0; i<2*MAXN; i<<=1,t++) {
            w[t]=new int[i>>1];
            ll wn=pw(3,(MOD-1)/i);
            w[t][0]=1;
            for(int j=1; j<(i>>1); j++) w[t][j]=w[t][j-1]*wn%MOD;
        }
    }
    struct poly {
        vector<int>a;//f=a[0]+a[1]*x+a[2]*x^2+...+a[n]*x^n
        //nsizena.size()=n+1
        /*----------------------------------------*/
        poly() {
        }
        poly(int sz) {
            a.resize(sz+1);
        }
#if __cplusplus >= 201103L
        poly(initializer_list<int>x) {
            a=x;
        }
#endif
        poly(vector<int>vec) {
            a=vec;
        }
        template<class T>
        poly(T s,T t) {
            //
            a=vector<int>(s,t);
        }
        poly(const poly &x) {
            a=x.a;
        }
        /*----------------------------------------*/
        inline int size() {
            return a.size()-1;
        }
        inline void resize(int x) {
            a.resize(x+1);
        }
        inline int& operator[](int pos) {
            return a[pos];
        }
        inline poly subpoly(int l,int r) {
            //
            return poly(&a[l],&a[r]);
        }
        /*----------------------------------------*/
        //NTT
        inline void NTT() {
            int N=a.size(),len=1;//N=+1
            while(len<N)len<<=1;
            if(N<len) {
                resize(len-1);
            }
            unsigned ll A[len];
            F(i,0,len-1)A[i]=a[i];
            register int j=len>>1;
            for(register int i=1; i<len-1; i++) {
                if (i<j) swap(A[i],A[j]);
                int k=len>>1;
                while (j>=k) {
                    j-=k;
                    k>>=1;
                }
                j+=k;
            }
            for(register int i=2,t=0; i<=len; i<<=1,t++) {
                if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
                for(register int j=0; j<len; j+=i)
                    for(register int k=j; k<j+(i>>1); k++) {
                        unsigned ll u=A[k];
                        unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
                        A[k]=u+v;
                        A[k+(i>>1)]=u-v+mod;
                    }
            }
            F(i,0,len-1)a[i]=A[i]%mod;
        }
        //NTT
        inline void UNTT() {
            int N=a.size(),len=1;//N=+1
            while(len<N)len<<=1;
            if(N<len) {
                resize(len-1);
            }
            unsigned ll A[len];
            F(i,0,len-1)A[i]=a[i];
            register int j=len>>1;
            for(register int i=1; i<len-1; i++) {
                if (i<j) swap(A[i],A[j]);
                int k=len>>1;
                while (j>=k) {
                    j-=k;
                    k>>=1;
                }
                j+=k;
            }
            for(register int i=2,t=0; i<=len; i<<=1,t++) {
                if(t==17)for(register int j=0; j<len; ++j)A[j]%=MOD;
                for(register int j=0; j<len; j+=i)
                    for(register int k=j; k<j+(i>>1); k++) {
                        unsigned ll u=A[k];
                        unsigned ll v=w[t][k-j]*A[k+(i>>1)]%MOD;
                        A[k]=u+v;
                        A[k+(i>>1)]=u-v+mod;
                    }
            }
            reverse(A+1,A+len);
            ll nev=pw(len,MOD-2);
            for(int i=0; i<len; i++) a[i]=(A[i]%MOD)*nev%MOD;
        }
        /*----------------------------------------*/
        //
        inline poly operator+(poly b) {
            register int n=size(),bn=b.size();
            if(n>=bn) {
                poly rt(a);
                for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
                return rt;
            }
            poly rt(b);
            for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]+b.a[i])%mod;
            return rt;
        }
        //
        inline poly operator-(poly b) {
            register int n=size(),bn=b.size();
            if(n>=bn) {
                poly rt(a);
                for(register int i=0; i<=bn; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
                return rt;
            }
            poly rt(bn);
            for(register int i=0; i<=n; ++i)rt.a[i]=(a[i]-b.a[i]+mod)%mod;
            for(register int i=n+1; i<=bn; ++i)rt.a[i]=(mod-b.a[i])%mod;
            return rt;
        }
        //
        inline poly operator-() {
            register int n=size();
            poly rt(n);
            for(register int i=0; i<=n; ++i)rt.a[i]=(mod-a[i])%mod;
            return rt;
        }
        //
        inline poly operator*(poly b) {
            int n=size(),bn=b.size();
            int len=n+bn;
            if(1ll*n*bn<=10000) {
                poly rt(len);
                for(register int i=0; i<=n; ++i) {
                    for(register int j=0; j<=bn; ++j) {
                        rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
                    }
                }
                return rt;
            }
            poly A(a),B(b.a);
            A.resize(len);
            B.resize(len);
            A.NTT();
            B.NTT();
            poly rt(A.size());
            for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
            rt.UNTT();
            rt.resize(len);
            return rt;
        }
        //
        inline poly operator&(poly b) {
            int n=size(),bn=b.size();
            int len=n+bn;
            if(1ll*n*bn<=10000) {
                poly rt(n);
                for(register int i=0; i<=n; ++i) {
                    for(register int j=0; j<=min(bn,n-i); ++j) {
                        rt.a[i+j]=(rt.a[i+j]+1ll*a[i]*b.a[j])%mod;
                    }
                }
                return rt;
            }
            poly A(a),B(b.a);
            A.resize(len);
            B.resize(len);
            A.NTT();
            B.NTT();
            poly rt(A.size());
            for(register int i=0; i<=A.size(); ++i)rt.a[i]=1ll*A.a[i]*B.a[i]%mod;
            rt.UNTT();
            rt.resize(n);
            return rt;
        }
        inline poly rev() {
            poly rt(a);
            reverse(rt.a.begin(),rt.a.end());
            return rt;
        }
        //res[i-j]+=f[i]*g[j]
        inline poly operator^(poly b) {
            poly temp=b.rev();
            temp=(*this)*temp;
            temp.a.erase(temp.a.begin(),temp.a.begin()+b.size());
            return temp;
        }
    } A,B;
}
/*
int n;
int main() {
    NTT_set(1050000);
    cin>>n;
    A.resize(n-1);
    F(i,0,n-1)read(A[i]);
    A=A.exp();
    F(i,0,n-1)write(A[i],' ');
    return 0;
}
*/
ll n,m,a[200002],b[200002],c[200002],d[200002],e[200002],pre[200002],sumd,aa[200002];
inline void cha(ll *v,int len){
    v[0]=0;
    UF(i,len,1)v[i]-=v[i-1];
    UF(i,len,1)v[i]-=v[i-1];
}
inline ll calc(int a,int d){
    return 1ll*a*a+1ll*d*d-2ll*a*d+a-d;
}
inline int v1(int pos){
    return (pos&1)?a[pos]:-a[pos];
}
inline int v2(int pos){
    if(pos&1)return a[pos]-2*a[pos-1];
    return 2*a[pos-1]-a[pos];
}
#define mod1 998244353
#define mod2 1004535809
#undef mod
#define a c
bool vis[200002];
inline void getans(int pos){
    if(!(pos&1))swap(d,e);
    int cnt=0;
    F(i,1,n)if(vis[i])++cnt;
    F(i,3,m){
        if(c[pos+i-1]!=d[i])vis[pos+i-1]=true,++cnt;
    }
    write(cnt,'\n');
    F(i,1,n)if(vis[i])write(i,' ');
    putchar('\n');
}
inline bool dfs(int pos,int z,ll x){
    if(!pos)return z==0&&x==0;
    if(pos&1)return dfs(pos-1,z-1,x-pos)||dfs(pos-1,z,x);
    else return dfs(pos-1,z+1,x+pos)||dfs(pos-1,z,x);
}
inline bool check(int pos,ll x,ll y){
    y=-y;
    ll z=y-x;
    int qwq=(pos+1)>>1,qaq=(pos>>1);
    z+=qaq;
    x+=1ll*qaq*(qaq+1);
    if(z<0||z>pos)return false;
    return 1ll*z*(z+1)/2<=x&&x<=1ll*(pos-z)*z+1ll*z*(z+1)/2;
}
inline bool ok(int pos){
    if(check(pos,b[1]-aa[pos],b[2]-aa[pos+1])){
        ll x=b[1]-aa[pos],y=b[2]-aa[pos+1];//cerr<<pos<<" "<<x<<" "<<y<<endl;
        UF(i,pos,1){
            if(check(i-1,x-((i&1)?i:-i),y-((i&1)?(-i-1):i+1)))vis[pos-i+1]=true,x-=((i&1)?i:-i),y-=((i&1)?(-i-1):i+1);
        }
        return true;
    }
    if(check(pos,b[1]-aa[pos],b[2]-aa[pos+1]-1)){
        vis[pos+1]=true;
        ll x=b[1]-aa[pos],y=b[2]-aa[pos+1]-1;
        UF(i,pos,1){
            if(check(i-1,x-((i&1)?i:-i),y-((i&1)?(-i-1):i+1)))vis[pos-i+1]=true,x-=((i&1)?i:-i),y-=((i&1)?(-i-1):i+1);
        }
        return true;
    }
    return false;
}
inline bool check(ll *d,int tag){
//  F(i,1,n)cerr<<a[i]<<" ";cerr<<"\n";
//  F(i,1,m)cerr<<d[i]<<" ";cerr<<"\n\n";
	d[1]=d[2]=0;
    F(i,1,m)if(llabs(d[i])>9e5)return false;
    sumd=0;
    F(i,1,m)sumd+=1ll*d[i]*d[i]-d[i];
    Poly1::A.resize(n),Poly1::B.resize(m-1);
    Poly2::A.resize(n),Poly2::B.resize(m-1);
    Poly1::A[0]=Poly2::A[0]=0;
    F(i,1,n){
        Poly1::A[i]=((-2*a[i])%mod1+mod1)%mod1;
        Poly2::A[i]=((-2*a[i])%mod2+mod2)%mod2;
    }
    F(i,1,m){
        Poly1::B[i-1]=(d[i]+mod1)%mod1;
        Poly2::B[i-1]=(d[i]+mod2)%mod2;
    }
    Poly1::A=Poly1::A^Poly1::B;
    Poly2::A=Poly2::A^Poly2::B;
    F(i,1,n-m+1){
        Poly1::A[i]=(Poly1::A[i]+pre[i+m-1]-pre[i-1]+sumd)%mod1+mod1;
        Poly2::A[i]=(Poly2::A[i]+pre[i+m-1]-pre[i-1]+sumd)%mod2+mod2;
     //   cerr<<i<<" "<<(Poly1::A[i])%mod1<<endl;
        if((i&1)==tag&&(Poly1::A[i]-calc(a[i],d[1])-calc(a[i+1],d[2]))%mod1==0&&
        (Poly2::A[i]-calc(a[i],d[1])-calc(a[i+1],d[2]))%mod2==0&&ok(i)){
            getans(i);
            return true;
        }
    }
    return false;
}
#undef a
int main() {
    Poly1::NTT_set(1050000);
    Poly2::NTT_set(1050000);
    F(iakioi,1,read()){
        read(n);
        F(i,1,n)vis[i]=false;
        F(i,0,n+1)a[i]=b[i]=c[i]=d[i]=e[i]=0;
        F(i,1,n)read(a[i]),aa[i]=a[i];read(m);
        F(i,1,m)read(b[i]),d[i]=e[i]=b[i];
        for(int i=2;i<=n;i+=2)a[i]=-a[i];
        F(i,1,n)c[i]=a[i];
        cha(c,n);
        F(i,1,m){
            if(i&1)e[i]=-e[i];
            else d[i]=-d[i];
        }
        cha(d,m);
        cha(e,m);
        for(int i=2;i<=n;i+=2)c[i]=-c[i];
        F(i,1,n)pre[i]=c[i]+1ll*c[i]*c[i]+pre[i-1];
        F(i,1,m){
            if(i&1)e[i]=-e[i];
            else d[i]=-d[i];
        }
        if(!check(d,1)){
            if(!check(e,0)){
                puts("-1");
            }
        }
    }
    return 0;
}
/*
20
169 29 105 317 42 93 448 51 491 272 375 359 28 400 36 349 430 46 497 339
18
30 104 318 42 92 451 46 498 263 387 344 46 380 59 324 458 15 532
*/