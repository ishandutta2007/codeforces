#include <stdio.h>
int min(int a, int b){
                         if(a < b)return a; 
                         return b;
}
int main() {
   int t, n;
   scanf("%d",&n);
   int a1 = 0, a2 = 0;
   while(n--) {
        int a;
      scanf("%d",&a);
      if(a % 2 == 0)a2++;else a1++;
   }
   int ans = 0;
   int k = min(a1,a2);
   ans = k + (a1 - k) / 3;
   printf("%d\n", ans);
}