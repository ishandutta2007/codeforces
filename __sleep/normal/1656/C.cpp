#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300005;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            if(a[i]==0) x=1;
            if(a[i]==1) y=1;
        }
        if(x&&y){puts("NO"); continue;}
        if(y){
            sort(a+1,a+n+1);
            int flag=1;
            for(int i=2;i<=n;i++)
                if(a[i-1]==a[i]-1) flag=0; 
            puts(flag?"YES":"NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}