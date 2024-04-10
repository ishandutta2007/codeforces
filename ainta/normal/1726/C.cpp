#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
 
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned ll;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N_ 201000
int S[N_], vis[N_], st[N_];
vi E[N_];
char p[N_];
vi G[N_*2];

int n;

void add_edge(int a, int b){
    if(a<0||a>n||b<0||b>n)return;
    //printf("%d %d\n",a,b);
    E[a].pb(b);
    E[b].pb(a);
}
void DFS(int a){
    vis[a]=1;
    for(auto &x: E[a]){
        if(!vis[x]){
            DFS(x);
        }
    }
}
int Mat[N_];

void Solve(){
    scanf("%d",&n);
    n*=2;
    scanf("%s",p);
    rep(i,n){
        S[i+1]=S[i];
        if(p[i]=='(')S[i+1]++;
        else S[i+1]--;
    }
    rng(i,0,n)E[i].clear();
    int top = 0;
    rng(i,0,n)Mat[i]=0;
    rep(i,n){
        if(p[i]=='(')st[++top] = i;
        else{
            int x = st[top];
            top--;
            Mat[x+1] = i+1;
            Mat[i+1] = x+1;
        }
    }
    rng(i,1,n){
        if(i < Mat[i]){
            add_edge(i,Mat[i]);
            if(i>1 && i-1 > Mat[i-1]){
                add_edge(i,i-1);
            }
        }
    }
    rng(i,1,n)vis[i]=0;
    int cnt = 0;
    rng(i,1,n){
        if(vis[i])continue;
        cnt++;
        DFS(i);
    }
    printf("%d\n",cnt);

}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}