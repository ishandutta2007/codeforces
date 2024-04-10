// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

int n;

int ask(int x){
    printf("? %d\n",x),fflush(stdout);
    int y;scanf("%d",&y);if(y==0)return (int)1e9;else return y;
}

int main(){
    scanf("%d",&n);
    int l=1,r=2000*n;
    while(l<r){
        int mid=l+r>>1;
        if(ask(mid)==1)r=mid;
        else l=mid+1;
    }
    int S=l;
    ll ans=S;
    for(int h=2;h<=n;h++){
        int t=S/h;
        ckmin(ans,(ll)ask(t)*t);
    }
    printf("! %lld\n",ans),fflush(stdout);
    return 0;
}