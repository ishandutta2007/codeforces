#include<stdio.h>

int n,a[100500],t[100500];

int main() {
 scanf("%d", &n);
 for(int i = 1; i <= n; i++) scanf("%d", a+i);

 int mx = 1;
 for(int i = n; i > 0; i--) {
  t[a[i]] = t[a[i] + 1] + 1;
  if(mx < t[a[i]]) mx = t[a[i]];
 }
 printf("%d\n", n - mx);
}