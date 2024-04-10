#include<stdio.h>
#include<algorithm>
using namespace std;
int w[1010000], L[1010000], R[1010000], n, st[1010000];
double S1[1010000], S2[1010000], Res[1010000];
void Add(int A, int B, int H){
    if(B<A)swap(A,B);
    S1[1] += H;
    S1[A+1] -= H;
    S2[A+1] += 1ll*A*H;
    S2[B+1] -= 1ll*A*H;
    S1[B+1] -= H;
    S2[B+1] += 1ll*(A+B)*H;
    S1[A+B] += H;
    S2[A+B] -= 1ll*(A+B)*H;
}
int main(){
    int i, top = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n+1;i++){
        while(top && (i==n+1 || w[st[top]] >= w[i])){
            R[st[top]] = i-st[top];
            top--;
        }
        L[i] = i-st[top];
        st[++top] = i;
    }
    long long s=0;
    for(i=1;i<=n;i++){
        Add(L[i],R[i],w[i]);
    }
    double A=0.0,B=0.0;
    for(i=1;i<=n;i++){
        A+=S1[i],B+=S2[i];
        Res[i] = (A*i+B) / (n-i+1);
    }
    int Q, a;
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&a);
        printf("%.11f\n",Res[a]);
    }
}