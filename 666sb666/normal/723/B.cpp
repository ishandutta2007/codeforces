#include <cstdio>
int n;
char s[50000];
bool b=false;
int tlen=0,ans=0,ans2=0;
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++){
        if (s[i]=='('){
            if (!b && ans<tlen) ans=tlen;
            tlen=0;
            b=true;
        }else
        if (s[i]==')'){
            if (b && tlen>0) ans2++;
            b=false;
            tlen=0;
        }else
        if (s[i]=='_'){
            if (b && tlen>0) ans2++;
            if (!b && ans<tlen) ans=tlen;
            tlen=0;
        }
        else {tlen++;}
    }
    if (!b && ans<tlen) ans=tlen;
    printf("%d %d\n",ans,ans2);
    return 0;
}