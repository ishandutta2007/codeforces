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

const int N=2000005;

bool ban[2][N];
int f[2][N],g[2][N];
int a[N],b[N],tmp[N],len;
int n,m1,m2,t;

int main(){
    // freopen("cell.in","r",stdin);
    // freopen("cell.out","w",stdout);
    scanf("%d%d%d%d",&n,&m1,&m2,&t);
    rep(i,1,m1)scanf("%d",&a[i]),tmp[++len]=a[i],tmp[++len]=a[i]+1;
    rep(i,1,m2)scanf("%d",&b[i]),tmp[++len]=b[i],tmp[++len]=b[i]+1;
    tmp[++len]=0,tmp[++len]=n+1;
    sort(tmp+1,tmp+len+1),len=unique(tmp+1,tmp+len+1)-tmp-1;
    rep(i,1,m1){
        int t=lower_bound(tmp+1,tmp+len+1,a[i])-tmp;
        ban[0][t]=1;
    }
    rep(i,1,m2){
        int t=lower_bound(tmp+1,tmp+len+1,b[i])-tmp;
        ban[1][t]=1;
    }
    memset(f,-1,sizeof(f));
    f[0][1]=f[1][1]=0,g[1][1]=1;
    rep(i,1,len){
        rep(j,0,1)
            if(f[j][i]!=-1&&!ban[j^1][i])
                if(ckmax(f[j^1][i],min(f[j][i],t)))
                    g[j^1][i]=1;
        rep(j,0,1)
            if(f[j][i]!=-1&&f[j][i]+tmp[i+1]-tmp[i]-1>=t*ban[j][i+1])
                if(ckmax(f[j][i+1],f[j][i]+tmp[i+1]-tmp[i]-t*ban[j][i+1]))
                    g[j][i+1]=0;
    }
    int ansx=f[1][len]>=f[0][len],ansy=len;
    if(!~f[ansx][ansy])return puts("No"),0;
    puts("Yes");
    vector<int> ans1;
    vector<pii> ans2;
    int last=2e9;
    while(ansx||ansy>1){
        if(g[ansx][ansy]==1){
            ans1.pb(tmp[ansy]);
            ansx^=1;
        }else{
            if(ban[ansx][ansy]){
                last=min(last-t,tmp[ansy]-1);
                ans2.pb({last,ansx});
            }
            ansy--;
        }
    }
    reverse(ans1.begin(),ans1.end()),reverse(ans2.begin(),ans2.end());
    printf("%d\n",SZ(ans1));for(auto it:ans1)printf("%d ",it);puts("");
    printf("%d\n",SZ(ans2));for(auto [u,v]:ans2)printf("%d %d\n",u,v+1);
    return 0;
}