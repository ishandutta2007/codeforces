#include<cstdio>
#include<cstring>
int t,n,a;
char s[100],ans[55][55];
int main(){
    scanf("%d",&t);
    while(t--){
        memset(ans,0,sizeof(ans));
        scanf("%d%s",&n,s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                for(int j=1;j<=n;j++)
                    ans[i][j]=ans[j][i]='=';
            }
            ans[i][i]='X';
        }
        bool flag=1;
        for(int i=1;i<=n;i++){
            bool fflag=1;
            if(s[i]=='2'){
                for(int j=1;j<=n;j++){
                    if(!ans[i][j]){
                        ans[i][j]='+';
                        ans[j][i]='-';
                        fflag=0;
                        break;
                    }
                }
                if(fflag) flag=0;
            }
        }
        if(!flag){
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][j]) putchar(ans[i][j]);
                else putchar('=');
            }
            puts("");
        }
    }
    return 0;
}