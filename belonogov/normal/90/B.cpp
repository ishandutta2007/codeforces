#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int i, j, n, m, i1, j1;
    int z[100][100];
    cin >> n >> m;
    char a[100][100];
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
      {
          cin >> a[i][j];
          z[i][j] = 0;
      }
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
      {
         for(i1 = 0; i1 < i; i1++)
            if (a[i1][j] == a[i][j])
            {
                z[i1][j] = 1;
                z[i][j] = 1;
            }
         for(j1 = 0; j1 < j; j1++)
            if (a[i][j1] == a[i][j])
            {
                z[i][j1] = 1;
                z[i][j] = 1;
            }

        }
   for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        if(z[i][j] == 0) cout << a[i][j];


    return 0;
}