#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{
    int a, b, num;
    bool operator<(const point &p)const{
        return a<p.a;
    }
}w[3010], P[3010];
int n, A, B, C[6010], C2[6010], S, Res, chk[3010];
int Get1(int cc){
    int i, r = 0;
    for(i=3000;i>=0;i--){
        if(cc >= C[i]){
            r += C[i]*i;
            cc-=C[i];
        }
        else{
            r += cc*i;
            return r;
        }
    }
    return r;
}
int Get2(int cc){
    int i, r = 0;
    for(i=6000;i>=0;i--){
        if(cc >= C2[i]){
            r += C2[i]*i;
            cc-=C2[i];
        }
        else{
            r += cc*i;
            return r;
        }
    }
    return r;
}
int main(){
    int i, ck = 0;
    scanf("%d%d%d",&n,&A,&B);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i].a);
        w[i].num = i;
    }
    for(i=1;i<=n;i++)scanf("%d",&w[i].b);
    sort(w+1,w+n+1);
    for(i=n;i>=n-A+1;i--){
        S += w[i].a;
        C2[w[i].b-w[i].a + 3000]++;
    }
    for(i=1;i<=n-A;i++){
        C[w[i].b]++;
    }
    Res = Get1(B) + S;
    int cc = 0;
    for(i=n-A;i>=1;i--){
        C[w[i].b]--;
        S += w[i].a;
        C2[w[i].b-w[i].a + 3000]++;
        cc++;
        if(B<cc)break;
        int tp = Get1(B-cc) + S + Get2(cc) - 3000*cc;
        if(Res<tp){
            Res=tp;
            ck=cc;
        }
    }
    cc = 0;
    for(i=n;i>=n-A-ck+1;i--){
        cc++;
        P[cc].a = w[i].b-w[i].a;
        P[cc].num = w[i].num;
    }
    sort(P+1,P+cc+1);
    for(i=1;i<=cc;i++){
        if(i>cc-ck)chk[P[i].num] = 2;
        else chk[P[i].num] = 1;
    }
    cc=0;
    for(i=1;i<=n-A-ck;i++){
        cc++;
        P[cc].a = w[i].b;P[cc].num = w[i].num;
    }
    sort(P+1,P+cc+1);
    for(i=cc;i>=cc-(B-ck)+1;i--)chk[P[i].num] = 2;
    printf("%d\n",Res);
    for(i=1;i<=n;i++){
        if(chk[i]==1)printf("%d ",i);
    }
    printf("\n");
    for(i=1;i<=n;i++){
        if(chk[i]==2)printf("%d ",i);
    }
    printf("\n");
}