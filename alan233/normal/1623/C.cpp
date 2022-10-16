#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
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
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=200005;
ll a[N],b[N];int n;

bool check(int lim){
    rep(i,1,n)b[i]=a[i];
    per(i,n,3){
        if(b[i]<lim)return false;
        ll rem=(b[i]-lim)/3;
        ckmin(rem,a[i]/3);
        b[i-1]+=rem,b[i-2]+=2*rem;
    }
    if(b[1]<lim||b[2]<lim)return false;
    else return true;
}

void solve(){
    n=read();
    rep(i,1,n)a[i]=read();
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid))l=mid;else r=mid-1;
    }    
    printf("%d\n",l);
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}