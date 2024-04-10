#include <stdio.h>
#include <algorithm>

const int N_ = 305;
int N, D[N_];

int main(){
 int i, j;
 scanf("%d", &N);
 for(i = 1; i <= N; i++) scanf("%d", D+i);

 for(i = 1; i <= N; i++) {
   if(i > 1) printf("R");
   while(D[i]--) printf((i==1) ? "PRL" : "PLR");
 }
 return 0;
}//PRLRPLRPLR