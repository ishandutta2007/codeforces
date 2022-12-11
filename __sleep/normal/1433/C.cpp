#include<cstdio>
int t,n,mx,flag,x[300005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mx=flag=0;
        for(int i=1;i<=n;i++){
            scanf("%d",x+i);
            if(x[i]>x[mx]) mx=i;
            if(i-1&&x[i]!=x[i-1]) flag=1;
        }
        if(n==1) puts("1");
        else if(!flag) puts("-1");
        else{ 
            if(mx==1)
                while(mx<n&&x[mx]==x[mx+1]) mx++;
            printf("%d\n",mx);
        }
    }
    return 0;
}