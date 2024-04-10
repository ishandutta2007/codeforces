#include<stdio.h>

int n;
int A[105],AN,cnt;

int main(){
    int i, j = 1;
    
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        int d; scanf("%d",&d);
        if(d < 0) ++cnt;
        if(cnt == 3){
            A[++AN] = i - j;
            j = i;
            cnt = 1;
        }
    }
    A[++AN] = n + 1 - j;
    printf("%d\n",AN);
    for(i = 1; i <= AN; i++) printf("%d ",A[i]);
}