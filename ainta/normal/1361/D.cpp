#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<vector>
#include<cmath>
#define N_ 501000
using namespace std;
struct point{
    int x, y;
    bool operator <(const point &p)const{
        if((x>0||(x==0&&y>0)) != (p.x>0||(p.x==0&&p.y>0))) return (x>0||(x==0&&y>0));
        if(1ll*y*p.x != 1ll*p.y*x)return 1ll*y*p.x < 1ll*p.y*x;
        return 1ll*x*x+1ll*y*y<1ll*p.x*p.x+1ll*p.y*p.y;
    }
}w[501000];
int n, K;
vector<int>E[N_];
vector<double>L[N_];
void Add_Edge(int a, int b){
    double dx = w[a].x-w[b].x , dy = w[a].y-w[b].y;
    double d = sqrt(dx*dx+dy*dy);
    E[a].push_back(b);
    E[b].push_back(a);
    L[a].push_back(d);
    L[b].push_back(d);
}
double pL[N_];
int par[N_];
double T[N_], S[N_], S2[N_];
vector<double>R;
void Do(int a){
    int x=a;
    int cnt=0;
    while(x!=1){
        T[++cnt]=pL[x];
        x=par[x];
    }
    reverse(T+1,T+cnt+1);
    int i;
    for(i=1;i<=cnt;i++){
        S[i]=S[i-1]+T[i];
    }
    for(i=1;i<=K/2 && i<=cnt;i++){
        R.push_back(S[cnt-i+1]*(K-i*2+1));
    }
    if(K%2==0){
        double s=0;
        for(i=K/2+1;i<=cnt;i++){
            int t = i-K/2;
            s+=T[t];
            s+=S[t-1]*2;
            R.push_back(-s);
        }
    }
    else{
        double s=0;
        for(i=K/2+1;i<=cnt;i++){
            int t =i-K/2;
            s+=S[t-1]*2;
            R.push_back(-s);
        }
    }
}
void DFS(int a, int pp){
    int ck=0;
    for(int i=0;i<E[a].size();i++){
        int x = E[a][i];
        if(pp==x)continue;
        pL[x] = L[a][i];
        par[x] = a;
        DFS(x,a);
        ck=1;
    }
    if(!ck){
        Do(a);
    }
}
int main(){
    int i, c=1;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x||y)w[++c]={x,y};
    }
    sort(w+2,w+n+1);
    for(i=2;i<=n;i++){
        if(i==2 ||(w[i-1].x>0||(w[i-1].x==0&&w[i-1].y>0)) != (w[i].x>0||(w[i].x==0&&w[i].y>0)) || 1ll*w[i-1].x*w[i].y!=1ll*w[i-1].y*w[i].x){
            Add_Edge(1,i);
        }
        else{
            Add_Edge(i-1,i);
        }
    }
    DFS(1,0);
    R.push_back(0);
    sort(R.begin(),R.end());
    reverse(R.begin(),R.end());
    double res=0.0;
    for(i=0;i<K;i++)res+=R[i];
    printf("%.10f\n",res);
}