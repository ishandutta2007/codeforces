#include<stdio.h>

int main(){
  long long k, s, e, m;
  int n, i;
  char str[1000006];
  scanf("%d %lld", &n, &k);
  s = 1;
  e = n;
  if((e*(e-1))/2 < k){
    printf("Impossible\n");
    return 0;
  }
  while(s < e){
    m= (s + e)/2;
    if((m*(m - 1))/2 < k){
      s = m + 1;
    }
    else{
      e = m;
    }
  }

  e = (s*(s-1)/2)-k;

  for(i = 0;i < s - 1;i++){
    str[i] = '(';
  }
  for(;e > 0;e--){
    str[i++] = ')';
  }
  str[i++] = '(';
  str[i++] = ')';
  for(;i < 2*s;i++){
    str[i] = ')';
  }
  while(i < 2*n){
    str[i++] = '(';
    str[i++] = ')';
  }
  str[i] = '\0';
  printf("%s\n", str);
  
  return 0;
}