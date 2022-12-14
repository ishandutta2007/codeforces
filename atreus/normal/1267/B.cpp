// KALAM
# include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 77;
char S[N];
int a[N];
char SS[N];
int n , cur = 1;
int main() {
   scanf("%s" , S + 1);
   n = strlen(S + 1);
   char now = S[1];
   int td = 1;
   for(int i = 2;i <= n;++ i) {
      if(S[i] != now)
         a[cur] = td , SS[cur] = now , td = 0 , now = S[i] , ++ cur;
      ++ td;
   }
   a[cur] = td;
   SS[cur] = now;
   n = cur;
   if(n % 2 == 0) return ! printf("0\n");
   int md = ((n + 1) / 2);
   if(a[md] < 2) return ! printf("0\n");
   int f = md - 1;
   for(int i = md + 1;i <= n;++ i) {
      if(SS[i] != SS[f]) return ! printf("0\n");
      if(a[i] + a[f] < 3) return ! printf("0\n");
      -- f;
   }
   printf("%d\n" , a[md] + 1);

   return 0;
}