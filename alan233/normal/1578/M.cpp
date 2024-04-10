// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

const int N=1005;

char a[N];
int wa[N],n,m;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double get(){
    uniform_real_distribution<double>qwq(0,1);
    return qwq(rng);    
}

int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%s",a+1);
        double p[2];p[0]=p[1]=0.;
        rep(j,1,n)p[a[j]-'0']+=pow(0.8,wa[j]);
        bool ac;
        if(get()<p[0]/(p[0]+p[1]))ac=0;
        else ac=1;
        printf("%d\n",ac),fflush(stdout);
        scanf("%d",&ac);
        rep(j,1,n)if(a[j]-'0'!=ac)wa[j]++;
    } 
    return 0;
}