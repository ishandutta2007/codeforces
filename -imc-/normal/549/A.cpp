#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char m[55][55];

int main()
{   
    int w, h;
    scanf("%d %d", &h, &w);
    
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            scanf(" %c", &m[x][y]);
        
    int answer = 0;
    
    for (int y = 0; y < h - 1; y++)
        for (int x = 0; x < w - 1; x++)
        {
            string s = "";
            s += m[x][y];
            s += m[x + 1][y];
            s += m[x][y + 1];
            s += m[x + 1][y + 1];
            sort(s.begin(), s.end());
            if (s == "acef")
                answer++;
        }
        
    printf("%d\n", answer);
        
    return 0;
}