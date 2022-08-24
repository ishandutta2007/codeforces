#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<vector<int>,int>Map;

long long Comb[110][110], F[110], Mod = 1000000007, PO[110][110];
int vis[110], w[110];

long long Go(vector<int> T);

int C[50]={0}, ss = 0;

vector<int>ZZ;
void DFS(int pv, vector<vector<int>>&GG, long long t){
    if(pv==ss+1){
        ZZ.push_back(t);
        GG.push_back(ZZ);
        ZZ.pop_back();
        return;
    }
    DFS(pv+1,GG,t);
    for(int i=1;i<=C[pv];i++){
        ZZ.push_back(pv);
        DFS(pv+1,GG,t*Comb[C[pv]][i]%Mod);
    }
    for(int i=1;i<=C[pv];i++)ZZ.pop_back();
}

long long Pow(long long a, long long b){
    long long r=1;
    while(b){
        if(b&1)r=r*a%Mod;
        a=a*a%Mod;b>>=1;
    }
    return r;
}

long long Go(vector<int> T){
    if(T.empty())return 1;
    if(Map.count(T))return Map[T];
    //printf("in\n");
    vector<vector<int>>VV;
    for(int i=0;i<=40;i++)C[i]=0;
    ss=0;
    int n  =0;
    for(auto &t : T){
        C[t]++;
        ss=max(ss,t);
        n+=t;
    }
    DFS(0,VV,1);

    long long ans  = 0;
    for(auto &t : VV){
        if(t.size()==T.size()+1)continue;
        vector<int>t2 = t;
        long long ccc = t2.back();
        t2.pop_back();
        int z = n;
        int ck=1;
        if(T.size()%2==0)ck=-1;
        for(auto &u : t2){
            z-=u;
            ck=-ck;
        }
        long long r = Go(t2);
        //printf("%d\n",ck);
        //printf("sub ");
       // for(auto &u : t)printf("%d ",u);
       // printf(": %lld ",r);
        long long ttt = Comb[n][z]*F[z]%Mod;
        ttt = Pow(ttt,n-z)*Pow(F[n-1],z)%Mod;
        long long tot = r%Mod * ttt%Mod*ccc%Mod;
        //printf(": %lld\n",tot);
        //rintf("%d %d\n",ck,t2.size());
        ans = (ans + tot*ck + Mod)%Mod;
    }
    Map[T]=ans;
    //printf("out\n");

    //printf("hey ");
    //for(auto &t : T)printf("%d ",t);
    //puts("");
    //printf("%lld\n",ans);
    return ans;
}
void Solve(){
    int n, i;
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    vector<int>T;
    for(i=1;i<=n;i++){
        if(vis[i])continue;
        int a = i, c=0;
        while(1){
            vis[a]=1;
            c++;
            a=w[a];
            if(a==i)break;
        }
        T.push_back(c);
    }
    sort(T.begin(),T.end());
    printf("%lld\n",Go(T));
}
int main(){
    int TC = 1, i, j;
    for(i=0;i<=100;i++){
        Comb[i][0]=1;
        for(j=1;j<=i;j++){
            Comb[i][j]=(Comb[i-1][j-1]+Comb[i-1][j])%Mod;
        }
    }
    for(i=0;i<=100;i++){
        PO[i][0]=1;
        for(j=1;j<=100;j++){
            PO[i][j]=PO[i][j-1]*i%Mod;
        }
    }
    F[0]=1;
    for(i=1;i<=100;i++)F[i]=F[i-1]*i%Mod;
    //po[0]=1;
    //for(i=1;i<=1000000;i++)po[i]=po[i-1]*2%Mod;
    while(TC--){
        Solve();
    }
}