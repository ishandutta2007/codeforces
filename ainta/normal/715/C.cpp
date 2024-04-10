#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n, M, Q[101000], D[101000], C[101000];
int par[101000];
int chk[101000], tail, head;
long long po[101000], D1[101000], D2[101000], Inv[101000];
vector<int>E[101000], L[101000];
map<int,int>Map2, Map;
bool v[101000];
void BFS(int a){
    int i, x, y;
    head = tail = 0;
    Q[++tail] = a;
    v[a]=true;
    D[1]=0;
    D1[1]=D2[1]=0;
    while(head<tail){
        x = Q[++head];
        for(i=0;i<E[x].size();i++){
            y = E[x][i];
            if(v[y]||chk[y])continue;
            Q[++tail] = y;
            v[y]=true;
            par[tail] = head;
            D[tail] = D[head]+1;
            D1[tail] = (D1[head]*10 + L[x][i])%M;
            D2[tail] = (D2[head] + L[x][i]*po[D[head]])%M;
        }
    }
}
void init(){
    int i;
    for(i=1;i<=tail;i++){
        v[Q[i]]=false;
    }
}
int get_mid(){
    int i, MM = tail+1, x = 0;
    for(i=1;i<=tail;i++)C[i]=0;
    for(i=tail;i>=1;i--){
        C[i]++;
        if(C[i]*2>=tail && MM>C[i])MM=C[i],x=Q[i];
        C[par[i]]+=C[i];
    }
    return x;
}
long long res;
void Do(int nd){
    BFS(nd);
    if(tail == 1){
        init();
        return;
    }
    int m = get_mid(), i, j;
    init();
    chk[m]=true;
    for(i=0;i<E[m].size();i++){
        if(!chk[E[m][i]]){
            Do(E[m][i]);
        }
    }
    Map.clear();
    Map2.clear();
    for(i=0;i<E[m].size();i++){
        if(!chk[E[m][i]]){
            BFS(E[m][i]);
            for(j=1;j<=tail;j++){
                D2[j]=(D2[j]*10+L[m][i])%M;
                D1[j]=(D1[j]+1*po[D[j]]*L[m][i])%M;
                D[j]++;
                if(!D1[j])res++;
                if(!D2[j])res++;
                res += Map[(M-D1[j])*Inv[D[j]]%M];
                res += Map2[D2[j]];
            }
            for(j=1;j<=tail;j++){
                Map[D2[j]]++;
                Map2[(M-D1[j])*Inv[D[j]]%M]++;
            }
            init();
        }
    }
    chk[m]=false;
}
long long GetInv(int t){
    int i,phi=M, tp = M;
    for(i=2;i*i<=tp;i++){
        if(tp%i==0){
            phi=phi/i*(i-1);
            while(tp%i==0)tp/=i;
        }
    }
    if(tp!=1){
        phi=phi/tp*(tp-1);
    }
    phi--;
    long long rr = 1, aa = t;
    while(phi){
        if(phi&1)rr=rr*aa%M;
        aa=aa*aa%M;phi/=2;
    }
    return rr;
}
int main(){
    int i, a, b, c;
    scanf("%d%d",&n,&M);
    if(M==1){
        printf("%lld\n",1ll*n*(n-1));
        return 0;
    }
    Inv[1] = GetInv(10);
    Inv[0] = 1;
    for(i=2;i<=n;i++)Inv[i]=1ll*Inv[i-1]*Inv[1]%M;
    po[0]=1;
    for(i=1;i<=n;i++)po[i]=10ll*po[i-1]%M;
    for(i=0;i<n-1;i++){
        scanf("%d%d%d",&a,&b,&c);
        a++;
        b++;
        E[a].push_back(b);
        L[a].push_back(c);
        E[b].push_back(a);
        L[b].push_back(c);
    }
    Do(1);
    printf("%lld\n",res);
}