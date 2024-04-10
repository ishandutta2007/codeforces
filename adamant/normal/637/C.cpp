#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<string> code(n);
    for (int i = 0; i < n; i++)
        cin >> code[i];
    
    int minDiff = 6;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int nDiff = 0;
            for (int k = 0; k < 6; k++)
                if (code[i][k] != code[j][k])
                    nDiff++;
                
            minDiff = min(minDiff, nDiff);
        }
        
    // 0, 1, 2 differences -> k=0
    // 3, 4 -> k=1
    // 5, 6 -> k=2
    
    if (n == 1)
        printf("6\n");
    else
        printf("%d\n", (minDiff - 1) / 2);
    
    return 0;
}