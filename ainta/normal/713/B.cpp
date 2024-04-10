#include<stdio.h>
int n, res[8];
void Print(int bx, int ex, int by, int ey, int ck){
    if(!ck)printf("%d %d %d %d",bx,by,ex,ey);
    else printf("%d %d %d %d",by,bx,ey,ex);
}
int Query(int bx, int ex, int by, int ey, int ck){
    printf("? ");
    Print(bx,ex,by,ey,ck);
    printf("\n");
    fflush(stdout);
    int a;
    scanf("%d",&a);
    return a;
}
int Get(int ck){
    int b = 1, e = n, mid, r, g;
    while(b<=e){
        mid = (b+e)>>1;
        g = Query(1, mid, 1, n, ck);
        if(g){
            r = mid;
            e = mid - 1;
        }
        else b = mid + 1;
    }
    if(r == n)return -1;
    g = Query(r+1, n, 1, n, ck);
    if(g != 1)return -1;
    return r;
}
void Do(int *w, int pv, int cc, int ck){
    if(pv==4){
        int i;
        for(i=0;i<4;i++)res[cc*4+i]=w[i];
        return;
    }
    int b = w[pv^(pv&1)], e = w[pv|1], mid, g, r;
    while(b<=e){
        mid = (b+e)>>1;
        int tp = w[pv];
        w[pv] = mid;
        g = Query(w[0],w[1],w[2],w[3], ck);
        w[pv] = tp;
        if(g){
            r = mid;
            if(pv&1)e = mid - 1;
            else b = mid + 1;
        }
        else{
            if(pv&1)b = mid + 1;
            else e = mid - 1;
        }
    }
    w[pv] = r;
    Do(w, pv+1, cc, ck);
}
int main(){
    int i, x, ck = 0, w[4];
    scanf("%d",&n);
    x = Get(0);
    if(x==-1){
        x = Get(1);
        ck = 1;
    }
    w[0] = 1, w[1] = x, w[2] = 1, w[3] = n;
    Do(w,0,0,ck);
    w[0] = x+1, w[1] = n, w[2] = 1, w[3] = n;
    Do(w,0,1,ck);
    printf("! ");
    Print(res[0],res[1],res[2],res[3],ck);
    printf(" ");
    Print(res[4],res[5],res[6],res[7],ck);
    printf("\n");
    fflush(stdout);
}