#include <iostream>

int main()
{
    int N, M;
    std::cin >> N >> M;
    
    bool a[N][M], b[N][M];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            std::cin >> a[i][j];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            std::cin >> b[i][j];
    
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < M - 1; j++)
        {
            if(a[i][j] != b[i][j])
            {
                for(int l = 0; l < 2; l++)
                    for(int r = 0; r < 2; r++)
                        a[i+l][j+r] = !a[i+l][j+r];
            }
        }
    }
    
    bool poss = true;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(a[i][j] != b[i][j])
                poss = false;
                
    if(poss)
        std::cout << "Yes";
    else
        std::cout << "No";
    
    return 0;
}