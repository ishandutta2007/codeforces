#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char p[3010], q[3010];
int n, m, D[3010][3010], Mod = 998244353;
int main(){
    int i, j;
    scanf("%s",q);
    scanf("%s",p);
    for(i=0;q[i];i++);
    n=i;
    for(i=0;p[i];i++);
    m=i;
    for(i=0;i<n;i++){
        if(i<m){
            if(q[0]==p[i])D[1][i]+=2;
        }
        if(i>=m){
            D[1][i]+=2;
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<n;j++){
            int b = j, e = j+i-1;
            if(e>=n)continue;
            if(e+1<n){
                if(e+1 < m && p[e+1] != q[i]){
                    
                }
                else{
                    D[i+1][j] = (D[i+1][j] + D[i][j])%Mod;
                }
            }
            if(j){
                if(j-1 < m && p[j-1] != q[i]){
                    
                }
                else{
                    D[i+1][j-1]=(D[i+1][j-1]+D[i][j])%Mod;
                }
            }
        }
    }
    int res=0;
    for(i=m;i<=n;i++){
        res=(res+D[i][0])%Mod;
    }
    printf("%d\n",res);
}