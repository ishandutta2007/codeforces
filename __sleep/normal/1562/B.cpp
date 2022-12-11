#include<cstdio>
const int N=100005;
int t,k,isp[N];
char s[55];
void ini(){
    for(int i=2;i<N;i++)
        if(!isp[i])
            for(int j=2;i*j<N;j++)
                isp[i*j]=1;
}
int main(){
    ini();
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&k,s);
        if(k==1){
            puts("1");
            putchar(s[0]);
            putchar('\n');
            continue;
        }
        int flag=0;
        for(int i=0;i<k;i++){
            if(s[i]=='1'||isp[s[i]-'0']){
                puts("1");
                putchar(s[i]);
                puts("");
                flag=1;
                break;
            }
        }
        if(flag) continue;
        
        printf("%d\n",2);
        flag=1;
        for(int i=0;i<k&&flag;i++){
            for(int j=i+1;j<k&&flag;j++){
                if(isp[(s[i]-'0')*10+s[j]-'0']){
                    putchar(s[i]);
                    putchar(s[j]);
                    puts("");
                    flag=0;
                    break;
                }
            }
        }
    }
    return 0;
}