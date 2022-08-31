#include<cstdio>
#include<algorithm>
using namespace std;
char p[10][10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char q[10];
int D[2010][2010], n, K, Path[2010][2010][2], Rank[2010][2010], T[2010];
char S[2010][10];
struct point{
    int z;
    int num;
    bool operator <(const point &p)const{
        return z<p.z;
    }
}ww[2010];
int main(){
    int i, j, k;
    scanf("%d%d",&n,&K);
    for(i=n;i>=1;i--){
        scanf("%s",S[i]);
    }
    D[0][0]=1;
    Rank[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=K;j++)T[j]=-1e9;
        for(j=0;j<10;j++){
            int ck=0,cc=0;
            for(k=0;k<7;k++){
                if(p[j][k]=='0' && S[i][k]=='1')ck=1;
                if(p[j][k]=='1'&&S[i][k]=='0')cc++;
            }
            if(ck)continue;
            for(k=cc;k<=K;k++){
                if(D[i-1][k-cc]){
                    D[i][k]=1;
                    int tp = j*3000+Rank[i-1][k-cc];
                    if(T[k] < tp){
                        T[k] = tp;
                        Path[i][k][0]=j;
                        Path[i][k][1]=k-cc;
                    }
                }
            }
        }
        int c=0;
        for(j=0;j<=K;j++){
            if(D[i][j])ww[c++]={T[j],j};
        }
        sort(ww,ww+c);
        int cc=0;
        for(j=0;j<c;j++){
            if(j==0 || ww[j].z!=ww[j-1].z)cc++;
            Rank[i][ww[j].num]=cc;
        }
    }
    if(!D[n][K]){
        puts("-1");
        return 0;
    }
    int x = K;
    for(i=n;i>=1;i--){
        int t = Path[i][x][0];
        printf("%d",t);
        x=Path[i][x][1];
    }
}