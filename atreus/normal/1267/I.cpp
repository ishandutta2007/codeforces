// KALAM
# include <bits/stdc++.h>

using namespace std;

const int N = 200 + 77;
int n;
int F[N][N];
inline bool Ask(int x , int y) {
   if(F[x][y] > 0) return F[x][y] - 1;
   cout << "? " << x << ' ' << y << endl;
   char c;
   cin >> c;
   F[x][y] = (c == '<') + 1;
   return F[x][y] - 1;
}
inline void Test() {
   cin >> n;
   for(int i = 0;i <= n * 2;++ i) for(int j = 0;j <= n * 2;++ j) F[i][j] = 0;
   vector < int > I , O;
   for(int i = 1;i <= n + n;i += 2) {
      int x = i , y = i + 1;
      if(Ask(x , y))
         I.push_back(x) , O.push_back(y);
      else
         I.push_back(y) , O.push_back(x);
   }
   for(int i = 0;i < n;++ i)
      for(int j = i + 1;j < n;++ j)
         if(Ask(I[j] , I[i]))
            swap(I[i] , I[j]) , swap(O[i] , O[j]);
   bool good = 0;
   for(int i = 0;i < n - 1;++ i) {
      int ted = (n - i - 1) * 2;
      for(int j = 0;j <= i;++ j)
         if(Ask(I[i] , O[j]))
            ++ ted;
      if(ted < n) {
         for(int j = 0;j < i;++ j)
            for(int k = j + 1;k < i;++ k)
               Ask(O[j] , O[k]);
         good = 1;
         cout << "!" << endl;
         break ;
      }
   }
   if(good) return ;
   for(int j = 0;j < n - 1;++ j)
      for(int k = j + 1;k < n - 1;++ k)
         if(Ask(O[k] , O[j]))
            swap(O[k] , O[j]);
   Ask(I[n - 1] , O[0]);
   cout << "!" << endl;
}
int main() {

   int T;
   cin >> T;
   while(T --)
      Test();
   return 0;
}