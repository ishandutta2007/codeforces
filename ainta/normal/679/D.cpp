#include<stdio.h>
#include<algorithm>
using namespace std;
int w[410][410], D[410][410], Deg[410], L[410];
bool v[410];
double Res, P[410], MM[410];
int n, m;
void Do(int a){
    int i, j, k;
    double S=0.0;
    for(i=0;i<n;i++){
        int cnt = 0, cnt2 = 0;
        double Mx = 0.0, SS;
        for(j=1;j<=n;j++){
            P[j] = 0.0;
            v[j]=false;
        }
        for(j=1;j<=n;j++){
            if(D[a][j] == i){
                cnt++;
                double tp = 1.0/Deg[j]/n;
                for(k=1;k<=n;k++){
                    if(w[j][k]){
                        P[k] += tp;
                        v[k] = true;
                    }
                }
            }
        }
        if(cnt){
            Mx = max(Mx,1.0/n);
        }
        for(j=1;j<=n;j++){
            if(v[j]){
                L[++cnt2] = j;
            }
        }
        for(j=1;j<=n;j++){
            SS = 0.0;
            for(k=1;k<=cnt2;k++){
                MM[D[j][L[k]]]=max(MM[D[j][L[k]]],P[L[k]]);
            }
            for(k=1;k<=cnt2;k++){
                SS += MM[D[j][L[k]]];
                MM[D[j][L[k]]]=0.0;
            }
            Mx = max(Mx,SS);
        }
        S+=Mx;
    }
    Res = max(Res,S);
}
int main(){
    int i, j, a, b, k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j)D[i][j]=9999999;
        }
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        Deg[a]++,Deg[b]++;
        D[a][b]=D[b][a]=1;
        w[a][b]=w[b][a]=1;
    }
    for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
    for(i=1;i<=n;i++){
        Do(i);
    }
    printf("%.11lf\n",Res);
}