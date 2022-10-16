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

const int N=100005;

vector<array<int,3>> task[N];
int a[N];
int n,m;

int dp[N][205];
pii f[N][205];

void solve(){
    // memset(dp,0x3f,sizeof(dp));
    n=read(),m=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n)task[i].clear();
    rep(i,1,m){
        int e=read(),t=read(),p=read();
        task[e].pb({p,t,i});
    }
    vector<int> ans;
    int bef=0;
    rep(i,1,n){
        int turns=0;
        dp[0][0]=0;
        for(auto [p,t,id]:task[i]){
            turns++;
            rep(j,p,200){
                if(dp[turns-1][j-p]+t<=dp[turns][j])
                    dp[turns][j]=dp[turns-1][j-p]+t,f[turns][j]={p,id};
            }
            rep(j,0,200){
                if(dp[turns-1][j]<=dp[turns][j])
                    dp[turns][j]=dp[turns-1][j],f[turns][j]={0,0};
            }
        }
        int t=min_element(dp[turns]+100,dp[turns]+200)-dp[turns];
        // printf("when i=%d,dp=%d\n",i,dp[turns][t]);
        if(dp[turns][t]>a[i]-bef){
            puts("-1");
            rep(j,0,turns)memset(dp[j],0x3f,sizeof(dp[j]));
            return;
        }
        bef+=dp[turns][t];
        int tmp=turns;

        vector<int> zz;
        while(turns){
            if(f[turns][t].sec)zz.pb(f[turns][t].sec);
            t-=f[turns][t].fir,turns--;
        }

        reverse(zz.begin(),zz.end());
        for(auto it:zz)ans.pb(it);

        rep(j,0,tmp+1)memset(dp[j],0x3f,sizeof(dp[j]));
    }
    printf("%d\n",SZ(ans));
    for(auto it:ans)printf("%d ",it);puts("");
}

int main(){
    memset(dp,0x3f,sizeof(dp));
    int T=read();
    while(T--)solve();
    return 0;
}