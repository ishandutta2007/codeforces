#include <cstdio>

char ch[101][101];
int n, m;
const char color[3] = {'C', 'M', 'Y'};

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %c", &ch[i][j]);
    
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(ch[i][j] == color[k])
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    
    if(flag) printf("#Color\n");
    else printf("#Black&White\n");
    
    return 0;
}