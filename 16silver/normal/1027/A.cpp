#include <cstdio>
char s[555];
int main(){
    int T,t,n,i;
    scanf("%d",&T);
    for(t=0;t<T;t++){
        scanf("%d",&n);
        scanf("%s",s);
        for(i=0;i<n;i++){
            if(s[i]-s[n-1-i] != 2 && s[i]-s[n-1-i] != -2 && s[i]-s[n-1-i] != 0) break;
        }
        if(i==n) printf("YES\n");
        else printf("NO\n");
    }
}