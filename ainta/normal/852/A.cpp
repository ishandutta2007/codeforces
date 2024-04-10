#include<cstdio>
#include<algorithm>
using namespace std;
int n, S, chk[201000];
char p[201000];
int Calc(int a){
    if(a==0)return 0;
    return a%10 + Calc(a/10);
}
bool Pos(int a){
   /* int w[10] = {0};
    while(a){
        
    }*/
    if(Calc(Calc(a)) >9){
        return false;
    }
    return true;
}
void Print(int a){
    int w[10],c=0;
    while(a){
        w[c++]=a%10;
        a/=10;
    }
    int i;
    for(i=c-1;i>=0;i--){
        printf("%d",w[i]);
        if(i)printf("+");
    }
    printf("\n");
}
int main(){
    int i;
    scanf("%d",&n);
    scanf("%s",p);
    for(i=0;p[i];i++) S += p[i]-'0';
    int SS = S;
    for(i=0;i+1<n;i+=2){
        if(Pos(S))break;
        S += (p[i]-'0')*9;
        chk[i] = 1;
    }
    if(!Pos(S)){
        S = SS;
        for(i=0;i<n;i++)chk[i]=0;
    
        for(i=1;i+1<n;i+=2){
            if(Pos(S))break;
            S += (p[i]-'0')*9;
            chk[i] = 1;
        }
        if(!Pos(S)){
            while(1){}
        }
    }
    
    
    for(i=0;i<n;i++){
        printf("%d",p[i]-'0');
        if(i==n-1||chk[i])continue;
        printf("+");
    }
    printf("\n");
    Print(S);
    S=Calc(S);
    Print(S);
}