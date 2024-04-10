#include <cstdio>
#include <cstring>
char s[5555];
char t[5555];
int main(){
    scanf("%s",s);
    int l=strlen(s);
    if(l<4){
        printf("Impossible");
        return 0;
    }
    int i;
    for(i=1;i<l/2;i++){
        if(s[i]!=s[i-1]) break;
    }
    if(i==l/2){
        printf("Impossible");
        return 0;
    }
    else{
        for(i=0;i<l;i++){
            t[i]=s[i];
        }
        for(i=0;i<l;i++){
            int j;
            t[l]=t[0];
            for(j=0;j<l;j++) t[j]=t[j+1];
            for(j=0;j<l;j++){
                if(t[j]!=t[l-j-1]) break;
            }
            if(j!=l) continue;
            for(j=0;j<l;j++){
                if(t[j]!=s[j]) break;
            }
            if(j!=l){
                printf("1");
                return 0;
            }
        }
        printf("2");
    }
}