#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{   
    int n;
    scanf("%d", &n);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i] -= (n - i - 1);
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
        {
            printf(":(\n");
            return 0;
        }
        
    vector<int> answer(n);
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] = a[i] + (n - i - 1);
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);
    printf("\n");
    
    return 0;
}