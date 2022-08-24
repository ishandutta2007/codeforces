#include<stdio.h>
int U[200010], D[200010], n, m, oto[200010];
int A[200010], B[200010], st[200010], top, res;
bool F(int a, int b){
    if(D[a] && A[b + D[a] - a] > A[b])return false;
    if(U[a] && A[b + U[a] - a] < A[b])return false;
    return true;
}
bool F2(int a, int b){
    if(D[b] && B[a + D[b] - b] > B[a])return false;
    if(U[b] && B[a + U[b] - b] < B[a])return false;
    return true;
}
int main()
{
    int i, a, t, pv;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d",&a);
        B[a] = i;
    }
    for(i=1;i<=n;i++){
        while(top &&st[top] > A[i]){
            U[st[top]] = A[i];
            top--;
        }
        if(top) D[A[i]] = st[top];
        st[++top] = A[i];
    }
    for(i=1;i<=n;i++)st[A[i]]=i;
    for(i=1;i<=n;i++)A[i]=st[i];
    oto[1] = 0;
    for(i=2;i<=n+1;i++){
        t = oto[i-1];
        while(t && !F(t, i-1)){
            t=oto[t];
        }
        oto[i] = t+1;
    }
    pv = 1;
    for(i=1;i<=m;i++){
        while(pv && !F2(i, pv)){
            pv = oto[pv];
        }
        pv++;
        if(pv == n + 1){
            res++;
            pv=oto[pv];
        }
    }
    printf("%d\n",res);
}