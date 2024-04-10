#include<stdio.h>
#include<string.h>

int N, L;
char S[105], R[105];
bool A[200];

int main(){
 scanf("%s",S+1); N = strlen(S+1);
 A['a']=A['e']=A['i']=A['o']=A['u']=A['y']=1;
 for(int i=1; i<=N; i++){
  if(S[i]<='Z') S[i]+='a'-'A';
  if(!A[S[i]]) R[++L] = S[i];
 }
 for(int i=1; i<=L; i++) printf(".%c",R[i]);
}