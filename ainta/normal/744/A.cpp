#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1010];
int n, m, K, SZ[1010], UF[1010], w[1010], C[1010], Res;
bool v[1010];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a] = Find(UF[a]);
}
void Merge(int a, int b){
    a = Find(a), b = Find(b);
    if(a!=b){
        UF[a] = b;
        SZ[b] += SZ[a];
    }
}
int main(){
    int i, a, b;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++){
        SZ[i] = 1;
        UF[i] = i;
    }
    for(i=0;i<K;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        Merge(a,b);
    }
    for(i=0;i<K;i++){
        C[i] = SZ[Find(w[i])];
        v[Find(w[i])] = true;
    }
    sort(C,C+K);
    for(i=1;i<=n;i++){
        if(v[Find(i)])continue;
        v[Find(i)] = true;
        C[K-1] += SZ[Find(i)];
    }
    Res = -m;
    for(i=0;i<K;i++){
        Res += C[i]*(C[i]-1)/2;
    }
    printf("%d\n",Res);
}