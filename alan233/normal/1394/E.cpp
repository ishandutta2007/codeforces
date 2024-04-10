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

const int N=100005;

unordered_map<int,int>mem[N],vis[N];
vector<int>pre[N],suf[N];
int a[N],n,cntZ;

int dp(int l,int r){
    if(l>r)return 0;
    if(mem[r].count(l))return mem[r][l];
    for(auto len:suf[r]){
        if(r-2*len+1>=l)return mem[r][l]=dp(l,r-len)+1;
        else break;
    }    
    for(auto len:pre[l]){
        if(l+2*len-1<=r)return mem[r][l]=dp(l+len,r)+1;
        else break;
    }
    return mem[r][l]=0;
}

int main(){
    int T=read();
    while(T--){
        int x=read();a[++n]=x;
        if(a[n-1]==x)suf[n].pb(1),vis[n][1]=1;
        for(auto len:suf[n-1])if(a[n-1-2*len]==a[n])suf[n].pb(len+1),vis[n][len+1]=1;
        for(auto len:suf[n])pre[n-2*len+1].pb(len);
        int Z=0;
        for(auto len:suf[n])if(vis[n-len][len]){Z=len;break;}
        if(Z){
            cntZ++;
            rep(i,1,2*Z){
                for(auto len:suf[n])pre[n-2*len+1].pop_back();
                vis[n].clear(),suf[n].clear(),mem[n].clear();
                n--;
            }
        }
        print(2*cntZ+dp(1,n),' ');
    }
    return 0;
}