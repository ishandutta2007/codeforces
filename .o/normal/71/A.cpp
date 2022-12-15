#include<stdio.h>
#include<string.h>

int TC;
char S[105]; int len;

int main(){
 scanf("%d",&TC); while(TC--){
  scanf("%s",S+1); len = strlen(S+1);
  if(len <= 10) puts(S+1);
  else printf("%c%d%c\n",S[1],len-2,S[len]);
 }
}