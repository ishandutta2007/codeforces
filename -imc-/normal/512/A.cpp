#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

char w[105][105];

vector<int> edgesTo[100];
vector<char> visited, visiting;

string answer;

void topsort(int x)
{
    if (visiting[x])
    {
        printf("Impossible\n");
        exit(0);
    }
    
    visiting[x] = true;
        
    for (int u: edgesTo[x])
        if (!visited[u])
            topsort(u);
    
    answer += 'a' + x;
    
    visiting[x] = false;
    visited[x] = true;
}

int main()
{
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%s", w[i]);
    
    for (int i = 0; i < n - 1; i++)
    {
        int lcp = 0;
        while (w[i][lcp] && w[i + 1][lcp] && w[i][lcp] == w[i + 1][lcp]) lcp++;
        
        if (w[i][lcp] && !w[i + 1][lcp])
        {
            printf("Impossible\n");
            exit(0);
        }
        
        if (w[i][lcp] && w[i + 1][lcp])
        {
            edgesTo[w[i + 1][lcp] - 'a'].push_back(w[i][lcp] - 'a');
        }
    }
    
    visited.assign('z' - 'a' + 1, false);
    visiting.assign('z' - 'a' + 1, false);
    
    for (int i = 0; i < 'z' - 'a' + 1; i++)
        if (!visited[i])
            topsort(i);
        
    printf("%s\n", answer.c_str());
        
    return 0;
}