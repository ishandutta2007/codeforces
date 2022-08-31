#include<stdio.h>
int get(int C){
    int i;
    for(i=0;i*(i-1)/2 <= 1e9;i++){
        if(i*(i-1)/2 == C)return i;
    }
    return -1;
}
bool Pos(int A, int B, int C2, int C3){
    if(A==0 && B==0)return false;
    if(C2+C3 != A*B)return false;
    int i;
    if(A==0){
        for(i=0;i<B;i++)printf("1");
        return true;
    }
    if(B==0){
        for(i=0;i<A;i++)printf("0");
        return true;
    }
    for(i=0;i<C3/A;i++)printf("1");
    int t = C3%A;
    for(i=0;i<A-t;i++)printf("0");
    if(C3/A != B)printf("1");
    for(i=0;i<t;i++)printf("0");
    for(i=0;i<B-C3/A-1;i++)printf("1");
    return true;
}
bool Do2(int A, int C4, int C2, int C3){
    int i;
    for(i=0;i*(i-1)/2 <= 1e9;i++){
        if(i*(i-1)/2 == C4){
            if(Pos(A, i, C2, C3))return true;
        }
    }
    return false;
}
bool Do(int C1, int C4, int C2, int C3){
    int i;
    for(i=0;i*(i-1)/2 <= 1e9;i++){
        if(i*(i-1)/2 == C1){
            if(Do2(i, C4,C2,C3))return true;
        }
    }
    return false;
}
int main(){
    int C1, C2, C3, C4;
    scanf("%d%d%d%d",&C1,&C2,&C3,&C4);
    if(!Do(C1,C4,C2,C3))printf("Impossible\n");
}