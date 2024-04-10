#include <cstdio>
char s[99], ans[55];
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int sum=0;
    int i;
    for(i=1;sum<=n;i++){
        sum+=i;
        ans[i-1]=s[sum-1];
    }
    ans[i-1]='\0';
    printf("%s",ans);
}