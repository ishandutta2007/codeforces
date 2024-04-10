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

const int N=105;
set<pii> s;
int n,a[N][N];

int main(){
    n=read();
    rep(i,1,n){
        rep(j,1,n)a[i][read()]++;
        rep(j,1,n)if(a[i][j]>=2)s.insert({i,j});
    }
    vector<vector<int>> ans;
    while(!s.empty()){
        int pos=s.begin()->fir;
        // printf("now pos=%d\n",pos);
        // for(auto it:s)printf("(%d,%d) ",it.fir,it.sec);puts("");
        vector<int> tmp(n);
        rep(i,0,n-1){
            auto it=s.lower_bound({pos,0});
            assert(it->fir==pos);
            int val=it->sec;
            // printf("i=%d,pos=%d,val=%d\n",i,pos,val);
            tmp[pos-1]=val;
            if(--a[pos][val]==1)s.erase({pos,val});
            pos=pos%n+1;
            if(++a[pos][val]==2)s.insert({pos,val});
        }
        ans.pb(tmp);
    }
    printf("%d\n",SZ(ans)+n*(n-1)/2);
    for(auto &arr:ans){
        for(auto &it:arr)printf("%d ",it);puts("");
    }
    for(int i=2;i<=n;i++){
        int hd=n+2-i;
        for(int j=1;j<=n+1-i;j++){
            int now=hd;
            if(hd==1)hd=n;
            else hd--;
            for(int k=1;k<=n;k++){
                printf("%d ",now);
                now=now%n+1;
            }
            puts("");
        }
    }
    return 0;
}