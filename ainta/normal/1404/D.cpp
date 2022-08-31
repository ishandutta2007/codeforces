#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 1010000
#define pii pair<int,int>
using namespace std;
int w[N_], chk[N_], vv[N_], vis[N_];
struct AA{
    int a, b;
}U[N_];
vector<pii>E[N_];
int main(){
    int n, i;
    scanf("%d",&n);
    if(n%2==0){
        printf("First\n");
        fflush(stdout);
        for(i=1;i<=2*n;i++){
            int x = i;
            if(x>n)x-=n;
            printf("%d ",x);
        }
        puts("");
        fflush(stdout);
        int r;
        scanf("%d",&r);
        return 0;
    }
    printf("Second\n");
    fflush(stdout);
    for(i=1;i<=2*n;i++){
        scanf("%d",&w[i]);
        if(!U[w[i]].a)U[w[i]].a=i;
        else U[w[i]].b=i;
    }
    for(i=1;i<=n;i++){
        if(U[i].a%n == U[i].b%n){
            chk[U[i].a]=1;
            continue;
        }
        int x = U[i].a%n, y = U[i].b%n;
        E[x].push_back({y,i});
        E[y].push_back({x,i});
    }
    for(i=0;i<n;i++){
        if(E[i].empty())continue;
        if(vis[i])continue;
        int x = i;
        while(1){
            vis[x]=1;
            int a = -1;
            for(auto &t : E[x]){
                if(!vv[t.second]){
                    a = t.first;
                    AA bb = U[t.second];
                    if(bb.a%n == x){
                        chk[bb.a]=1;
                    }
                    else{
                        chk[bb.b]=1;
                    }
                    vv[t.second]=1;
                    break;
                }
            }
            if(a==-1)break;
            x = a;
        }
    }
    long long s=0;
    for(i=1;i<=2*n;i++){
        if(chk[i])s+=i;
    }
    if(s%(2*n)){
        for(i=1;i<=2*n;i++)chk[i]=1-chk[i];
    }
    for(i=1;i<=2*n;i++)if(chk[i])printf("%d ",i);
    puts("");
    fflush(stdout);
}