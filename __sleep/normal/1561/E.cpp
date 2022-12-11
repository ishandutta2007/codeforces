#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2022;
int n,t,a[2022],p[2022],ans[10005],top;
void work(int x){
    for(int i=1;i<=x/2;i++){
        swap(a[i],a[x-i+1]);
        p[a[i]]=i; p[a[x-i+1]]=x-i+1;
    }
    ans[top++]=x;
}
int main(){
    scanf("%d",&t);
    while(t--){
        bool flag=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if((a[i]^i)&1) flag=0;
            p[a[i]]=i;
        }
        if(!flag){puts("-1"); continue;}
        top=0;
        for(int i=n;i>1;i-=2){
            if(p[i]==i&&p[i-1]==i-1) continue;
            if(p[i]==1){
                if(p[i-1]==2)
                    work(i);
                else{
                    work(p[i-1]-1);
                    work(p[i-1]+1);
                    work(3);
                    work(i);
                }
            }
            else if(p[i]==p[i-1]+1){
                work(p[i]);
                work(i);
            }
            else if(p[i]==p[i-1]-1){
                work(p[i-1]+1);
                work(3);
                work(i);
            }
            else{
                work(p[i]);
                work(p[i-1]-1);
                work(p[i-1]+1);
                work(3);
                work(i);
            }
        }
        printf("%d\n",top);
        for(int i=0;i<top;i++)
            printf("%d ",ans[i]);
        if(top)puts("");
    }
    return 0;
}