#include<bits/stdc++.h>
#define ll long long
#define N 250015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int n,m;
VI V[N],P,tmp;
int check(VI a,VI b){
    int cnt = 0;
    rep(i,1,m) cnt += (a[i] != b[i]);
    return cnt;
}
bool check(){
    rep(i,1,n){
        int val = check(tmp,V[i]);
        if(val > 3) return 0;
        if(val == 3){
            bool flag = 0;
            rep(j,1,m){
                if(tmp[j]==-1) tmp[j] = V[i][j],flag = 1;
            }
            if(!flag) return 0;
        }
    }
    return 1;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
    tmp.resize(m+1);
    rep(i,1,n){
        V[i].pb(-114514);
        rep(j,1,m){int x; scanf("%d",&x); V[i].pb(x);}
    }
    int pos,dif = 0;
    rep(i,2,n){
        int d = check(V[1],V[i]);
        if(d >= dif) dif = d,pos = i;
    }
    // printf("%d %d\n",dif,pos);
    if(dif <= 2){
        puts("Yes");
        rep(i,1,m) printf("%d ",V[1][i]);
        return 0;
    }
    if(dif > 4) return puts("No"),0;
    rep(i,1,m) if(V[1][i] != V[pos][i]) P.pb(i);
    for(auto u:P) for(auto v:P){
        if(u == v) continue;
        rep(i,1,m) tmp[i] = V[1][i];
        tmp[u] = V[pos][u]; tmp[v] = -1;
        if(check()){
            puts("Yes");
            rep(i,1,m) printf("%d ",tmp[i]!=-1?tmp[i]:114514);
            return 0;
        }
    }
    puts("No");
    return 0;
}