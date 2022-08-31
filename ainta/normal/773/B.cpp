#include<cstdio>
#include<algorithm>
#include<bitset>
#define BS 15000
using namespace std;
int w[122][6], n, m = 5, C[6];
bitset<30100>B[6];
bool Pos(int c){
    int i, j;
    int pp[7] = {n+c, (n+c)/2,(n+c)/4,(n+c)/8,(n+c)/16,(n+c)/32, -1};
    B[0].reset();
    B[0][BS] = 1;
    for(i=1;i<=5;i++){
        B[i].reset();
        int tt = c;
        if(w[1][i]==-1)tt = 0;
        for(j=0;j<6;j++){
            if(max(C[i], pp[j+1] + 1) <= min(C[i]+tt, pp[j])){
                int t = (j+1)*500, s = 0;
                if(w[1][i] != -1)s += t - t/250*w[1][i];
                if(w[2][i] != -1)s -= t - t/250*w[2][i];
                if(s>0)B[i] |= B[i-1] << s;
                else B[i] |= B[i-1] >> (-s);
            }
        }
    }
    
    for(i=BS+1;i<=BS+BS;i++){
        if(B[5][i])return true;
    }
    return false;
}
int main(){
    int b, e, mid, i, j, r = -1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&w[i][j]);
            if(w[i][j]!=-1)C[j]++;
        }
    }
    for(i=0;i<4000;i++)if(Pos(i)){r=i;break;}
    printf("%d\n",r);
}