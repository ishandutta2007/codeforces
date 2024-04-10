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

char a[1005][1005];
int n,m;

bool fre[1005][1005];

void solve(){
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%s",a[i]+1);
        rep(j,1,m)a[i][j]-='0',fre[i][j]=0;
    }
    int block=0;
    queue<pii> q;
    rep(i,1,n){
        rep(j,1,m){
            if(a[i][j]==0)
                fre[i][j]=1,q.push({i,j});
            else
                block++;
        }
    }
    vector<array<int,4>> ans;
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        if(y<m&&!fre[x][y+1]){
            fre[x][y+1]=1;
            block--;
            q.push({x,y+1});
            ans.pb({x,y,x,y+1});
        }
        if(x<n&&!fre[x+1][y]){
            fre[x+1][y]=1;
            block--;
            q.push({x+1,y});
            ans.pb({x,y,x+1,y});
        }
    }
    if(block)puts("-1");
    else{
        print(SZ(ans),'\n');
        reverse(ans.begin(),ans.end());
        for(auto [a,b,c,d]:ans)
            printf("%d %d %d %d\n",a,b,c,d);
    }
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}