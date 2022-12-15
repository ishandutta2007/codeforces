#include<stdio.h>
#include<math.h>
double a,b,k;
 
int main(){
 scanf("%lf%lf%lf",&a,&b,&k);
 printf("%.0lf\n",ceil(a/k)*ceil(b/k));
 return 0;
}