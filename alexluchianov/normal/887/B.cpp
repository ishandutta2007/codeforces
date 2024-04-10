#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 3;
int const valmax = 1000;

int v[1 + nmax][6];
int frec[3][1 + valmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    for(int j = 0; j < 6; j++)
      std::cin >> v[i][j];
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < 6; j++)
      frec[1][v[i][j]] = 1;
  
  for(int i = 1;i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(i != j)
        for(int h = 0; h < 6; h++)
          for(int h2 = 0; h2 < 6; h2++)
            frec[2][v[i][h] * 10 + v[j][h2]] = 1;
   
   for(int i = 1; i <= n; i++)
     for(int j = 1;j <= n; j++)
       if(i != j)
         for(int k = 1; k <= n; k++)
           if(i != k && j != k)
             for(int h = 0; h < 6; h++)
               for(int h2 = 0; h2 < 6; h2++)
                 for(int h3 = 0; h3 < 6; h3++)
                   frec[3][v[i][h] * 100 + v[j][h2] * 10 + v[k][h3]];
  int result = 0;
  while(true) {
    if(result < 9 && frec[1][result + 1] == 1)
      result++;
    else if(9 <= result && result < 99 && frec[2][result + 1] == 1)
      result++;
    else if(99 <= result && result < 999 && frec[3][result + 1] == 1)
      result++;
    else
      break;
  }
  std::cout << result;
  return 0;
}