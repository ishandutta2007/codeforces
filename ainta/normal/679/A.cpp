#include<stdio.h>
int d[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
int res[20], c;
int main(){
    int i;
    char p[5];
    for(i=0;i<19;i++){
        printf("%d\n",d[i]);
        fflush(stdout);
        scanf("%s",p);
        if(p[0]=='y')res[i] = 1;
        else res[i] = 0;
    }
    if(res[15]||res[16]||res[17]||res[18]){
        printf("composite\n");
        fflush(stdout);
        return 0;
    }
    for(i=0;i<19;i++){
        c += res[i];
    }
    if(c<=1){
        printf("prime\n");
        fflush(stdout);
        return 0;
    }
    else{
        printf("composite\n");
        fflush(stdout);
        return 0;
    }
}