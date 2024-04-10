// KALAM
# include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 77 , ALPHA = 26;
char S[N * N] , A[N][N];
int T[ALPHA];
int n , l , k , m;
int main() {
   scanf("%d %d %d" , & n , & l , & k);
   scanf("%s" , S + 1);
   m = n * l;
   for(int i = 1;i <= m;++ i)
      ++ T[S[i] - 'a'];
   int rem = k;
   for(int i = 1;i <= l;++ i) {
      int sum = 0;
      for(int j = 0;j < ALPHA;++ j) {
         sum += T[j];
         if(sum >= rem) {
            int f = 0;
            int x = rem;
            int cnt = k - rem + 1;
            while(x --) {
               while(T[f] == 0)
                  ++ f;
               if(f < j) -- rem;
               A[cnt][i] = 'a' + f;
               ++ cnt;
               -- T[f];
            }
            break ;
         }
      }
   }

   vector < string > V;
   for(int i = 1;i <= n;++ i) {
      string ss;
      for(int j = 1;j <= l;++ j) {
         if(A[i][j] < 'a' || A[i][j] > 'z') {
            for(int c = 0;c < ALPHA;++ c) {
               if(T[c] > 0) {
                  -- T[c];
                  A[i][j] = c + 'a';

                  break ;
               }
            }
         }
         ss += A[i][j];
      }
      V.push_back(ss);
   }
   sort(V.begin() , V.end());
   for(int i = 0;i < n;++ i)
      cout << V[i] << endl;


   return 0;
}