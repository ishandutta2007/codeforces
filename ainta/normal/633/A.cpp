#include<stdio.h>
int a, b, c;
int main(){
    int i;
    scanf("%d%d%d",&a,&b,&c);
    for(i=0;i*a<=c;i++){
        if((c-i*a)%b==0){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}