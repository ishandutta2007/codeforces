#include <cstdio>
#include <cstring>
char s[111111],t[111111];
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        scanf("%s",t);
        int l1=strlen(s),l2=strlen(t);
        int x,y;
        for(x=0;x<l2;x++){
            if(t[l2-1-x]=='1') break;
        }
        for(y=x;y<l1;y++){
            if(s[l1-1-y]=='1') break;
        }
        printf("%d\n",y-x);
    }
}