#include<stdio.h>
#include<algorithm>
using namespace std;
int w[110], n, Mn;
int R[10100][110], C;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    while(1){
        int Mn = 9999;
        for(i=1;i<=n;i++){
            Mn = min(Mn,w[i]);
        }
        int c = 0, ck = 0;
        for(i=1;i<=n;i++){
            if(Mn!=w[i])c++;
            if(w[i]-Mn>1)ck=1;
        }
        if(c==0)break;
        C++;
        if(c == 3&&ck==0){
            for(i=1;i<=n;i++){
                if(Mn != w[i]){
                    R[C][i] = 1;
                    w[i]--;
                }
            }
        }
        else{
            int Mx1=-1, x1=0, Mx2=-1, x2=0;
            for(i=1;i<=n;i++){
                if(Mx1<w[i]){
                    Mx2=Mx1,x2=x1;
                    Mx1=w[i],x1=i;
                }
                else if(Mx2<w[i])Mx2=w[i],x2=i;
            }
            R[C][x1]=R[C][x2]=1;
            w[x1]=max(w[x1]-1,0);
            w[x2]=max(w[x2]-1,0);
        }
    }
    printf("%d\n%d\n",w[1],C);
    for(i=1;i<=C;i++){
        for(int j=1;j<=n;j++){
            printf("%d",R[i][j]);
        }
        printf("\n");
    }
}