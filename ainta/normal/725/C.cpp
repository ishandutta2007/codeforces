#include<stdio.h>
char p[30], res[3][30];
int C[26], pp2;
void Do(int pv, int x, int y){
    if(res[x][y])return;
    if(pp2==pv){
        Do((pv+1)%27,x,y);
        return;
    }
    res[x][y] = p[pv];
    if(x==0){
        y--;
        if(y<0){
            y=0;
            x++;
        }
        Do((pv+1)%27,x,y);
    }
    else{
        y++;
        if(y==13){
            y--;
            x--;
        }
        Do((pv+1)%27,x,y);
    }
}
int main(){
    int i, pv, p1 = -1, p2, t;
    scanf("%s",p);
    for(i=0;i<27;i++){
        C[p[i]-'A']++;
    }
    for(i=0;i<26;i++){
        if(C[i]==2)break;
    }
    pv = i;
    for(i=0;i<27;i++){
        if(p[i]-'A' == pv){
            if(p1 == -1)p1 = i;
            else p2 = i;
        }
    }
    if(p2-p1 == 1){
        printf("Impossible\n");
        return 0;
    }
    t = (p2 - p1 - 1)/2;
    pp2 = p2;
    Do(p1, 0, t);
    for(i=0;i<2;i++){
        printf("%s\n",res[i]);
    }
}