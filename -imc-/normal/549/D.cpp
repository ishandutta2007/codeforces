#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int m[105][105], a[105][105];

int main()
{   
    int w, h;
    scanf("%d %d", &h, &w);
    
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            char c;
            scanf(" %c", &c);
            m[x][y] = c == 'W' ? 1 : -1;
        }
    
    int answer = 0;
    for (int x = w - 1; x >= 0; x--)
        for (int y = h - 1; y >= 0; y--)
        {
            a[x][y] = m[x][y] - m[x + 1][y] - m[x][y + 1] + m[x + 1][y + 1];
            if (a[x][y] != 0)
                answer++;
        }
        
    /*for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
            printf("%d ", a[x][y]);
        printf("\n");
    }*/
    
    printf("%d\n", answer);
        
    return 0;
}