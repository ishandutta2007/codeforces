#include<stdio.h>
char p[20];
long long n, t;
char ck;
int main(){
    int i;
    scanf("%s",p);
    for(i=0;p[i];i++);
    ck = p[i-1];
    p[i-1] = 0;
    for(i=0;p[i];i++){
        n=n*10+p[i]-'0';
    }
    t = ((n-1)/4*2 + (1 - n%2)) * 6;
    if(n%4 == 1 || n%4 == 2){
        t += (n-1);
    }
    else{
        t += (n-3);
    }
    if(ck=='f')t++;
    if(ck=='e')t+=2;
    if(ck=='d')t+=3;
    if(ck=='a')t+=4;
    if(ck=='b')t+=5;
    if(ck=='c')t+=6;
    printf("%lld\n",t);
}