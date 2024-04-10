#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
    int x, b, e, num;
    bool operator<(const point &p)const{
        return x<p.x;
    }
}A[401000], B[401000];
int n, w[201000], Q;
long long R[201000];
long long Calc(int x){
    return 1ll*x*(x-1)/2;;
}
int BIT[201000];
void Ins(int a){
    while(a<=n){
        BIT[a]++;
        a+=(a&-a);
    }
}
int Sum(int a){
    int r = 0;
    while(a){
        r += BIT[a];
        a-=(a&-a);
    }
    return r;
}
int main(){
    int i, x1, y1, x2, y2;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=Q;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        R[i] += Calc(x1-1) + Calc(n-x2) + Calc(y1-1) +Calc(n-y2);
        A[i] = {x1-1, 1, y1-1, i};
        A[i+Q] = {x1-1, y2+1, n, i};
        B[i] = {x2+1, 1, y1-1, i};
        B[i+Q] = {x2+1, y2+1, n, i};
    }
    sort(A+1,A+Q+Q+1);
    sort(B+1,B+Q+Q+1);
    int pv = 1;
    for(i=1;i<=Q+Q;i++){
        while(pv <= A[i].x){
            Ins(w[pv]);
            pv++;
        }
        R[A[i].num] -= Calc(Sum(A[i].e) - Sum(A[i].b-1));
    }
    for(i=1;i<=n;i++) BIT[i] = 0;
    pv = n;
    for(i=Q+Q;i>=1;i--){
        while(pv >= B[i].x){
            Ins(w[pv]);
            pv--;
        }
        R[B[i].num] -= Calc(Sum(B[i].e) - Sum(B[i].b-1));
    }
    for(i=1;i<=Q;i++){
        printf("%lld\n",Calc(n)-R[i]);
    }
}