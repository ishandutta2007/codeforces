#include<stdio.h>
#include<algorithm>
using namespace std;
int A, B, C, n, C1, C2, R;
int P1[301000], P2[301000];
long long S = 0;
int main(){
    int i, a;
    char p[10];
    scanf("%d%d%d%d",&A,&B,&C,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        scanf("%s",p);
        if(p[0]=='U')P1[++C1] = a;
        else P2[++C2] = a;
    }
    sort(P1+1,P1+C1+1);
    sort(P2+1,P2+C2+1);
    int pv1 = min(C1, A), pv2 = min(C2, B);
    R = pv1 + pv2;
    for(i=1;i<=pv1;i++) S += P1[i];
    for(i=1;i<=pv2;i++) S += P2[i];
    while((pv1 < C1 || pv2 < C2) && C){
        if((pv2 == C2) || (pv1 != C1 && P1[pv1+1] <= P2[pv2+1])){
            pv1++;R++;
            S += P1[pv1];
            C--;
        }
        else{
            pv2++;R++;
            S += P2[pv2];
            C--;
        }
    }
    printf("%d %lld\n",R,S);
}