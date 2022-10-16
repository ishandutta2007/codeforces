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

const int N=1505;

int a[N][N],row[N],col[N];
ll ans;
pii POS[N*N];
int n;

int main(){
    n=read();
    rep(i,1,n)
        rep(j,1,n){
            a[i][j]=read();
            POS[a[i][j]]={i,j};
        }
    rep(i,1,n*n){
        int r=POS[i].fir,c=POS[i].sec;
        ans+=1ll*row[r]*(n-1-col[c])+1ll*col[c]*(n-1-row[r]);
        row[r]++,col[c]++;
    }
    print(ans/2,'\n');
    return 0;
}