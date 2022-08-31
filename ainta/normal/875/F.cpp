#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, SZ[201000], UF[201000];
long long res;
struct point{
    int a, b, c;
    bool operator <(const point &p)const{
        return c<p.c;
    }
}w[201000];
int Find(int a){
    if(a==UF[a])return a;
    return UF[a] = Find(UF[a]);
}
int main(){
    int i, a, b;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].c);
    }
    sort(w,w+m);
    for(i=1;i<=n;i++)UF[i]=i,SZ[i]=1;
    for(i=m-1;i>=0;i--){
        a = Find(w[i].a), b = Find(w[i].b);
        if(SZ[a]+SZ[b]==0)continue;
        res += w[i].c;
        if(a==b){
            SZ[a]--;
        }
        else{
            UF[b] = a;
            SZ[a] += SZ[b]-1;
        }
    }
    printf("%lld\n",res);
}