#include<cstdio>
const int N=55;
char s[N],t[N];
int n,m;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        scanf("%s%s",s,t);
        int x=0,y=0,st=0;
        if(n<m) goto NO;
        while(n>m){
            if(s[st++]=='0') x=1;
            else y=1;
            --n;
        }
        // printf("# %d %d %d\n",x,y,st);
        for(int i=1;i<m;i++)
            if(s[st+i]!=t[i]) goto NO;
        if(s[st]!=t[0]){
            if(t[0]=='0'&&x) goto YES;
            if(t[0]=='1'&&y) goto YES;
            goto NO;
        }
YES:    puts("YES"); continue;
NO:     puts("NO"); continue;
    }
    return 0;
}