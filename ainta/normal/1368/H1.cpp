#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int Do(int n, int m, char *U, char *D, char *L, char *R){
    int CB=0,CR=0;
    int i;
    for(i=0;i<m;i++){
        if(U[i]=='B')CR++;
        else CB++;
    }
    for(i=0;i<n;i++){
        int tcr=CR,tcb=CB;
        if(L[i]=='B')tcr++;
        else tcb++;
        if(R[i]=='B')tcr++;
        else tcb++;
        if(i!=0){
            tcr = min(tcr, CB+m+tcr-CR);
            tcb = min(tcb, CR+m+tcb-CB);
        }
        CB=tcb, CR=tcr;
    }
    for(i=0;i<m;i++){
        if(D[i]=='B')CR++;
        else CB++;
    }
    return min(CR,CB);
}
int n, m, Q;
char L[N_],R[N_],U[N_],D[N_];
int main(){
    scanf("%d%d%d",&n,&m,&Q);
    scanf("%s%s%s%s",L,R,U,D);
    int r1 = Do(n,m,U,D,L,R);
    int r2 = Do(m,n,L,R,U,D);
    printf("%d\n",min(r1,r2));
}