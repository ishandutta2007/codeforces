#include <cstdio>
#include <algorithm>
using namespace std;
char s[200101];
char ans[200101];
char curr[2];
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        scanf("%s",s);
        int aaaa = 0;
        for(int d=0;d<10;d++){
            int flag = 1;
            curr[0]='0';
            curr[1]='0'+d;
            for(int i=0;i<n;i++){
                if(curr[0]<=s[i] && s[i]<('0'+d)){
                    ans[i]='1';
                    curr[0]=s[i];
                }
                else if(s[i]>('0'+d)){
                    if(s[i]<curr[1]){
                        flag = 0;
                        break;
                    }
                    else{
                        ans[i]='2';
                        curr[1]=s[i];
                    }
                }
                else if(curr[0]>s[i] && s[i]<('0'+d)){
                    flag = 0;
                    break;
                }
                else{ // s[i]==('0'+d)
                    if(curr[1]==('0'+d)){
                        ans[i]='2';
                    }
                    else{
                        ans[i]='1';
                        curr[0]=s[i];
                    }
                }
            }
            if(flag==1){
                ans[n]='\0';
                printf("%s\n",ans);
                aaaa=1;
                break;
            }
        }
        if(aaaa==0){
            printf("-\n");
        }
    }
}