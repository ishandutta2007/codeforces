#include<stdio.h>
#include<string.h>
 
char D[205]; int N;
int C;
bool Chk[205];
 
int main(){
 scanf("%s",D+1);
 for(int i=0; D[++i]; ){
  if(!Chk[D[i]]) ++C; Chk[D[i]] = 1;
 }
 puts(C&1 ? "IGNORE HIM!" : "CHAT WITH HER!");
}