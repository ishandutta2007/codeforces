#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
using namespace std;
int w[5010][1010][2], n, m, R1[1010], R2[1010];
char p[1010], q[1010], r[1010];
map<string,int> Map;
int main(){
    scanf("%d%d",&n,&m);
    int i, j, t1, t2, k;
    for(i=0;i<m;i++)w[n+1][i][0]=0,w[n+1][i][1]=1;
    for(i=1;i<=n;i++){
        scanf("%s",p);
        Map[p] = i;
        scanf("%s",p);
        scanf("%s",p);
        if(p[0]=='0' || p[0]=='1'){
            for(j=0;j<m;j++){
                w[i][j][0] = w[i][j][1] = p[j]-'0';
            }
            continue;
        }
        t1 = n+1, t2 = n+1;
        scanf("%s%s",q,r);
        if(Map[p]) t1 = Map[p];
        if(Map[r]) t2 = Map[r];
        if(strcmp(q,"XOR") == 0){
            for(j=0;j<m;j++){
                for(k=0;k<2;k++){
                    w[i][j][k] = w[t1][j][k] ^ w[t2][j][k];
                }
            }
        }
        if(strcmp(q,"OR") == 0){
            for(j=0;j<m;j++){
                for(k=0;k<2;k++){
                    w[i][j][k] = w[t1][j][k] | w[t2][j][k];
                }
            }
        }
        if(strcmp(q,"AND") == 0){
            for(j=0;j<m;j++){
                for(k=0;k<2;k++){
                    w[i][j][k] = w[t1][j][k] & w[t2][j][k];
                }
            }
        }
    }
    for(i=0;i<m;i++){
        int s1 = 0, s2 = 0;
        for(j=1;j<=n;j++){
            s1 += w[j][i][0];
            s2 += w[j][i][1];
        }
        if(s1 <= s2) R1[i] = 0;
        else R1[i] = 1;
        if(s1 >= s2) R2[i] = 0;
        else R2[i] = 1;
    }
    for(i=0;i<m;i++)printf("%d",R1[i]);
    printf("\n");
    for(i=0;i<m;i++)printf("%d",R2[i]);
    printf("\n");
}