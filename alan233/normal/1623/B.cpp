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

const int N=1005;

struct node{
    int l,r;
    friend bool operator < (const node&x,const node&y){
        return x.l!=y.l?x.l<y.l:x.r>y.r;
    }
}a[N];
int stk[N],top;
int n;

vector<int>adj[N];

void dfs(int u){
    if(!SZ(adj[u])){
        printf("%d %d %d\n",a[u].l,a[u].r,a[u].l);
        return ;
    }
    if(SZ(adj[u])==1){
        if(a[adj[u][0]].l==a[u].l){
            printf("%d %d %d\n",a[u].l,a[u].r,a[u].r);
            dfs(adj[u][0]);
        }else{
            printf("%d %d %d\n",a[u].l,a[u].r,a[u].l);
            dfs(adj[u][0]);
        }
    }else{
        if(a[adj[u][0]].l>a[adj[u][1]].l)swap(adj[u][0],adj[u][1]);
        printf("%d %d %d\n",a[u].l,a[u].r,a[adj[u][0]].r+1);
        dfs(adj[u][0]);
        dfs(adj[u][1]);
    }
}

void solve(){
    n=read();
    rep(i,1,n)a[i].l=read(),a[i].r=read();
    sort(a+1,a+n+1);
    
//    puts("!!!");
//    rep(i,1,n)printf("%d %d\n",a[i].l,a[i].r);
//    puts("---");
    
    stk[top=1]=1;
    rep(i,1,n)adj[i].clear();
    rep(i,2,n){
        while(top&&a[stk[top]].r<a[i].r)top--;
        adj[stk[top]].pb(i);
        stk[++top]=i;
    }
    dfs(1);
    puts("");
}

int main(){
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}