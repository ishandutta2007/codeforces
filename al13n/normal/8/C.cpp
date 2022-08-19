#pragma comment(linker,"/STACK:256000000")
//#pragma comment(linker,"/STACK:536870912")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <ctime>
using namespace std;

#define lng long long
#define PB push_back
#define pii pair<int,int>
#define MPII make_pair<int,int>
#define PLL pair<lng,lng>
#define MPLL make_pair<lng,lng>
#define PI 3.1415926535897932384626433832795
#define DEG2RAD (PI/180.0)
#define RAD2DEG (1.0/DEG2RAD)
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define forn(i,n) for(int i=0;i<n;++i)
#define forn1(i,n) for(i=0;i<n;++i)
#define forv(i,v) for(int i=0;i<v.size();++i)
#define forvr(i,v) for(int i=v.size()-1;i>=0;--i)
#define fors(i,s) for(int i=0;i<s.length();++i)
#define EPS 1e-10
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)
#define iinf 1000000000
#define linf 4000000000000000000LL
#define maxll ((1LL<<62)-1+(1LL<<62))
#define dinf 10000000000000000000000.0
#define SQ(a) ((a)*(a))
#define SWAP(t,a,b) {t ____tmpasdasdasd=(a);(a)=(b);(b)=____tmpasdasdasd;}
#define left _left
#define y1 asdy1
#define y2 asdy2
#define y0 asdy1
#define abs(a) ((a)<0?-(a):(a))
#define mat _mat

/*
inline lng abs(lng a){
    return a<0?-a:a;
}
void l2sf(lng a,string &r){
    if(a<0){
        r+='-';
        a=-a;
    }
    if(a==0)
        r+='0';
    while(a){
        r+='0'+a%10;
        a/=10;
    }
    reverse(r.begin(),r.end());
}
string l2s(lng a){
    string r;
    l2sf(a,r);
    return r;
}
lng s2l(const string &s){
    lng r=0;
    for(int i=0;i<s.length();++i)
        r=r*10+(s[i]-'0');
    return r;
}
int digits(lng a){
    int r=0;
    while(a){
        ++r;
        a/=10;
    }
    return r;
}
int sumdigits(lng a){
    int r=0;
    while(a){
        r+=a%10;
        a/=10;
    }
    return r;
}
lng gcd(lng a,lng b){
    if(!b)
        return b;
    if(!b)
        return a;
    while(true){
        a%=b;
        if(!a)
            return b;
        b%=a;
        if(!b)
            return a;
    }
}
bool pandigital19(const string &s){
    bool was[10];
    for(int i=1;i<10;++i)
        was[i]=false;
    int left=9;
    for(int i=0;i<s.length();++i){
        if(s[i]=='0')
            continue;
        if(!was[s[i]-'0'])
            --left;
        if(!left)
            return true;
        was[s[i]-'0']=true;
    }
    return false;
}
bool prime(lng a){
    if(a==1)
        return false;
    if(a==2)
        return true;
    if(a%2==0)
        return false;
    for(lng i=3;i*i<=a;i+=2)
        if(a%i==0)
            return false;
    return true;
}
int distinct_prime_factors(int a){
    int r=0;
    for(int i=2;i*i<=a;++i){
        if(a%i==0){
            ++r;
            while(a%i==0)
                a/=i;
        }
    }
    if(a>1)
        ++r;
    return r;
}
int bitcount(int a){
    int r=0;
    while(a){
        if(a%2)
            ++r;
        a/=2;
    }
    return r;
}
void erat(bool *r,int len,vector<int> &v){
    memset(r,1,sizeof(r[0])*len);
    r[0]=r[1]=false;
    for(int i=2;i<len;++i){
        if(!r[i])
            continue;
        v.pb(i);
        for(int j=i+i;j<len;j+=i)
            r[j]=false;
    }
}
lng phi(lng a){
    lng r=a;
    for(lng i=2;i*i<=a;++i){
        if(a%i==0){
            while(a%i==0)
                a/=i;
            r-=r/i;
        }
    }
    if(a>1)
        r-=r/a;
    return r;
}
lng fact(int a){
    lng r=1;
    for(int i=2;i<=a;++i)
        r*=i;
    return r;
}
bool bouncy(int a){
    string s;
    l2sf(a,s);
    string t=s;
    sort(t.begin(),t.end());
    if(s==t)
        return false;
    reverse(t.begin(),t.end());
    if(s==t)
        return false;
    return true;
}
struct ivec2{
    lng x,y;
    ivec2():x(0),y(0){}
    ivec2(lng x,lng y):x(x),y(y){}
    void read(){
        cin>>x>>y;
    }
    lng dot(const ivec2 &b){
        return x*b.x+y*b.y;
    }
    ivec2 cwperp(){
        return ivec2(y,-x);
    }
    ivec2& operator-=(const ivec2 &b){
        x-=b.x;
        y-=b.y;
        return *this;
    }
    ivec2& operator+=(const ivec2 &b){
        x+=b.x;
        y+=b.y;
        return *this;
    }
    ivec2 operator-(const ivec2 &b){
        return ivec2(x-b.x,y-b.y);
    }
};
bool pointintriangle(ivec2 p,ivec2 a,ivec2 b,ivec2 c){
    ivec2 t;
    lng d;

    t=(b-a).cwperp();
    d=t.dot(a);
    if((t.dot(c)-d)*(t.dot(p)-d)<=0)
        return false;

    t=(c-b).cwperp();
    d=t.dot(b);
    if((t.dot(a)-d)*(t.dot(p)-d)<=0)
        return false;

    t=(c-a).cwperp();
    d=t.dot(a);
    if((t.dot(b)-d)*(t.dot(p)-d)<=0)
        return false;

    return true;
}
lng radical(lng a){
    lng r=1;
    for(lng i=2;i*i<=a;++i){
        if(a%i==0){
            r*=i;
            while(a%i==0)
                a/=i;
        }
    }
    if(a>1)
        r*=a;
    return r;
}
bool palindromic(const string &s){
    string t=s;
    reverse(t.begin(),t.end());
    return s==t;
}
bool palindromic(lng a){
    string s;
    l2sf(a,s);
    return palindromic(s);
}
int cntdivisors(lng a){
    int r=0;
    for(lng i=1;i*i<=a;++i){
        if(a%i==0)
            if(i*i==a)
                ++r;
            else
                r+=2;
    }
    return r;
}
lng multmod(lng a,lng p,lng mod){
    lng r=0;
    while(p){
        if(p%2){
            --p;
            r+=a;
            r%=mod;
        }else{
            p/=2;
            a+=a;
            a%=mod;
        }
    }
    return r;
}
lng sumproperdivisors(lng a){
    lng r=1;
    for(lng i=2;i*i<=a;++i){
        if(a%i)
            continue;
        if(i*i==a)
            r+=i;
        else
            r+=i+a/i;
    }
    return r;
}
bool squarefree(lng a){
    for(lng i=2;i*i<=a;++i){
        if(a%i==0){
            a/=i;
            if(a%i==0)
                return false;
        }
    }
    return true;
}
struct frac{
    lng a,b;
    frac(lng a):a(a),b(1){}
    frac(lng a,lng b):a(a),b(b){
        norm();
    }
    frac():a(0),b(1){}
    void readspace(){
        cin>>a>>b;
    }
    void writeslash()const{
        cout<<a<<'/'<<b;
    }
    void writespace()const{
        cout<<a<<' '<<b;
    }
    void writedef()const{
        if(b==1)
            cout<<a;
        else
            writeslash();
    }
    void norm(){
        lng g=gcd(abs(a),abs(b));
        if(b<0)
            g=-g;
        a/=g;
        b/=g;
    }
    bool operator<(const frac &f)const{
        return a*f.b<b*f.a;
    }
    frac operator+(const frac &f)const{
        frac r(a*f.b+b*f.a,b*f.b);
        r.norm();
        return r;
    }
    frac operator-(const frac &f)const{
        frac r(a*f.b-b*f.a,b*f.b);
        r.norm();
        return r;
    }
    frac operator*(const frac &f)const{
        frac r(a*f.a,b*f.b);
        r.norm();
        return r;
    }
    frac operator/(const frac &f)const{
        if(f.a==0){
            exit(1234567);
        }
        frac r(a*f.b,b*f.a);
        if(r.b<0){
            r.b=-r.b;
            r.a=-r.a;
        }
        r.norm();
        return r;
    }
    frac operator-()const{
        return frac(-a,b);
    }
};
lng powmod(lng a,lng p,lng mod){
    lng r=1;
    while(p){
        if(p%2){
            r*=a;
            r%=mod;
            --p;
        }else{
            a*=a;
            a%=mod;
            p/=2;
        }
    }
    return r;
}
lng powsat(lng a,lng p){
    if(!a)
        return 0;
    lng r=1;
    lng t;
    while(p){
        if(p%2){
            t=r*a;
            if(t/a!=r||t>=linf)
                return linf;
            r=t;
            --p;
        }else{
            t=a*a;
            if(t/a!=a||t>=linf)
                return linf;
            a=t;
            p/=2;
        }
    }
    return r;
}
lng mulsat(lng a,lng b){
    lng t=a*b;
    if(t/a!=b||t>=linf)
        return linf;
    return t;
}
lng rootl(lng v,lng p=2){//returns root rounded down to nearest integer
    if(p==1)
        return v;
    lng a=0,b=2000000000;
    while(b>a+1){
        lng k=(a+b)/2;
        if(powsat(k,p)>v)
            b=k;
        else
            a=k;
    }
    return a;
}
lng rootp(lng v,lng p=2){//precise root (returns -1 if no root exists)
    lng t=rootl(v,p);
    if(powsat(t,p)!=v)
        return -1;
    else
        return t;
}
double drand(){
    return ((double)rand())/RAND_MAX;
}
lng gcdex(lng a,lng b,lng &x,lng &y){
    if(!a){
        x=0;
        y=1;
        return b;
    }
    lng x1,y1;
    lng d=gcdex(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
lng invmod(lng a,lng mod){
    lng x,y;
    lng g=gcdex(a,mod,x,y);
    if(g!=1)
        return 0;
    else
        return x;
}
bool square(lng a){
    lng t=(lng)sqrt((double)a);
    return SQ(t)==a||SQ(t+1)==a;
}
//*/

int x0,y0;
int xs[100],ys[100];
int n;
int minl[1<<24];
int last1[1<<24];
int last2[1<<24];
int dist[100][100];
bool pairable[100][100];

int doit(int m,int f=0){
    if(minl[m]!=-1)
        return minl[m];
    if(m==0){
        minl[m]=0;
        last1[m]=last2[m]=-1;
        return 0;
    }
    for(int i=f;i<n;++i){
        if(!pairable[f][i]||!(m&(1<<i)))
            continue;
        int tm=m&~(1<<f)&~(1<<i);
        int tf=f+1;
        if(tm)
            while(!(tm&(1<<tf)))
                ++tf;
        int t=doit(tm,tf)+dist[f+1][i+1]+dist[0][f+1]+dist[0][i+1];
        if(minl[m]==-1||minl[m]>t){
            minl[m]=t;
            last1[m]=f;
            last2[m]=i;
        }
    }
    if(minl[m]==-1)
        exit(1);
    return minl[m];
}

int main(){
#ifdef __TRATATA__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    memset(minl,-1,sizeof(minl));
    cin>>x0>>y0;
    cin>>n;
    forn(i,n)
        cin>>xs[i]>>ys[i];
    forn(i,n){
        dist[i+1][0]=dist[0][i+1]=SQ(xs[i]-x0)+SQ(ys[i]-y0);
        forn(j,n){
            dist[i+1][j+1]=SQ(xs[i]-xs[j])+SQ(ys[i]-ys[j]);
        }
    }
    forn(i,n){
        forn(j,n){
            pairable[i][j]=dist[i+1][j+1]<dist[i+1][0]+dist[j+1][0];
        }
    }
    
    cout<<doit((1<<n)-1,0)<<endl;
    int m=(1<<n)-1;
    cout<<0;
    while(m){
        cout<<' '<<last1[m]+1;
        if(last1[m]!=last2[m])
            cout<<' '<<last2[m]+1;
        cout<<" 0";
        m=m&~(1<<last1[m])&~(1<<last2[m]);
    }

    return 0;
}