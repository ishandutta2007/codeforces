#include<cstdio>
int t,n,a;
char s[100005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s);
        bool flag=0;
        for(int i=1;s[i];i++){
            if(s[i]!=s[i-1]){
                flag=1;
                printf("%d %d\n",i,i+1);
                break;
            }
        }
        if(!flag) puts("-1 -1");
    }
    return 0;
}