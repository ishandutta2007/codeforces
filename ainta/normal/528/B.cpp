#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
    int x, y;
    bool operator<(const A &p)const{
        return x-y<p.x-p.y;
    }
}w[201000];
int n, D[201000], cnt;
int main(){
    int i, b, e, r, mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].x,&w[i].y);
    }
    sort(w+1,w+n+1);
    for(i=1;i<=n;i++){
        if(!D[i])D[i]=1;
        D[i]=max(D[i-1],D[i]);
        b = i+1,e=n, r=n+1;
        while(b<=e){
            mid=(b+e)>>1;
            if(w[i].x+w[i].y <= w[mid].x-w[mid].y){
                r=mid;
                e=mid-1;
            }
            else b=mid+1;
        }
        if(r<=n)D[r] = max(D[r], D[i]+1);
    }
    printf("%d\n",D[n]);
}