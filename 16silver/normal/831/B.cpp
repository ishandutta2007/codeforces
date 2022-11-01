#include <stdio.h>
#include <string.h>
int main(){
    char f[28],s[28],ans[1005];
    int d[26],i;
    scanf("%s",f);
    scanf("%s",s);
    for(i=0;i<26;i++){
        d[f[i]-'a']=i;
    }
    scanf("%s",ans);
    for(i=0;i<strlen(ans);i++){
        if(ans[i]>='A' && ans[i]<='Z'){
            ans[i]=s[d[ans[i]-'A']]+'A'-'a';
        }
        else if(ans[i]>='a' && ans[i]<='z'){
            ans[i]=s[d[ans[i]-'a']];
        }
    }
    printf("%s",ans);
}