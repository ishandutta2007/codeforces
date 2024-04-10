#include<cstdio>
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<=5){
            for(int i=0;i<n;i++)
                putchar('a'+i);
            puts("");
        }
        else{
            int x=n/2-1;
            for(int i=0;i<x+1;i++)
                putchar('a');
            putchar('b');
            for(int i=0;i<x;i++)
                putchar('a');
            if(n&1) putchar('c');
            puts("");
        }
    }
    return 0;
}