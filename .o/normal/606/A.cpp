#include<stdio.h>

int a[3],b[3];
int main(){
 for(int i=0;i<3;i++)scanf("%d",a+i);
 for(int i=0;i<3;i++)scanf("%d",b+i);

 for(int i=0;i<3;i++){
  for(int j=0;j<3;j++) while(a[i] < b[i] && a[j] - 2 >=b[j]) a[j] -= 2, a[i]++;
 }

 for(int i=0;i<3;i++){
  if(a[i] < b[i]) return 0 & puts("No");
 }
puts("Yes");

 return 0;
}