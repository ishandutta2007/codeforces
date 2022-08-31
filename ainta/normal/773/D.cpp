#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[2010][2010], Mn = 2e9, chk[2010], cnt;
long long D[2010];
struct point{
    int a, b, c;
    bool operator<(const point &p)const{
        return c<p.c;
    }
}E[2010000];
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            scanf("%d",&w[i][j]);
            w[j][i]=w[i][j];
            Mn = min(Mn, w[i][j]);
        }
        D[i] = 2e9;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j)continue;
            w[i][j]-=Mn;
            if(!w[i][j])D[i]=D[j]=0;
            if(i<j && w[i][j]){
                E[cnt++] = {i,j,w[i][j]};
            }
        }
    }
    sort(E,E+cnt);
    for(i=0;i<cnt;i++){
        D[E[i].a] = min(D[E[i].a],min(E[i].c*2ll, D[E[i].b] + E[i].c));
        D[E[i].b] = min(D[E[i].b],min(E[i].c*2ll, D[E[i].a] + E[i].c));
    }
    for(i=1;i<=n;i++)printf("%lld\n",D[i]+1ll*(n-1)*Mn);
}