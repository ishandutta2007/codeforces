#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 301000
using namespace std;
int w[N_], H[N_], n;
vector<int>E[N_], Ch[N_];
long long U[N_], D[N_];
void DFS(int a, int pp){
    for(auto &x : E[a]){
        if(x==pp)continue;
        DFS(x,a);
        Ch[a].push_back(x);
    }
    if(Ch[a].empty()){
        U[a]=D[a]=0ll;
        return;
    }
    int i;
    long long s=0;
    int c1=0,c2=0,c3=0;
    vector<long long>V;
    for(auto &x : Ch[a]){
        if(H[x]==H[a]){
            c3++;
            s += U[x];
            V.push_back(D[x]-U[x]);
        }
        else{
            if(H[x]<H[a])s += U[x], c1++;
            else s += D[x], c2++;
        }
    }
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    for(i=0;i<=c3;i++){
        int t1 = c1 + c3 - i;
        int t2 = c2 + i;

        long long ss = s + 1ll * min(t1,t2) * w[a];
        long long  su = ss, sd = ss;
        if(pp==0){
            D[a]=max(D[a],ss);
            U[a]=max(U[a],ss);
        }
        else{
            if(t1>t2 && H[a]<=H[pp]){
                su+=w[a];
            }
            if(t2>t1 && H[a]>=H[pp]){
                sd+=w[a];
            }
            if(H[a]<=H[pp])U[a]=max(U[a],su);
            if(H[a]>=H[pp])D[a]=max(D[a],sd);
        }

        if(i==c3)break;
        s+=V[i];
    }

}
int main(){
    int i;
    scanf("%d",&n);
    long long sum=0;
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&H[i]);
    }
    for(i=1;i<n;i++){
        int a, b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
        sum+=w[a],sum+=w[b];
    }
    DFS(1,0);
    printf("%lld\n",sum - max(D[1],U[1]));
}