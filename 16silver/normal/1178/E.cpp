#include <cstdio>
#include <cstring>
char s[1010101];
char ans[1010101];
int main(){
    scanf("%s",s);
    int l = strlen(s);
    ans[l/2]='\0';
    for(int i=0;i<l/4;i++){
        if(s[i*2]==s[l-1-i*2]){
            ans[i]=s[i*2];
            ans[l/2-1-i]=s[i*2];
        }
        else if(s[i*2+1]==s[l-1-i*2]){
            ans[i]=s[i*2+1];
            ans[l/2-1-i]=s[i*2+1];
        }
        else if(s[i*2]==s[l-2-i*2]){
            ans[i]=s[i*2];
            ans[l/2-1-i]=s[i*2];
        }
        else if(s[i*2+1]==s[l-2-i*2]){
            ans[i]=s[i*2+1];
            ans[l/2-1-i]=s[i*2+1];
        }
    }
    if(l%4>=2){
        ans[l/4] = s[l/2];
    }
    printf("%s\n",ans);

}