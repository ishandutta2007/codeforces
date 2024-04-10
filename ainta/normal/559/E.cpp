#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
struct Order{
    int num, x;
    bool operator<(const Order &p)const{
        return x<p.x;
    }
}ord[410];
struct A{
    int b, e, x;
    bool operator <(const A &p)const{
        return x<p.x;
    }
}w[210];
int X[410], L[410], D[110][110][410], DP[110][410];
int main(){
    int i, a, b, cnt = 0, j, k, l, e, t;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        w[i].x = w[i+n].x = a;
        ord[i].num = i, ord[i].x = a-b;
        ord[i+n].num = i+n, ord[i+n].x = a;
        ord[i+n*2].num = i+n*2, ord[i+n*2].x = a;
        ord[i+n*3].num = i+n*3, ord[i+n*3].x = a+b;
    }
    sort(ord+1,ord+n*4+1);
    for(i=1;i<=n*4;i++){
        if(i == 1 || ord[i].x != ord[i-1].x){
            cnt++;
            X[cnt] = ord[i].x;
        }
        if(ord[i].num <= n) w[ord[i].num].b = cnt;
        else if(ord[i].num <= n*2) w[ord[i].num - n].e = cnt;
        else if(ord[i].num <= n*3) w[ord[i].num - n].b = cnt;
        else if(ord[i].num <= n*4) w[ord[i].num - n*2].e = cnt;
    }
    sort(w+1,w+n+1);
    sort(w+n+1,w+n+n+1);
    for(i=1;i<=n;i++){
        D[i][i][w[i].b] = w[i].e;
        D[i][i][w[n+i].b] = w[n+i].e;
        for(j=1;j<=w[i].e;j++)D[i][i][j] = max(D[i][i][j],D[i][i][j-1]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            b = j, e = i + j;
            for(k=b;k<=e;k++){
                if(w[b].e < w[k].b)continue;
                if(k == b){
                    D[b][e][w[k].b] = max(D[b][e][w[k].b], D[b+1][e][w[k].e]);
                    t = w[k+n].e;
                    for(l=k+1;l<=e;l++){
                        if(t >= w[l].e) t = max(t, w[l+n].e);
                        else break;
                    }
                    if(l == e+1) D[b][e][w[k].e] = max(D[b][e][w[k].e], t);
                    else D[b][e][w[k].e] = max(D[b][e][w[k].e], D[l][e][t]);
                }
                else{
                    t = 0;
                    for(l=b;l<k;l++) t = max(t, w[l+n].e);
                    t = max(t, w[k].e);
                    if(k == e){
                        D[b][e][w[k].b] = max(D[b][e][w[k].b], t);
                    }
                    else{
                        for(l=k+1;l<=e;l++){
                            if(t >= w[l].e)t = max(t, w[l+n].e);
                            else break;
                        }
                        if(l == e+1) D[b][e][w[k].b] = max(D[b][e][w[k].b], t);
                        else D[b][e][w[k].b] = max(D[b][e][w[k].b], D[l][e][t]);
                    }
                }
            }
            for(k=1;k<=w[b].e;k++)D[b][e][k] = max(D[b][e][k],D[b][e][k-1]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            for(k=1;k<=cnt;k++){
                if(D[j][i][k]==0)continue;
                DP[i][D[j][i][k]] = max(DP[i][D[j][i][k]], DP[j-1][k-1] + X[D[j][i][k]] - X[k]);
            }
        }
        for(j=1;j<=cnt;j++){
            DP[i][j] = max(DP[i][j],DP[i][j-1]);
            DP[i][j] = max(DP[i-1][j], DP[i][j]);
        }
    }
    printf("%d\n",DP[n][cnt]);
}