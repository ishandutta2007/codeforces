#include<stdio.h>
#include<algorithm>
#include<list>
using namespace std;
struct point{
    int x, y;
    bool operator <(const point &p)const{
        return x<p.x;
    }
}w[101000];
int n, K, S[30100000], tp[101000], C[101000];
int L[101000], LC;
bool IsIn[101000];
struct Q{
    int x, y, ck;
    bool operator <(const Q &p)const{
        return x<p.x;
    }
}P[201000];
void Ins(int x, int y, int ck){
    int i;
    for(i=y;i<y+K;i++){
        C[S[i]]--;
        S[i] += ck;
        C[S[i]]++;
        if(S[i] > 500 && !IsIn[S[i]]){
            IsIn[S[i]]=true;
            L[++LC] = S[i];
        }
    }
}
long long Res[101000];
int main(){
    int i, j;
    long long d;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].y,&w[i].x);
    }
    sort(w+1,w+n+1);
    tp[1] = 1;
    for(i=2;i<=n;i++){
        if(w[i].x > w[i-1].x + 300){
            tp[i] = tp[i-1] + 300;
        }
        else tp[i]=tp[i-1] + w[i].x-w[i-1].x;
    }
    for(i=1;i<=n;i++){
        w[i].x = tp[i];
        swap(w[i].x,w[i].y);
    }
    for(i=1;i<=n;i++){
        P[i].x = w[i].x, P[i+n].x = w[i].x+K;
        P[i].y = P[i+n].y = w[i].y;
        P[i].ck=1,P[i+n].ck=-1;
    }
    sort(P+1,P+n+n+1);
    for(i=1;i<=2*n;i++){
        Ins(P[i].x,P[i].y,P[i].ck);
        if(P[i].x!=P[i+1].x){
            d = P[i+1].x-P[i].x;
            for(j=1;j<=500;j++)Res[j] += d*C[j];
            int LC2 = 0;
            for(j=1;j<=LC;j++){
                Res[L[j]] += d*C[L[j]];
                if(C[L[j]])L[++LC2] = L[j];
                else IsIn[L[j]]=false;
            }
            LC = LC2;
        }
    }
    for(i=1;i<=n;i++)printf("%lld ",Res[i]);
}