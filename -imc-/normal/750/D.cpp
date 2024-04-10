#include <bits/stdc++.h>

using namespace std;

const int maxSize = 320;

typedef unsigned char bufarray[maxSize][maxSize];

unsigned char buffer[2][maxSize][maxSize];
unsigned char used[maxSize][maxSize];

const int dx[] = { 0, 1, 1 , 1,  0, -1, -1, -1 };
const int dy[] = { 1, 1, 0, -1, -1, -1,  0,  1 };

void move(bufarray& from, bufarray& to)
{
    for (int x = 1; x < maxSize - 1; x++)
        for (int y = 1; y < maxSize - 1; y++)
            if (from[x][y])
            {
                used[x][y] = true;
                for (int dir = 0; dir < 8; dir++)
                    if (from[x][y] & (1 << dir))
                        to[x + dx[dir]][y + dy[dir]] |= (1 << dir);
            }
}

void populate(bufarray& from, bufarray& to)
{
    for (int x = 1; x < maxSize - 1; x++)
        for (int y = 1; y < maxSize - 1; y++)
            if (from[x][y])
            {
                used[x][y] = true;
                for (int dir = 0; dir < 8; dir++)
                    if (from[x][y] & (1 << dir))
                    {
                        int pDir = (dir + 7) % 8;
                        int nDir = (dir + 1) % 8;
                        
                        to[x][y] |= (1 << pDir);
                        to[x][y] |= (1 << nDir);
                    }
            }
}

void print(bufarray& arr)
{
    for (int y = 5; y >= -5; y--)
    {
        for (int x = -5; x <= 5; x++)
            printf("%c", arr[maxSize / 2 + x][maxSize / 2 + y] ? '#' : '.');
        printf("\n");
    }
    printf("\n");
}

int main()
{
    buffer[0][maxSize / 2][maxSize / 2] = 1;
    //print(buffer[0]);
    
    int n;
    cin >> n;
    
    int t = 0;
    
    for (int i = 0; i < n; i++)
    {
        int nSteps;
        cin >> nSteps;
        
        for (int j = 0; j < nSteps; j++)
        {   
            memset(buffer[(t + 1) % 2], 0, sizeof(buffer[0]));
            move(buffer[t % 2], buffer[(t + 1) % 2]);
            if (i == 0 && j == 0)
                used[maxSize / 2][maxSize / 2] = false;
            t++;
            //print(buffer[t % 2]);
        }
        
        memset(buffer[(t + 1) % 2], 0, sizeof(buffer[0]));
        populate(buffer[t % 2], buffer[(t + 1) % 2]);
        t++;
    }
    
    int answer = 0;
    for (int x = 0; x < maxSize; x++)
        for (int y = 0; y < maxSize; y++)
            if (used[x][y])
                answer++;
            
#if 0
    for (int y = 20; y >= 0; y--)
    {
        for (int x = -30; x <= 30; x++)
            printf("%c", used[maxSize / 2 + x][maxSize / 2 + y] ? '#' : '.');
        printf("\n");
    }
    printf("\n");
#endif
    
    cout << answer << endl;
            
    return 0;
}