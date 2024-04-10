#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int t,b,a,x,y;
int ans[500005],top;
// void work(){
//     for(int i=x-a;i<=n;i-=2) ans[top++]=i,printf("~%d ",i);
// }
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        top=0;
        if(a>b) swap(a,b);
        x=(a+b)/2;
        y=a+b-x;
        int p=b-y;
        if((a+b)&1){
            printf("%d\n",a+b-2*p+1);
            for(int i=p;i<=a+b-p;i++)
                printf("%d ",i);
            puts("");
        }
        else{
            printf("%d\n",(a+b-2*p)/2+1);
            for(int i=p;i<=a+b-p;i+=2)
                printf("%d ",i);
            puts("");
        }
    }
    return 0;
}