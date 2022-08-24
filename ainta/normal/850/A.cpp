#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int w[1010][5], n, P[1010][5], v[3][3][3][3][3];
int main(){
    int i, j, k, l;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=0;j<5;j++)scanf("%d",&w[i][j]);
    }
    vector<int>res;
    for(i=1;i<=n;i++){
        for(j=0;j<243;j++){
            v[j/81][(j/27)%3][(j/9)%3][(j/3)%3][j%3] = 0;
        }
        for(j=1;j<=n;j++){
            for(k=0;k<5;k++){
                int t = w[j][k]-w[i][k];
                P[j][k] = t>0?1:t<0?-1:0;
            }
            v[P[j][0]+1][P[j][1]+1][P[j][2]+1][P[j][3]+1][P[j][4]+1]++;
        }
        int ck = 0;
        for(j=0;j<243;j++){
            if(v[j/81][(j/27)%3][(j/9)%3][(j/3)%3][j%3] >= 2) ck = 1;
        }
        if(!ck){
            for(j=1;j<=n;j++)for(k=j+1;k<=n;k++){
                int s = 0;
                for(l=0;l<5;l++)s += (w[j][l]-w[i][l])*(w[k][l]-w[i][l]);
                if(s>0)ck = 1;
            }
        }
        if(!ck)res.push_back(i);
    }
    printf("%d\n",res.size());
    for(i=0;i<res.size();i++)printf("%d ",res[i]);
}