#include<cstdio>
#include<algorithm>
#include<ctime>
#include<vector>
#include<queue>
using namespace std;
const int N=1003,P=998244353;
vector<int> nxt[N],rk;
long long a[N];
int n,m,t,in[N];
bool check(){
    for(int i=1;i<=n;i++){
        if(!a[i]) continue;
        for(auto v:nxt[i])
            if(!a[v]) return true;
    }
    return false;
}
int main(){
    // int tt=clock();
    scanf("%d",&t);
    // t=10;
    while(t--){
        scanf("%d%d",&n,&m);
        // n=1000; m=n-1;
        for(int i=1;i<=n;i++){
            nxt[i].clear();
            in[i]=0;
            scanf("%lld",a+i);
            // if(i==1) a[i]=10000;
            // else a[i]=0;
        }
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            // u=i,v=i+1;
            nxt[u].push_back(v);
            ++in[v];
        }
        rk.clear();
        queue<int> qu;
        for(int i=1;i<=n;i++)
            if(in[i]==0) qu.push(i);
        while(!qu.empty()){
            int u=qu.front(); qu.pop();
            rk.push_back(u);
            for(auto v:nxt[u])
                if(--in[v]==0)qu.push(v);
        }
        int ans=0;
        reverse(begin(rk),end(rk));
        while(check()){
            ++ans;
            for(auto u:rk){
                if(a[u]<=0) continue;
                --a[u];
                for(auto v:nxt[u])
                    ++a[v];
            }
        }
        reverse(begin(rk),end(rk));
        int tmp=0;
        for(auto u:rk){
            tmp=(a[u]%=P);
            for(auto v:nxt[u])
                a[v]+=a[u];
        }
        printf("%d\n",(ans+tmp)%P);
    }   
    // printf("# %ld\n",clock()-tt);
    return 0;
}