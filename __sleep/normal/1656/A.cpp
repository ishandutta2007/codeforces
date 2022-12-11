#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300005;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x=1,y=1;
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if(a[i]>a[x]) x=i;
            if(a[i]<a[y]) y=i;
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}