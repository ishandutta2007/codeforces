#include<cstdio>
#include<algorithm>
using namespace std;
int A[1010000];
int n, m, K, Res[2010000], RC;
struct point{
    int a, num;
    bool operator <(const point &p)const{
        return a<p.a;
    }
}B[1010000], C[2010000];
bool Pos(int T){
    int i;
    int p1 = 1, p2 = T, pv = 0;
    while(p1 <= n || p2 <= m){
        if(p1 <= n && (p2>m || A[p1] < B[p2].a)) C[pv++] = {A[p1++], 0};
        else C[pv++] = B[p2++];
    }
    int c = 0;
    for(i=0;i<pv;i++){
        if(c > C[i].a)return false;
        if(i%K == K-1)c++;
    }
    RC = 0;
    for(i=0;i<pv;i++){
        if(C[i].num) Res[++RC] = C[i].num;
    }
    return true;
}
int main(){
    int i;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d",&B[i].a);
        B[i].num = i;
    }
    sort(A+1,A+n+1);
    sort(B+1,B+m+1);
    int b = 1, e = m+1, r = -1, mid;
    while(b<=e){
        mid = (b+e)>>1;
        if(Pos(mid)){
            r = mid;
            e = mid - 1;
        }
        else b = mid + 1;
    }
    if(r == -1){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", RC);
    for(i=1;i<=RC;i++)printf("%d ",Res[i]);
}