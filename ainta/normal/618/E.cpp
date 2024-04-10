#include<stdio.h>
#include<algorithm>
#include<math.h>
#define SZ 524288
struct SegTree{
    double P[3][3];
}IT[SZ+SZ+2];
using namespace std;
int n, m;
const double PI = acos(-1.0);
double TP[3][3], Ans[3][3], TP2[3][3];
void init(int nd, int b, int e){
    if(b==e){
        IT[nd].P[0][2]=b;
        IT[nd].P[2][2]=1.0;
        return;
    }
    int m = (b+e)>>1;
    init(nd*2,b,m);
    init(nd*2+1,m+1,e);
    IT[nd].P[0][0]=IT[nd].P[1][1]=IT[nd].P[2][2]=1.0;
}
void Ans_init(){
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==j)Ans[i][j]=1.0;
            else Ans[i][j]=0.0;
        }
    }
}
void Gop(int nd){
    int i, j, k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            TP[i][j]=Ans[i][j];
            Ans[i][j]=0.0;
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++)Ans[i][j]+=TP[i][k]*IT[nd].P[k][j];
        }
    }
}
void Get(int nd, int b, int e, int x){
    Gop(nd);
    if(b==e)return;
    int m = (b+e)>>1;
    if(x<=m)Get(nd*2,b,m,x);
    else Get(nd*2+1,m+1,e,x);
}
void Doxy(double x, double y){
    int i,j, k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            TP2[i][j] = Ans[i][j];
            Ans[i][j]=0;
            if(i==j)TP[i][j]=1.0;
            else TP[i][j]=0.0;
        }
    }
    TP[0][2]=x;
    TP[1][2]=y;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++)Ans[i][j]+=TP[i][k]*TP2[k][j];
        }
    }
}
void DoAn(double An){
    int i,j, k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            TP2[i][j] = Ans[i][j];
            Ans[i][j]=0;
            if(i==j)TP[i][j]=1.0;
            else TP[i][j]=0.0;
        }
    }
    double ss=sin(An), cc=cos(An);
    TP[0][0]=TP[1][1]=cc;
    TP[0][1]=-ss,TP[1][0]=ss;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++)Ans[i][j]+=TP[i][k]*TP2[k][j];
        }
    }
}
void Mul(int nd){
    int i,j, k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            TP[i][j] = Ans[i][j];
            TP2[i][j]=IT[nd].P[i][j];
            IT[nd].P[i][j]=0;
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++)IT[nd].P[i][j]+=TP[i][k]*TP2[k][j];
        }
    }
}
void Spread(int nd){
    double TT[3][3];
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            TT[i][j]=Ans[i][j];
            Ans[i][j]=IT[nd].P[i][j];
            if(i==j)IT[nd].P[i][j]=1.0;
            else IT[nd].P[i][j]=0.0;
        }
    }
    Mul(nd*2);
    Mul(nd*2+1);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)Ans[i][j]=TT[i][j];
    }
}
void Ins(int nd, int b, int e, int s, int l){
    if(b==s&&e==l){
        Mul(nd);
        return;
    }
    Spread(nd);
    int m = (b+e)>>1;
    if(s<=m)Ins(nd*2,b,m,s,min(m,l));
    if(l>m)Ins(nd*2+1,m+1,e,max(s,m+1),l);
}
int main(){
    int i, ck, a, b;
    double x1, y1, x2, y2, An, d;
    scanf("%d%d",&n,&m);
    init(1, 0,n);
    while(m--){
        scanf("%d%d%d",&ck,&a,&b);
        Ans_init();
        Get(1, 0, n, a-1);
        x1 = Ans[0][2], y1 = Ans[1][2];
        if(ck==2){
            An=-b*PI/180.0;
            Ans_init();
            Doxy(-x1,-y1);
            DoAn(An);
            Doxy(x1,y1);
            Ins(1, 0, n, a, n);
        }
        else{
            Ans_init();
            Get(1, 0, n, a);
            x2 = Ans[0][2], y2 = Ans[1][2];
            d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            Ans_init();
            Doxy((x2-x1)/d*b,(y2-y1)/d*b);
            Ins(1, 0, n, a, n);
        }
        Ans_init();
        Get(1,0,n,n);
        printf("%.10lf %.10lf\n",Ans[0][2],Ans[1][2]);
    }
}