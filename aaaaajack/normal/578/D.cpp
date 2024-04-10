#include<cstdio>
#define N 200100
char s[N];
int main(){
    int n,m,ed;
    scanf("%d%d",&n,&m);
    long long ans=0;
    scanf("%s",s);
    for(int i=0;s[i];i++){
        ans+=m-1;
        if(s[i]!=s[i+1]) ans+=1LL*(m-1)*(n-i-1);
        if(i&&s[i]!=s[i-1]) ans+=1LL*(m-1)*i;
    }
    for(int i=0,j=1;s[i+1];i++){
        if(j<i+1) j=i+1;
        while(s[j]&&s[j]!=s[j-1]&&(j==i+1||s[j]==s[j-2])) j++;
        ans-=(j-i-1);
    }
    printf("%I64d\n",ans);
    return 0;
}