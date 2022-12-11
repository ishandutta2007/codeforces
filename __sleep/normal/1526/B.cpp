#include<cstdio>
int t,x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&x);
        if(x>1099) {puts("YES"); continue;}
        int flag=0;
        for(int i=0;i*11<=x;i++)
            if((x-i*11)%111==0) flag=1;
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}