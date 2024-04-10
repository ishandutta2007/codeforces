#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool trigger[105][105];

int main()
{   
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            scanf(" %c", &c);
            if (c == '1')
                trigger[i][j] = true;
        }
    }
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int nInvites = 0;
    
    vector<char> invite(n);
    for (int t = 0; t < n; t++)
    {
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
            {
                for (int j = 0; j < n; j++)
                    if (trigger[i][j])
                        a[j]--;
                invite[i] = true;
                nInvites++;
            }
    }
    
    printf("%d\n", nInvites);
    for (int i = 0; i < n; i++)
        if (invite[i])
            printf("%d ", i + 1);
    printf("\n");
    
    return 0;
}