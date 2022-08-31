#include<stdio.h>
#include<algorithm>
using namespace std;
int n, Res;
struct point{
    int b, e;
}w[110];
struct AA{
    int g, num, ck;
    bool operator<(const AA &p)const{
        return g<p.g;
    }
}R[110];
int ab(int a){
    return a<0?-a:a;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].b,&w[i].e);
        w[i].e += w[i].b;
        w[i].b = w[i].b*1000+n-i;
        w[i].e = w[i].e*1000+n-i;
    }
    for(i=1;i<=n;i++){
        R[i].g = w[i].b;
        R[i].num = i;
        R[i].ck = 0;
    }
    sort(R+1,R+n+1);
    while(1){
        int MM = 1e9, x = -1, t;
        for(i=1;i<=n;i++){
            t = R[i].num;
            if(w[t].b <= w[t].e && !R[i].ck){
                if(MM>w[t].b)MM=w[t].b, x = i;
            }
        }
        if(x!=-1){
            R[x].ck = 1;
            t = R[x].num;
            R[x].g = w[R[x].num].e;
            sort(R+1,R+n+1);
            for(i=1;i<=n;i++)if(R[i].num == t)break;
            Res += ab(i-x);
            continue;
        }
        MM = -1e9, x = -1;
        for(i=1;i<=n;i++){
            t = R[i].num;
            if(w[t].b >= w[t].e && !R[i].ck){
                if(MM<w[t].b)MM=w[t].b, x = i;
            }
        }
        if(x==-1)break;
        R[x].ck = 1;
        t = R[x].num;
        R[x].g = w[R[x].num].e;
        sort(R+1,R+n+1);
        for(i=1;i<=n;i++)if(R[i].num == t)break;
        Res += ab(i-x);
        continue;
    }
    printf("%d\n",Res);
}