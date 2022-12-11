#include<cstdio>
const int N=100005;
int n,t,k,ans;
char s[55];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s",s+1); ans=0;
        int i,lst=0,now=0;
        for(i=1;s[i];i++){
            if(s[i]=='*'){
                if(!lst) s[i]='x',lst=i,ans++;
                else if(i-lst<=k) now=i;
                else s[lst=now]='x',ans++,now=i;
            }
        }
        if(s[now]!='x'&&now) ans++;
        printf("%d\n",ans);
    }
    return 0;
}