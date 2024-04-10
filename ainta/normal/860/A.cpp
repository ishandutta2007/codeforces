#include<cstdio>
#include<algorithm>
using namespace std;
char p[3010];
int chk[220], D[3010], Path[3010];
int v[3010];
char q[6] = "aeiou";
int main(){
    int i, j, be = 0;
    for(i=0;i<5;i++)chk[q[i]] = 1;
    scanf("%s",p+1);
    D[0] = -1;
    for(i=1;p[i];i++){
        D[i] = D[max(i-2,0)] + 1;
        Path[i] = max(i-2,0);
        for(j=i;j>=3;j--){
            if(!chk[p[j]] && !chk[p[j-1]] && !chk[p[j-2]] && (p[j]!=p[j-1] || p[j-1]!=p[j-2]))break;
            if(D[i] > D[j-3] + 1){
                D[i] = D[j-3] + 1;
                Path[i] = j-3;
            }
        }
    }
    int n = i-1;
    int x = n;
    while(x){
        v[Path[x]] = 1;
        x = Path[x];
    }
    for(i=1;i<=n;i++){
        printf("%c",p[i]);
        if(v[i])printf(" ");
    }
    printf("\n");
}