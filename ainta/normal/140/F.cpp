#include<cstdio>
#include<algorithm>
#include<map>
#include<cstdlib>
#define pii pair<int,int>
using namespace std;
int n, K;
struct point{
    int x, y;
    bool operator<(const point &p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}w[201000];
map<pii, int>Map;
pii tp[25];
int RC, C[25], TC;
pii res[220];
int main(){
    int i, j, k;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].y);
    }
    if(K>=n){
        printf("-1\n");
        return 0;
    }
    sort(w+1,w+n+1);
    int base = 1e9;
    for(i=1;i<=n && i <= 100;i++){
        for(j=n-i-K+1;j<=n-i+K+1;j++){
            if(j<1||j>n)continue;
            pii t = {w[i].x+w[j].x,w[i].y+w[j].y};
            Map[t]++;
            if(Map[t]==n-K){
                res[++RC] = t;
            }
        }
    }
    if(n>100){
        for(auto it = Map.begin();it!=Map.end();it++){
            if(it->second >= 100 - K){
                tp[++TC] = it->first;
                C[TC] = it->second;
            }
        }
        for(i=101;i<=n;i++){
            for(j=n-i-K+1;j<=n-i+K+1;j++){
                if(j<1||j>n)continue;
                pii t = {w[i].x+w[j].x,w[i].y+w[j].y};
                for(k=1;k<=TC;k++){
                    if(tp[k]==t){
                        C[k]++;
                        if(C[k]==n-K)res[++RC] = tp[k];
                    }
                }
            }
        }
    }
    printf("%d\n",RC);
    for(i=1;i<=RC;i++){
        int x = res[i].first, y = res[i].second;
        if(x<0){printf("-");x=-x;}
        printf("%d.%d ",x/2,x%2*5);
        if(y<0){printf("-");y=-y;}
        printf("%d.%d\n",y/2,y%2*5);
    }
}