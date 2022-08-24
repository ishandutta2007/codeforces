#include<stdio.h>
#include<algorithm>
using namespace std;
char p[510][510];
int n, w[510], cnt, st[10100];
struct point{
    int x, y;
    point(){}
    point(int x_,int y_){x=x_,y=y_;}
    bool operator<(const point &p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}P[10100], Con[10100];
void Do(int a){
    int i, bb = -1, ee;
    for(i=1;i<=n;i++)p[a][i] -= w[i];
    for(i=1;i<=n;i++){
        if(p[a][i]!='0'){
            if(bb==-1)bb=i;
            ee=i;
        }
    }
    for(i=1;i<=n;i++)w[i]=0;
    if(bb==-1)return;
    for(i=bb;i<=ee;i++){
        if(i==bb||i==ee)w[i]=1;
        else w[i]=2;
    }
    P[++cnt] = point(bb, n-a);
    P[++cnt] = point(ee-1, n-a);
}
int ccw(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
void Make(){
    int i, top, cc = 0, j;
    top = 0;
    st[++top] = 1;
    for(i=2;i<=cnt;i++){
        while(top>1 && ccw(P[st[top-1]],P[st[top]],P[i])>=0)top--;
        st[++top] = i;
    }
    for(i=1;i<top;i++) Con[++cc] = P[st[i]];
    top = 0;
    st[++top] = 1;
    for(i=2;i<=cnt;i++){
        while(top>1 && ccw(P[st[top-1]],P[st[top]],P[i])<=0)top--;
        st[++top] = i;
    }
    for(i=top;i>1;i--) Con[++cc] = P[st[i]];
    for(i=1;i<=cc;i++){
        for(j=1;j<=cc;j++){
            if(Con[j]<Con[i])break;
        }
        if(j==cc+1)break;
    }
    j = i;
    printf("%d\n",cc);
    for(i=j;i<=cc;i++)printf("%d %d\n",Con[i].x,Con[i].y);
    for(i=1;i<j;i++)printf("%d %d\n",Con[i].x,Con[i].y);
    printf("\n");
}
int main(){
    int i, j, x, bb, ee;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        for(i=1;i<=n;i++){
            scanf("%s",p[i]+1);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(p[i][j]!='0')break;
            }
            if(j!=n+1)break;
        }
        x = i;
        for(i=1;i<=n;i++)w[i]=0;
        cnt = 0;
        for(i=x;i<=n;i++){
            Do(i);
        }
        Make();
    }
}