#include<cstdio>
#include<algorithm>
int t,n,a[200005];
long long x,y;
inline bool cmp(int c,int b){return c>b;}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        std::sort(a,a+n,cmp);
        x=y=0;
        for(int i=0;i<n;i++){
            if(!(a[i]&1)&&!(i&1)) x+=a[i];
            if((a[i]&1)&&(i&1)) y+=a[i];
        }
        if(x>y) puts("Alice");
        else if(x==y) puts("Tie");
        else puts("Bob");
    }
    return 0;
}