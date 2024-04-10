#include<stdio.h>
#include<algorithm>
using namespace std;
char p[110];
int n, w[60], cnt, ck[60];
long long D[2][110][2], Res;
int main(){
    scanf("%s",p);
    int i;
    for(i=0;p[i];i++);
    n = i;
    for(i=0;i<n;i++){
        if(p[i]=='B' && p[(i+1)%n] == 'A'){
            w[++cnt] = i;
        }
        if(p[i]=='A' && p[(i+1)%n] == 'B'){
            if(p[(i+n-1)%n] == 'A' && p[(i+2)%n] == 'B'){
                printf("0\n");
                return 0;
            }
        }
    }
    while(cnt){
        int chk = 0;
        for(i=1;i<=cnt;i++){
            if(p[(w[i]+n-1)%n] == 'A' && (w[(i+cnt-2)%cnt + 1] + 2)%n != w[i]){
                ck[i] = 1;
                chk=1;
            }
            if(p[(w[i]+2)%n] == 'B' && (w[i%cnt + 1] + n - 2)%n != w[i]){
                ck[i] = 1;
                chk = 1;
            }
        }
        if(!chk)break;
        int c2 = 0;
        for(i=1;i<=cnt;i++){
            if(!ck[i]) w[++c2] = w[i];
            else{
                swap(p[w[i]],p[(w[i]+1)%n]);
            }
            ck[i] = 0;
        }
        cnt = c2;
    }
    if(!cnt){
        printf("1\n");
        return 0;
    }
    D[0][1][0] = D[1][1][1] = 1;
    for(i=2;i<=cnt;i++){
        D[0][i][0] = D[0][i-1][1];
        D[0][i][1] = D[0][i-1][0] + D[0][i-1][1];
        D[1][i][0] = D[1][i-1][1];
        D[1][i][1] = D[1][i-1][0] + D[1][i-1][1];
    }
    for(i=1;i<=cnt;i++){
        if((w[i]+2)%n == w[i%cnt+1])ck[i] = 1;
    }
    for(i=1;i<=cnt;i++){
        if(ck[i]==0)break;
    }
    if(i==cnt+1){
        printf("%lld\n",D[0][cnt][1]+D[1][cnt][0]+D[1][cnt][1]);
        return 0;
    }
    int be = i%cnt+1, x = be;
    Res = 1;
    do{
        int c=1;
        while(ck[x]) x = x%cnt+1,c++;
        Res*=(D[0][c][0]+D[0][c][1]+D[1][c][0]+D[1][c][1]);
        x=x%cnt+1;
    }while(x!=be);
    printf("%lld\n",Res);
}